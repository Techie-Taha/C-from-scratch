#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){

/*
Logic 1: 
  vector<char> cipher; // so a vector char which is empty for now
  string text; // normal string
  int key;
  cout << "write your text : " << endl;
  getline(cin, text); // will go over the entire string
  cout << "Key : " << endl;
  cin >> key;
  // here comes the important part 
cipher.resize(text.size()); // we started with a vector char, which had 0 element in it, now we are resizing it with string text
// let's char vector had 0 elements before like the size was 0, but if we write "Taha". now the char vector has 4 elements like the size of the vector is 4
for( int i = 0; i < cipher.size(); i++){
cipher.at(i) = text.at(i); // now we are saying whatever is the index of string, that's same as the index of the char. Basically initialization.
    cout << cipher.at(i)<< " "; // if we try to print out just this line it would be blank like the size is 4, like 4 char elements. but we only said resize it. we havent initialize the value for the vector 
}
*/


/*
Logic 2:
 vector<char> cipher;
  string text;
  int key;
  cout << "write your text : " << endl;
  getline(cin, text);
  cout << "Key : " << endl;
  cin >> key;
  // here comes the important part 
cipher.resize(text.size());

for(int i = 0; i < text.size(); i++){

  cipher.at(i) = text.at(i) + key; // now we are saying whatever is the index of string, that's same as the index of the char. Basically initialization. and we are adding key value

// Lets say out text is "Taha", text.at(0) it's T, which is equal to cipher.at(0) BUT AS A CHAR 'T' which has a ascii value of 84, adding key 1 will be 85 which is U
// so this part is initialization
}

for(int i = 0; i < cipher.size(); i++){

  cout << cipher.at(i); // here we are just print it out which we could also do it in the previous loop
}
*/


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