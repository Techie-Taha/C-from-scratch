#include <iostream>

using namespace std;
int main (){

   string name1 = "Nishat"; // started with a string
string name2 = "Taha";
// One way to do it  
   name1.append("!!!") ;// Rules: name.append() adds one string to the end of another. Must be written as a string
   cout << name1 << endl; // output TAHAxxx
// second way 
name2.append(3, '!') ;// Rules: name.append(3 means the amount of times you want to add the char, 'x' means whatever you want to add)
   cout << name2; // output TAHAxxx


   return 0;
}