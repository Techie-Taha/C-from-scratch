#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

// Function to preprocess text (remove spaces)
string preprocessText(const string& ciphertext) {
    string result;
    for (char c : ciphertext) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

// Function to perform frequency analysis
map<char, int> frequencyAnalysis(const string& text) {
    map<char, int> freq;
    // Initialize A-Z with 0 counts
    for (char c = 'A'; c <= 'Z'; c++) {
        freq[c] = 0;
    }
    
    for (char c : text) {
        if (isalpha(c)) {
            freq[toupper(c)]++;
        }
    }
    return freq;
}

// Function to decrypt Vigenère cipher
string decryptVigenere(const string& ciphertext, const string& key) {
    string plaintext;
    string processedText = preprocessText(ciphertext);
    
    for (size_t i = 0; i < processedText.size(); i++) {
        char cipherChar = toupper(processedText[i]);
        char keyChar = toupper(key[i % key.size()]);
        
        if (isalpha(cipherChar)) {
            // Convert to 0-25
            int cipherNum = cipherChar - 'A';
            int keyNum = keyChar - 'A';
            
            // Vigenère decryption formula
            int plainNum = (cipherNum - keyNum + 26) % 26;
            char plainChar = 'A' + plainNum;
            plaintext += plainChar;
        } else {
            plaintext += cipherChar;
        }
    }
    return plaintext;
}

// Function to read keys from file
vector<string> readKeysFromFile(const string& filename) {
    vector<string> keys;
    ifstream file(filename);
    string key;
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return keys;
    }
    
    while (getline(file, key)) {
        // Remove carriage return if present
        if (!key.empty() && key.back() == '\r') {
            key.pop_back();
        }
        if (!key.empty()) {
            keys.push_back(key);
        }
    }
    
    file.close();
    return keys;
}

// English letter frequencies (approximate percentages)
const map<char, double> ENGLISH_FREQ = {
    {'E', 12.70}, {'T', 9.06}, {'A', 8.17}, {'O', 7.51}, {'I', 6.97},
    {'N', 6.75}, {'S', 6.33}, {'H', 6.09}, {'R', 5.99}, {'D', 4.25},
    {'L', 4.03}, {'C', 2.78}, {'U', 2.76}, {'M', 2.41}, {'W', 2.36},
    {'F', 2.23}, {'G', 2.02}, {'Y', 1.97}, {'P', 1.93}, {'B', 1.29},
    {'V', 0.98}, {'K', 0.77}, {'J', 0.15}, {'X', 0.15}, {'Q', 0.10},
    {'Z', 0.07}
};

// Function to score text based on English frequency match
double scoreText(const string& text) {
    if (text.empty()) return 0.0;
    
    // Calculate actual frequencies
    map<char, int> actualFreq = frequencyAnalysis(text);
    int totalLetters = 0;
    
    // Count total letters
    for (const auto& pair : actualFreq) {
        totalLetters += pair.second;
    }
    
    if (totalLetters == 0) return 0.0;
    
    // Calculate chi-squared statistic (lower is better)
    double chiSquared = 0.0;
    
    for (char c = 'A'; c <= 'Z'; c++) {
        double expectedCount = ENGLISH_FREQ.at(c) * totalLetters / 100.0;
        double actualCount = actualFreq[c];
        
        if (expectedCount > 0) {
            double difference = actualCount - expectedCount;
            chiSquared += (difference * difference) / expectedCount;
        }
    }
    
    // Return negative chi-squared so higher score is better
    return -chiSquared;
}

// Function to print frequency analysis
void printFrequencyAnalysis(const map<char, int>& freq) {
    cout << "Frequency Analysis of Encrypted Text:" << endl;
    cout << "=====================================" << endl;
    
    int totalLetters = 0;
    for (const auto& pair : freq) {
        totalLetters += pair.second;
    }
    
    // Print in a nice formatted way
    for (char c = 'A'; c <= 'Z'; c++) {
        cout << c << ": " << freq.at(c) << " (" 
             << (freq.at(c) * 100.0 / totalLetters) << "%)" << endl;
    }
    cout << "Total letters: " << totalLetters << endl;
    cout << endl;
}

int main() {
    // Provided ciphertext
    string ciphertext = 
        "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE "
        "NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE "
        "IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS "
        "WFCS ZRDM PAUI S";
    
    // Read keys from file
    vector<string> possibleKeys = readKeysFromFile("keys.txt");
    
    // If file reading failed, use the provided keys
    if (possibleKeys.empty()) {
        cout << "Using hardcoded keys (file not found)" << endl;
        possibleKeys = {
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
    }
    
    cout << "Testing " << possibleKeys.size() << " possible keys..." << endl;
    cout << "==========================================" << endl << endl;
    
    // Perform frequency analysis on original ciphertext
    string processedCiphertext = preprocessText(ciphertext);
    map<char, int> cipherFreq = frequencyAnalysis(processedCiphertext);
    
    // Find the best key
    double bestScore = -1e9;
    string bestKey;
    string bestPlaintext;
    
    for (const string& key : possibleKeys) {
        string decrypted = decryptVigenere(ciphertext, key);
        double score = scoreText(decrypted);
        
        if (score > bestScore) {
            bestScore = score;
            bestKey = key;
            bestPlaintext = decrypted;
        }
    }
    
    // OUTPUT THE REQUIRED RESULTS
    
    // 1. Frequency analysis of encrypted text
    printFrequencyAnalysis(cipherFreq);
    
    // 2. The correct original (decrypted) English plaintext
    cout << "Decrypted English Plaintext:" << endl;
    cout << "============================" << endl;
    
    // Format the plaintext for better readability (group in words)
    string formattedPlaintext;
    int charCount = 0;
    for (char c : bestPlaintext) {
        formattedPlaintext += c;
        charCount++;
        
        // Add space every 5 characters for readability (approximate word boundaries)
        if (charCount % 5 == 0) {
            formattedPlaintext += ' ';
        }
    }
    cout << formattedPlaintext << endl << endl;
    
    // 3. The correct key that you discovered
    cout << "Discovered Key: " << bestKey << endl;
    cout << "=================" << endl;
    
    // Additional info about the scoring
    cout << "Key Score: " << bestScore << " (higher is better match to English)" << endl;
    
    return 0;
}