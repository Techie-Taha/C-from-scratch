#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){


  vector<char> cipher; // so a vector char which is empty for now
  string text; // normal string
  int key;
  cout << "write your text : " << endl;
  getline(cin, text); // will go over the entire string
  cout << "Key : " << endl;
  cin >> key;
int i;
  // here comes the important part 
cipher.resize(text.size()); // we started with a vector char, which had 0 element in it, now we are resizing it with string text
// let's char vector had 0 elements before like the size was 0, but if we write "Taha". now the char vector has 4 elements like the size of the vector is 4

/*
for(int i = 0; i < text.size(); i++){
// initialization of our char vector

cipher.at(i) = text.at(i) + key;
// it works well but the problem is after z, it wont work because in ascii table after z it's [, and we dont want that, also we dont want input which are not alphabetical, here is the update
cout << cipher.at(i); 
}
*/


for(int i = 0; i < text.size(); i++){


    if(isalpha(text.at(i))){

        if(isupper(text.at(i))){
        // so we are basically saying if we have a upper case Z, instead of going to [, go to A, then do the job, and there's a special formula for that.
        cipher.at(i) = ((text.at(i) - 'A' + key) % 26) + 'A'; 
    }
     else if(islower(text.at(i))){
// so we are basically saying if we have a lower case z, instead of going to {, go to a, then do the job, and there's a special formula for that.
        cipher.at(i) = ((text.at(i) - 'a' + key) % 26) + 'a';
     }
    }
    else{
        //let's say it's not alphabetical, just dont shift, keep as it is

        cipher.at(i) = text.at(i);
    }
}

for (int i = 0; i < cipher.size(); i++) {
    cout << cipher.at(i); // finally print the result 
  }


return 0;


}