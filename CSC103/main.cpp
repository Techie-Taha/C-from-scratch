#include <iostream>
#include <vector>
#include <string>
#include "QRCode.h"

int main() {
    QRCode qr;
    int option;

    std::cout << "QR Generator & Decoder\n";
    std::cout << "Unique signature = binary for 'SIGN'.\n";
    std::cout << "This signature is placed in the first 4 rows and ignored during decoding.\n\n";

    std::cout << "1. Encode message\n";
    std::cout << "2. Decode from input\n";
    std::cout << "Choose: ";
    std::cin >> option;

    std::cin.ignore();

    if (option == 1) {
        std::string msg;
        std::cout << "Enter message: ";
        std::getline(std::cin, msg);

        qr.encodeMessage(msg);

        std::cout << "\nEncoded QR Grid:\n";
        qr.displayGrid();

        std::cout << "\nChecksum: " << qr.computeChecksum(msg) << "\n";

        std::cout << "\nSave to file? (y/n): ";
        char c;
        std::cin >> c;

        if (c == 'y') {
            qr.saveToFile("qr_output.txt");
            std::cout << "Saved as qr_output.txt\n";
        }
    }

    else if (option == 2) {
        std::cout << "Enter grid lines (type 'end' to finish):\n";
        std::vector<std::string> lines;
        std::string temp;
        while (true) {
            std::getline(std::cin, temp);
            if (temp == "end") break;
            lines.push_back(temp);
        }

        std::string result = qr.decodeGrid(lines);
        std::cout << "\nDecoded message: " << result << "\n";
    }

    return 0;
}