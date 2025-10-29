#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string ciphertext = 
        "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE "
        "NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE "
        "IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS "
        "WFCS ZRDM PAUI S";

    vector<string> possibleKeys = {
        "utter", "descriptive", "caring", "pies", "drawer", "station", "soothe", "year",
        "agreeable", "seemly", "button", "encourage", "reduce", "bed", "wave", "nosy",
        "zoo", "hateful", "flaky", "work", "ear", "uneven", "cumbersome", "languid",
        "box", "devilish", "yawn", "ablaze", "lake", "harbor", "legs", "glow",
        "glossy", "cruel", "warn", "hard", "unique", "card", "hug", "tangible",
        "hook", "label", "exotic", "account", "imagine", "grain", "tranquil", "book",
        "pickle", "whistle", "sack", "scissors", "trashy", "puzzled", "bottle", "smile",
        "neighborly", "eatable", "admit", "picayune", "type", "fast", "shy", "anger",
        "open", "add", "curly", "free", "aftermath", "cherry", "daily", "heal",
        "rose", "abhorrent", "short", "fine", "guarded", "vase", "fascinated", "fresh",
        "chickens", "mine", "stare"
    };

    // PREPROCESS TEXT - remove spaces
    string processedCiphertext;
    int i;
    int j;
    
    // first loop through ALL the char in string
    for (i = 0; i < ciphertext.size(); i++) {
        if (ciphertext.at(i) != ' ') {
            processedCiphertext += ciphertext.at(i);
        }
    }

    // FREQUENCY ANALYSIS
    vector<char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<int> letterCounts(letters.size(), 0);
    
    // first loop through ALL the char in string
    for (i = 0; i < processedCiphertext.size(); i++) {
        // loop through letters vector
        for (j = 0; j < letters.size(); j++) {
            if (processedCiphertext.at(i) == letters.at(j)) {
                // WE KNOW IT'S THE LETTER
                letterCounts.at(j)++;
                // PARALLEL VECTORS
            }
        }
    }

    cout << "Frequency Analysis of Encrypted Text:" << endl;
    cout << "=====================================" << endl;
    
    for (i = 0; i < letters.size(); i++) {
        cout << letters.at(i) << ": " << letterCounts.at(i) << endl;
    }
    cout << endl;

    // DECRYPTION WITH KEY TESTING
    string bestPlaintext;
    string bestKey;
    int bestScore = -1000000;

    int k;
    
    // loop through ALL possible keys
    for (k = 0; k < possibleKeys.size(); k++) {
        string currentKey = possibleKeys.at(k);
        string decrypted;
        
        // first loop through ALL the char in string
        for (i = 0; i < processedCiphertext.size(); i++) {
            char cipherChar = processedCiphertext.at(i);
            char keyChar = currentKey.at(i % currentKey.size());
            
            int cipherNum = cipherChar - 'A';
            int keyNum = keyChar - 'a';
            int plainNum = (cipherNum - keyNum + 26) % 26;
            char plainChar = 'A' + plainNum;
            decrypted += plainChar;
        }

        // SCORE THE DECRYPTION - count common English letters
        int score = 0;
        
        // first loop through ALL the char in string
        for (i = 0; i < decrypted.size(); i++) {
            char c = decrypted.at(i);
            if (c == 'E' || c == 'T' || c == 'A' || c == 'O' || c == 'I' || c == 'N') {
                score += 10;
            }
            if (c == 'S' || c == 'H' || c == 'R' || c == 'D' || c == 'L' || c == 'U') {
                score += 5;
            }
            if (c == ' ' || c == '.' || c == ',') {
                score -= 100;
            }
        }

        if (score > bestScore) {
            bestScore = score;
            bestKey = currentKey;
            bestPlaintext = decrypted;
        }
    }

    // OUTPUT RESULTS
    cout << "Decrypted English Plaintext:" << endl;
    cout << "============================" << endl;
    
    string formattedPlaintext;
    int charCount = 0;
    // first loop through ALL the char in string
    for (i = 0; i < bestPlaintext.size(); i++) {
        formattedPlaintext += bestPlaintext.at(i);
        charCount++;
        if (charCount % 5 == 0) {
            formattedPlaintext += ' ';
        }
    }
    cout << formattedPlaintext << endl << endl;

    cout << "Discovered Key: " << bestKey << endl;
    cout << "=================" << endl;

    return 0;
}