#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;

int main(){

    cout << "1. Part 1. Analysis/Decryption" << endl;
    cout << "2. Part 2. Encryption" << endl;
    cout << "Enter Your option (1 or 2): " << endl;
    int option;

    cin >> option;
    cin.ignore(); /* ----- This line was taken from ChatGPT; when prompted how to fix input buffering issue,  accesed: Oct. 2025 -----*/

    if(option == 1){

    string cipherText = "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS WFCS ZRDM PAUI S";

// vector keys has a size of 83 elements, like possible keys for decryption
    vector<string>keys = {"utter", "descriptive", "caring", "pies", "drawer", "station", "soothe", "year", 
       "agreeable", "seemly", "button", "encourage", "reduce", "bed", "wave", "nosy", "zoo", "hateful", "flaky",      
         "work", "ear", "uneven", "cumbersome", "languid", "box", "devilish", "yawn", "ablaze", "lake", "harbor", "legs",
           "glow", "glossy", "cruel", "warn", "hard", "unique", "card", "hug", "tangible", "hook", "label", "exotic", "account", 
             "imagine", "grain", "tranquil", "book", "pickle", "whistle", "sack", "scissors", "trashy", "puzzled", "bottle", "smile",
               "neighborly", "eatable", "admit", "picayune", "type", "fast", "shy", "anger", "open", "add", "curly", "free", "aftermath",
                  "cherry", "daily", "heal", "rose", "abhorrent", "short", "fine", "guarded", "vase", "fascinated", "fresh", "chickens", "mine", "stare"};

// run a quick for loop to remove the spaces between the cipherText since the letters have been places into groups of 4 so that the word breaks are disguised
 
    string updated_cipherText; // empty string to store cipherText without spaces
    for(int i = 0; i < static_cast<int>(cipherText.size()); i++){ /* ----- to avoid error with the aid ChatGPT; ,  accesed: Oct. 2025 -----*/ 
        if(cipherText.at(i) != ' '){
            updated_cipherText = updated_cipherText + cipherText.at(i);
        }
    }

// Step 1 : A frequency analysis showing the counts of every letter of our team's encrypted text
/***********
  Some ideas were taken from a youtube video:
  CodeWithBK
  https://youtu.be/8Sl92uxK9Ac?si=9IIpkZV9OfTUyExx
  Created: April, 2024
***********/

    vector<int> frequency(26, 0); // All 26 elements with a default value of 0
    for(int i = 0; i < static_cast<int>(updated_cipherText.size()); i++){
        if(isalpha(updated_cipherText.at(i))){
            char x = updated_cipherText.at(i);
            frequency.at(x - 'A')++;
        }
    }

    cout << "A frequency analysis showing the counts of every letter of our team's encrypted text: " << endl;
    for(int i = 0; i < 26; i++){
        cout << char('A' + i) << " : " << frequency.at(i) << endl;
    }
    cout << endl;

// Step 2 and 3 : the correct original (decrypted) English plaintext and best key
    string correctText, correctKey; // stores the best decrypted text and key
    int highestScore = 0;  // no key tested yet
    bool firstKey = true; // goal is to loop though every possible keys, haven't processed any keys yet

// Boolean works better since we have to check each keys. And using the concept of score, when firstKey = false, we can compare it
    for(int k = 0; k < static_cast<int>(keys.size()); k++){
        string currentKey = keys.at(k); // basically we have a container that holds whatever current key being tested
        string decryption; // This will hold the result of decryption with current key

        for(int i = 0; i < static_cast<int>(updated_cipherText.size()); i++){ // inner loop decrypts each character
            char firstLetter = updated_cipherText.at(i); // basically it gets the current cipherText char
            char key = currentKey.at(i % currentKey.size()); // this is the following individual key character, which stays within 0 1 2 3 4, so it has a fixed sequence

// formula : (C - K + 26) % 26
            int val = (firstLetter - 'A' - (key - 'a') + 26) % 26;
            decryption += 'A' + val;
        }

//  we gotta make sure decrypted text based on common English letters 
/* -----
This code was written with the aid of ChatGPT;
when prompted 'how to score the decrypted text based on English letter frequency?'
the generated text helped me write the following code:
accessed: Oct. 2025
 -------- */
        int currentScore = 0;
        for(int i = 0; i < static_cast<int>(decryption.size()); i++){
            char letter = decryption.at(i);
            if(letter == 'E' || letter == 'T' || letter == 'A' || letter == 'O' || letter == 'I' || letter == 'N'){
                currentScore = currentScore + 10;
            }
        }

        // need to find the best, now a basic comparison 
        if(firstKey || currentScore > highestScore){
            highestScore = currentScore;
            correctKey = currentKey;
            correctText = decryption;
            firstKey = false;
// here's how the code works;
/* we initialized highest score to 0, lets say current score is 120, so 120 greater than 0 which is true
knowledge from discrete mathematics, so we have( firstKey = true || score = true) and true || true is true, so our code executes
now highest score is 120, lets say utter, and correcttext will be decrypted text with "utter"
and then our first key becomes false;
*/
        }
    }

// creating final string to make text more readable
    string finalText; // empty string which will store the final decrypted text 
    for(int i = 0; i < static_cast<int>(correctText.size()); i++){ // because in line 98 we changed the decryption with correctText
        finalText = finalText + correctText.at(i);

// we will list the decrypted text with spaces with 4 character, just to read it better
         if(i % 4 == 3){
            finalText += ' ';
         }
    }

    cout << "The correct English plain text: " << finalText << endl;
    cout << "Best key: " << correctKey << endl;
}

    else if(option == 2){

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
  for (i = 0; i < static_cast<int>(phrase.size()); i++){
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
  for(i = 0; i < static_cast<int>(keys.size()); i++){
    if(i == static_cast <int>(keys.size()) - 1)
    {
      cout << keys.at(i);
    }
    else
    {
      cout << keys.at(i) << ", ";
    }
  }

  //Loop through each character in the encrypted text to decrypt
  for (i = 0; i < static_cast<int> (encryptedText.size()); i++) 
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
}

else{
  cout << "Input out of the range" << endl;
}


    return 0;
}