#include <iostream>
#include <vector>
using namespace std;

int main() {

  // input string + key
  // run a loop, for every character
  // shift ascii value by key

  string encrypted;
  int key;
  // key = shift value
  vector<char> decrypted;

  // getting our inputs
  cout << "encrypted text: " << endl;
  getline(cin, encrypted);

  // resizing our vectors
  decrypted.resize(encrypted.size());

  int i;

  for (key = 0; key < 26; key++) {
    // DO THE FOLLOWING FOR EVERY POSSIBLE KEY
    cout << "🔑=" << key << "  ";
    for (i = 0; i < encrypted.size(); i++) {
      if (isalpha(encrypted.at(i))) {
        if (isupper(encrypted.at(i))) {
          // minus the shift value here + calibration with 'A'
          decrypted.at(i) = ((encrypted.at(i) - 'A') - key + 26) % 26 + 'A';
        } else if (islower(encrypted.at(i))) {
          // minus the shift value here + calibration with 'a'
          decrypted.at(i) = ((encrypted.at(i) - 'a') - key + 26) % 26 + 'a';
        }
      } else {
        decrypted.at(i) = encrypted.at(i);
      }
    }

    for (i = 0; i < decrypted.size(); i++) {
      cout << decrypted.at(i);
    }
    cout << endl;
  }

  cout << endl;

  return 0;
}
