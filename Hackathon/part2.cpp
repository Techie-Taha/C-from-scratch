#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>
using namespace std;

int main() {

  string phrase;
  vector<int> keys;
  string encryptedText = "";
  string decryptedText = "";
  int i;
  int firstKey = 24;
  int randomKey;
  int previousKey;

  unsigned long seed = time(0);     
  unsigned long a = 1664525;         
  unsigned long c = 1013904223;      
  unsigned long m = 4294967296;

  cout << "Enter the phrase you would like to encrypt: " << endl;
  getline(cin, phrase);


  keys.resize(phrase.size());

  for (i = 0; i < phrase.size(); i++){
    if (isalpha(phrase.at(i))) 
    {
      if (isupper(phrase.at(i))) 
      {
        if(i == 0)
        {
          previousKey = firstKey;
        }
        else
        {
          previousKey = keys.at(i - 1);
        }

        seed = (a * seed + c) % m;
        unsigned long mixed = seed + (phrase.at(i) * i * 42) + previousKey;
        randomKey = mixed % 26;
        keys.at(i) = randomKey;
        encryptedText.push_back((phrase.at(i) - 'A' + randomKey) % 26 + 'A');
      } 
      else if (islower(phrase.at(i))) 
      {
        if(i == 0)
        {
          previousKey = firstKey;
        }
        else
        {
          previousKey = keys.at(i - 1);
        }

        seed = (a * seed + c) % m;
        unsigned long mixed = seed + (phrase.at(i) * i * 42) + previousKey;
        randomKey = mixed % 26;
        keys.at(i) = randomKey;
        encryptedText.push_back((phrase.at(i) - 'a' + randomKey) % 26 + 'a');
      }
    } 
    else 
    {

      encryptedText.push_back(phrase.at(i));
    }
  }

  cout << "Encrypted Text: " << encryptedText << endl << "Keys: ";
  for(i = 0; i < keys.size(); i++){
    if(i == keys.size() - 1)
    {
        cout << keys.at(i);
    }
    else
    {
        cout << keys.at(i) << ", ";
    }
  }

  for (i = 0; i < encryptedText.size(); i++) 
  {

    if (isalpha(encryptedText.at(i))) 
    {

      if (isupper(encryptedText.at(i))) 
      {
        decryptedText.push_back(((encryptedText.at(i) - 'A') - keys.at(i) + 26) % 26 + 'A');
      } 
      else if (islower(encryptedText.at(i))) 
      {
        decryptedText.push_back(((encryptedText.at(i) - 'a') - keys.at(i) + 26) % 26 + 'a');
      }
    } 
    else 
    {

      decryptedText.push_back(encryptedText.at(i));
    }
  }

  cout << endl << "Decrypted text: " << decryptedText << endl;

  return 0;
}