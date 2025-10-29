#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){

    string cipherText = "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS WFCS ZRDM PAUI S";

// vector keys has a size of 83 elements, like possible keys for decryption
    vector<string>keys = {"utter", "descriptive", "caring", "pies", "drawer", "station", "soothe", "year", 
       "agreeable", "seemly", "button", "encourage", "reduce", "bed", "wave", "nosy", "zoo", "hateful", "flaky",      
         "work", "ear", "uneven", "cumbersome", "languid", "box", "devilish", "yawn", "ablaze", "lake", "harbor", "legs",
           "glow", "glossy", "cruel", "warn", "hard", "unique", "card", "hug", "tangible", "hook", "label", "exotic", "account", 
             "imagine", "grain", "tranquil", "book", "pickle", "whistle", "sack", "scissors", "trashy", "puzzled", "bottle", "smile",
               "neighborly", "eatable", "admit", "picayune", "type", "fast", "shy", "anger", "open", "add", "curly", "free", "aftermath",
                  "cherry", "daily", "heal", "rose", "abhorrent", "short", "fine", "guarded", "vase", "fascinated", "fresh", "chickens", "mine", "stare"};

// we gonna run a quick for loop to remove the spaces between the cipherText since the letters have been placed into groups of 4 so that the word breaks are disguised. 
    string updated_cipherText;
    for(int i = 0; i < cipherText.size(); i++){
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
    vector<int>frequency(26, 0); // 26 elements with a default value of 0;
    string toVoidrepetition = ""; // empty string to store letters that have already been counted

    for(int i = 0; i < updated_cipherText.size(); i++){
        if(isalpha(updated_cipherText.at(i))){
        char x = toupper(updated_cipherText.at(i)); 
        if(toVoidrepetition.find(x) == string::npos){ // check to see whether x is already in toVoidrepetition, if not, second loop starts 

            int count = 0;

            for(int j = 0; j < updated_cipherText.size(); j++){ // This will only run if we have a new letter
                if(x == updated_cipherText.at(j)){
                    count++;
                }
            }
            frequency.at(x - 'A') = count;
            toVoidrepetition = toVoidrepetition + x;
        }
    }
}
cout << "A frequency analysis showing the counts of every letter of our team's encrypted text: " << endl;
    for(int i = 0; i < 26; i++){
        cout << char('A' + i) << " : " << frequency.at(i) << endl;
    }
    cout << endl;

// Step 2 and 3 : the correct original (decrypted) English plaintext, 
    string correctText, correctKey;
    int highestScore = 0; // it's a value we will use later to do comparison

    bool firstKey = true; // Boolean works better since we have to check each keys and using the concept of score, we can compare it
// We going run a loop inside the vector keys
    for(int k = 0; k < keys.size(); k++){
        string currentKey = keys.at(k);
        string decrypted; // empty string is going to hold our decrypted text
        for(int i = 0; i < updated_cipherText.size(); i++){
            char firstLetter = updated_cipherText.at(i);
            char key = currentKey.at(i % currentKey.size());
// formula :
            int num = (updated_cipherText.at(i) - 'A' - (key - 'a') + 26) % 26;
            decrypted += + 'A' + num;

        }
/* -----
This code was written with the aid of ChatGPT;
when prompted 'how to score the decrypted text based on English letter frequency?'
the generated text helped me write the following code:
accessed: Oct. 2025
 -------- */

        int currentScore = 0;
        for(int i = 0; i < decrypted.size(); i++){

            char letter = decrypted.at(i);
            if(letter == 'E' || letter == 'T' || letter == 'A' || letter == 'O' || letter == 'I' || letter == 'N'){
                currentScore = currentScore + 10;
            }
        }


        int perfectScore = currentScore > highestScore;
        if(firstKey || perfectScore){

            highestScore = currentScore;
            correctKey = currentKey;
            correctText = decrypted;
            firstKey = false;

        }
    }    

    string finalText; // empty string

    for(int i = 0; i < correctText.size(); i++){
        finalText = finalText + correctText.at(i);


// since the original text was 4 characters, lets make it 5, just an arbitrary
         if(i % 5 == 4) { 
           finalText += ' ';
         }

    }
    cout << "The correct English plain text: " << finalText << endl;

    cout << "Best Key: " << correctKey << endl;





    return 0;
}