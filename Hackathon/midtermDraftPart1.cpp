#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

  string encrypted;
  vector<string> keys = {"utter", "descriptive", "caring", 
    "pies", "drawer", "station", "soothe", "year", "agreeable", 
    "seemly", "button", "encourage", "reduce", "bed", "wave", "nosy", 
    "zoo", "hateful", "flaky", "work", "ear", "uneven", "cumbersome", "languid", "box", "devilish", 
    "yawn", "ablaze", "lake", "harbor", "legs", "glow", "glossy", "cruel", "warn", "hard", "unique", "card", 
    "hug", "tangible", "hook", "label", "exotic", "account", "imagine", "grain", "tranquil", "book", "pickle", "whistle", 
    "sack", "scissors", "trashy", "puzzled", "bottle", "smile", "neighborly", "eatable", "admit", "picayune", "type", "fast", "shy", 
    "anger", "open", "add", "curly", "free", "aftermath", "cherry", "daily", "heal", "rose", "abhorrent", "short", "fine", "guarded", "vase", "fascinated", 
    "fresh", "chickens", "mine", "stare"};

  vector<string> decrypted;
  decrypted.resize(keys.size());

  // Frequency analysis
  vector<int> freq(26, 0);
  int totalLetters = 0;

  cout << "Enter encrypted text: ";
  getline(cin, encrypted);

  // Count letter frequencies
  for (int i = 0; i < encrypted.size(); i++) {
    if (isalpha(encrypted.at(i))) {
      char c = toupper(encrypted.at(i));
      freq.at(c - 'A')++;
      totalLetters++;
    }
  }

  // Display frequency analysis
  cout << "\n=== FREQUENCY ANALYSIS ===" << endl;
  for (int i = 0; i < 26; i++) {
    char letter = 'A' + i;
    cout << letter << ": " << freq.at(i) << endl;
  }

  // Try each key for decryption
  for (int k = 0; k < keys.size(); k++) {
    string key = keys.at(k);
    int keyIndex = 0;

    for (int i = 0; i < encrypted.size(); i++) {
      if (isalpha(encrypted.at(i))) {
        char c = encrypted.at(i);
        char kc = key.at(keyIndex % key.size());

        if (isupper(c)) {
          decrypted.at(k) += ((c - 'A') - (toupper(kc) - 'A') + 26) % 26 + 'A';
        } else {
          decrypted.at(k) += ((c - 'a') - (tolower(kc) - 'a') + 26) % 26 + 'a';
        }
        keyIndex++;
      } else {
        decrypted.at(k) += encrypted.at(i);
      }
    }
  }

  // Find most likely key (simple English detection)
  int bestKeyIndex = 0;
  int maxSpaces = 0;

  for (int k = 0; k < keys.size(); k++) {
    int spaceCount = 0;
    for (int i = 0; i < decrypted.at(k).size(); i++) {
      if (decrypted.at(k).at(i) == ' ') {
        spaceCount++;
      }
    }
    if (spaceCount > maxSpaces) {
      maxSpaces = spaceCount;
      bestKeyIndex = k;
    }
  }

  cout << "\n=== BEST GUESS ===" << endl;
  cout << "Key: " << keys.at(bestKeyIndex) << endl;
  cout << "Decrypted text: " << decrypted.at(bestKeyIndex) << endl;

  return 0;
}