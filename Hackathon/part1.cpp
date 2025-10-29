#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // The encrypted message with spaces every 4 letters
    string ciphertext = "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS WFCS ZRDM PAUI S";
    
    // All possible decryption keys to test
    vector<string> possibleKeys = {"utter","descriptive","caring","pies","drawer","station","soothe","year","agreeable","seemly","button","encourage","reduce","bed","wave","nosy","zoo","hateful","flaky","work","ear","uneven","cumbersome","languid","box","devilish","yawn","ablaze","lake","harbor","legs","glow","glossy","cruel","warn","hard","unique","card","hug","tangible","hook","label","exotic","account","imagine","grain","tranquil","book","pickle","whistle","sack","scissors","trashy","puzzled","bottle","smile","neighborly","eatable","admit","picayune","type","fast","shy","anger","open","add","curly","free","aftermath","cherry","daily","heal","rose","abhorrent","short","fine","guarded","vase","fascinated","fresh","chickens","mine","stare"};

    // Remove spaces from ciphertext
    string processedCiphertext;
    for (int i = 0; i < ciphertext.size(); i++) {
        if (ciphertext.at(i) != ' ') {
            processedCiphertext += ciphertext.at(i);
        }
    }

    // Count frequency of each letter in encrypted text
    vector<int> frequency(26, 0);
    for (int i = 0; i < processedCiphertext.size(); i++) {
        char letter = processedCiphertext.at(i);
        frequency.at(letter - 'A')++;
    }

    // Display frequency analysis
    cout << "Frequency Analysis of Encrypted Text:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ": " << frequency.at(i) << endl;
    }
    cout << endl;

    // Variables to track best decryption results
    string bestPlaintext, bestKey;
    int bestScore = 0;
    bool isFirstKey = true;

    // Try every possible key
    for (int k = 0; k < possibleKeys.size(); k++) {
        string currentKey = possibleKeys.at(k);
        string decryptedText;
        
        // Decrypt the entire message with current key
        for (int i = 0; i < processedCiphertext.size(); i++) {
            char cipherChar = processedCiphertext.at(i);
            char keyChar = currentKey.at(i % currentKey.size());
            
            // Vigenère decryption formula
            int plainNum = (cipherChar - 'A' - (keyChar - 'a') + 26) % 26;
            decryptedText += 'A' + plainNum;
        }

        // Score the decrypted text based on English letter frequency
        int currentScore = 0;
        for (int i = 0; i < decryptedText.size(); i++) {
            char letter = decryptedText.at(i);
            if (letter == 'E' || letter == 'T' || letter == 'A' || 
                letter == 'O' || letter == 'I' || letter == 'N') {
                currentScore += 10;
            }
        }

        // Update best results if this is better (or first attempt)
        if (isFirstKey || currentScore > bestScore) {
            bestScore = currentScore;
            bestKey = currentKey;
            bestPlaintext = decryptedText;
            isFirstKey = false;
        }
    }

    // Display final results
    cout << "Decrypted English Plaintext:" << endl;
    cout << "============================" << endl;
    
    // Format plaintext with spaces for readability
    string formattedText;
    for (int i = 0; i < bestPlaintext.size(); i++) {
        formattedText += bestPlaintext.at(i);
        if ((i + 1) % 5 == 0) {
            formattedText += ' ';
        }
    }
    
    cout << formattedText << endl << endl;
    cout << "Discovered Key: " << bestKey << endl;
    cout << "=================" << endl;

    return 0;
}
