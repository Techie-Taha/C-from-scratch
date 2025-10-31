//Import libraries for time and manipulating strings and vectors
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int main() {
  //initialize variables and vectors to be used, like for storing the keys and the encrypted/decrypted text
  string phrase;
  vector<int> keys;
  string encryptedText = "";
  string decryptedText = "";
  string yn;
  int i;
  int firstKey = 24;
  int randomKey;
  int previousKey;

  //Used unsigned long long to remove the warning of comparison
  unsigned long long seed = time(0);  // used gen AI to come up with the idea of using current time as seed for pseudo-random number generation 

  //initialize constants to be used for key generation
  int a = 16642;         
  int c = 10139;      
  int m = 4294;

  //Prompt user for phrase to encrypt
  cout << endl << "Enter the phrase you would like to encrypt: ";
  getline(cin, phrase);

  //Resize vector to phrase size
  keys.resize(phrase.size());

  //Loop through each character in the phrase to generate keys and encryption
  for (i = 0; i < phrase.size(); i++){
    //Check for alphabetic character
    if (isalpha(phrase.at(i))) 
    {
      //use seed, constants, and other operations to generate pseudo-random key
      seed = (a * seed + c) % m;
      unsigned long mixed = seed + (phrase.at(i) * i * 42) + previousKey;
      randomKey = mixed % 26;
      /*
      Used gen AI to help come up with a way to generate pseudo-random numbers, which used the current time as seed and other constants, replicating the linear congruential generator method.
      */
      //ad key to vector
      keys.at(i) = randomKey;

      //keep setting previousKey to use in algorithm
      if(i == 0)
      {
        previousKey = firstKey;
      }
      else
      {
        previousKey = keys.at(i - 1);
      }

      //checks for letter case and subtracts accordingly
      if (isupper(phrase.at(i))) 
      {
        encryptedText.push_back((phrase.at(i) - 'A' + randomKey) % 26 + 'A');
      } 
      else if (islower(phrase.at(i))) 
      {
        encryptedText.push_back((phrase.at(i) - 'a' + randomKey) % 26 + 'a');
      }
    } 
    else 
    {
      //If not alphabetic, dont do anything and make key 0
      encryptedText.push_back(phrase.at(i));
    }
  }

  //Output encrypted text and keys
  cout << endl << "Encrypted Text: " << encryptedText << endl << endl << "Keys: ";
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

  //Loop through each character in the encrypted text to decrypt
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

  //Ask user if they want to see the decrypted text and output accordingly
  cout << endl << endl << "Would you like to see the decrypted text? (y/n): ";
  cin >> yn;

  if( yn == "y" || yn == "Y" ) {
    cout << endl << "Decrypted text: " << decryptedText << endl << endl;
  }
  else {
    cout << endl << "Goodbye!" << endl << endl;
  }

  return 0;
}