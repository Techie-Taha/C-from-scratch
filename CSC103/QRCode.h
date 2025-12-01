#ifndef QR_CODE_H
#define QR_CODE_H

#include <string>
#include <vector>

class QRCode {
private:
    std::vector<std::string> grid;
    std::vector<std::string> signature;

public:
    QRCode();

    std::vector<std::string> stringToBinary(const std::string& msg);
    std::string binaryToString(const std::vector<std::string>& binary);
    std::string computeChecksum(const std::string& msg);
    bool verifyChecksum(const std::string& msg, const std::string& checksum);

    void insertSignature();
    void encodeMessage(const std::string& msg);
    std::string decodeGrid(const std::vector<std::string>& inputGrid);

    void displayGrid() const;
    void saveToFile(const std::string& filename) const;

    std::vector<std::string> getGrid() const { return grid; }
};

#endif
