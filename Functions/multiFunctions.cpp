#include<iostream>
using namespace std;


void greet() {  // This is how we name our function, the name of the function can be anything
// Functions basically works like a shortcut

cout << "Hi" << endl;
cout << "Hello" << endl;
    

 } 

void score() {
    greet(); // we can call the function here
    cout << "50" << endl;
}
int main(){
    //greet(); // This will print out Hi Hello in the terminal 
    score(); // Print everything all here at once

   
  
}
