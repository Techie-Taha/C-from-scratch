#include <iostream>

using namespace std;
int main (){

   string name = "TAHA"; // started with a string

   cout << name.at(2) << endl; // format like name.at(2) means go into the string name = "TAHA" and print index 2.
   name.at(3) = 'x'; // here we are replacing A which is index 3, with x. But has to be in char 
   cout << name;



   return 0;
}