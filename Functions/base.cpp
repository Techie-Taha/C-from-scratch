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
/*

Here's how the code is running: Always the main function runs first, so once we enter into the main function, we see greet(); greet is basically a call. 
Call means go to the greet function like void greet() and print whatever is there. So we have cout << "Hi" << endl;
cout << "Hello" << endl;
So in the terminal we will see these two lines.

*/
