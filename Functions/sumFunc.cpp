#include<iostream>
using namespace std;


void greet() {  // This is how we name our function, the name of the function can be anything
// Functions basically works like a shortcut

cout << "Hi" << endl;
cout << "Hello" << endl;
    

 } 

void score() {
    cout << "50" << endl;
}
int main(){
    greet(); // This will print out Hi Hello in the terminal 
    score(); // This will print the same thing twice

    cout << "hola"; // Now the line will be printed at the end, we can also write a cout statement in the middle of the function.
  
}