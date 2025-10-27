#include <iostream>
#include <vector>
using namespace std;

int main() {

  // input string + key
  // run a loop, for every character
  // shift ascii value by key

  string plaintext;
  int key;
  vector<char> ciphertext;

  // getting our inputs
  cout << "plaintext: " << endl;
  getline(cin, plaintext);
  // key = shift value
  cout << "key: ";
  cin >> key;

  // resizing our vectors
  ciphertext.resize(plaintext.size());

  int i;
  for (i = 0; i < plaintext.size(); i++) {
    // check if character is alphabetical
    if (isalpha(plaintext.at(i))) {
      // check case of character
      // perform shift by key, and calibrate with ascii table
      if (isupper(plaintext.at(i))) {
        ciphertext.at(i) = ((plaintext.at(i) - 'A') + key) % 26 + 'A';
      } else if (islower(plaintext.at(i))) {
        ciphertext.at(i) = ((plaintext.at(i) - 'a') + key) % 26 + 'a';
      }
    } else {
      // for non-alphabetic characters, don't shift with key
      ciphertext.at(i) = plaintext.at(i);
    }
  }

  // print out the ciphertext
  for (i = 0; i < ciphertext.size(); i++) {
    cout << ciphertext.at(i);
  }

  cout << endl;

  return 0;
}