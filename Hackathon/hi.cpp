#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string ciphertext = "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS WFCS ZRDM PAUI S";
    vector<string> possibleKeys = {"utter","descriptive","caring","pies","drawer","station","soothe","year","agreeable","seemly","button","encourage","reduce","bed","wave","nosy","zoo","hateful","flaky","work","ear","uneven","cumbersome","languid","box","devilish","yawn","ablaze","lake","harbor","legs","glow","glossy","cruel","warn","hard","unique","card","hug","tangible","hook","label","exotic","account","imagine","grain","tranquil","book","pickle","whistle","sack","scissors","trashy","puzzled","bottle","smile","neighborly","eatable","admit","picayune","type","fast","shy","anger","open","add","curly","free","aftermath","cherry","daily","heal","rose","abhorrent","short","fine","guarded","vase","fascinated","fresh","chickens","mine","stare"};

    string processedCiphertext;
    int i;
    int j;
    
    for (i = 0; i < ciphertext.size(); i++) {
        if (ciphertext.at(i) != ' ') {
            processedCiphertext += ciphertext.at(i);
        }
    }

    vector<int> frequency(26, 0);
    string toVoidrepetition = "";

    for(int i = 0; i < processedCiphertext.size(); i++){
        if(isalpha(processedCiphertext.at(i))){
            char x = toupper(processedCiphertext.at(i));
            if(toVoidrepetition.find(x) == string::npos){
                int count = 0;
                for(int j = 0; j < processedCiphertext.size(); j++){
                    if(x == processedCiphertext.at(j)){
                        count++;
                    }
                }
                frequency.at(x - 'A') = count;
                toVoidrepetition = toVoidrepetition + x;
            }
        }
    }

    cout << "Frequency Analysis of Encrypted Text:" << endl;
    cout << "=====================================" << endl;
    
    for (i = 0; i < 26; i++) {
        cout << char('A' + i) << ": " << frequency.at(i) << endl;
    }
    cout << endl;

    string bestPlaintext;
    string bestKey;
    int bestScore = -1000000;
    int k;
    
    for (k = 0; k < possibleKeys.size(); k++) {
        string currentKey = possibleKeys.at(k);
        string decrypted;
        decrypted.resize(processedCiphertext.size());
        
        for (i = 0; i < processedCiphertext.size(); i++) {
            if (isalpha(processedCiphertext.at(i))) {
                char cipherChar = processedCiphertext.at(i);
                char keyChar = currentKey.at(i % currentKey.size());
                int cipherNum = cipherChar - 'A';
                int keyNum = keyChar - 'a';
                int plainNum = (cipherNum - keyNum + 26) % 26;
                decrypted.at(i) = 'A' + plainNum;
            }
        }

        int score = 0;
        for (i = 0; i < decrypted.size(); i++) {
            if (isalpha(decrypted.at(i))) {
                char c = decrypted.at(i);
                if (c == 'E' || c == 'T' || c == 'A' || c == 'O' || c == 'I' || c == 'N') {
                    score += 10;
                }
            }
        }

        if (score > bestScore) {
            bestScore = score;
            bestKey = currentKey;
            bestPlaintext = decrypted;
        }
    }

    cout << "Decrypted English Plaintext:" << endl;
    cout << "============================" << endl;
    
    string formattedPlaintext;
    for (i = 0; i < bestPlaintext.size(); i++) {
        formattedPlaintext += bestPlaintext.at(i);
        if ((i + 1) % 5 == 0) {
            formattedPlaintext += ' ';
        }
    }
    cout << formattedPlaintext << endl << endl;

    cout << "Discovered Key: " << bestKey << endl;
    cout << "=================" << endl;

    return 0;
}