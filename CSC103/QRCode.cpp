#include "QRCode.h"
#include <iostream>
#include <fstream>

QRCode::QRCode() {
    // Signature = binary for "SIGN"
    signature = {
        "01010011", // S
        "01001001", // I
        "01000111", // G
        "01001110"  // N
    };
}

std::vector<std::string> QRCode::stringToBinary(const std::string& msg) {
    std::vector<std::string> result;
    for (char c : msg) {
        std::string bin = "";
        for (int i = 7; i >= 0; --i)
            bin += ((c >> i) & 1) ? '1' : '0';
        result.push_back(bin);
    }
    return result;
}

std::string QRCode::binaryToString(const std::vector<std::string>& binary) {
    std::string result = "";
    for (auto& b : binary) {
        char c = 0;
        for (int i = 0; i < 8; ++i)
            c |= (b[i] - '0') << (7 - i);
        result += c;
    }
    return result;
}

std::string QRCode::computeChecksum(const std::string& msg) {
    int sum = 0;
    for (char c : msg) sum += c;
    return stringToBinary(std::string(1, (char)(sum % 256)))[0];
}

bool QRCode::verifyChecksum(const std::string& msg, const std::string& checksum) {
    return computeChecksum(msg) == checksum;
}

void QRCode::insertSignature() {
    for (auto& row : signature)
        grid.push_back(row);
}

void QRCode::encodeMessage(const std::string& msg) {
    grid.clear();
    insertSignature();

    auto binMsg = stringToBinary(msg);
    for (auto& b : binMsg)
        grid.push_back(b);

    grid.push_back(computeChecksum(msg));
}

std::string QRCode::decodeGrid(const std::vector<std::string>& inputGrid) {
    std::vector<std::string> bin;

    for (int i = 4; i < inputGrid.size() - 1; i++)
        bin.push_back(inputGrid[i]);

    std::string msg = binaryToString(bin);

    std::string givenChecksum = inputGrid.back();

    if (!verifyChecksum(msg, givenChecksum))
        return "ERROR: checksum mismatch — data corrupted.";

    return msg;
}

void QRCode::displayGrid() const {
    for (auto& row : grid) {
        for (char bit : row)
            std::cout << (bit == '1' ? "█" : " ");
        std::cout << "\n";
    }
}

void QRCode::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (auto& row : grid)
        out << row << "\n";
    out.close();
}