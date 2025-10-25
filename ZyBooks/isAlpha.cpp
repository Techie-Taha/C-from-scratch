#include <iostream>

using namespace std;
int main (){

   char word =  'x'; // we gonna define a char variable. as long as there is an alphabet in it, it will work. 

   if(isalpha(word)){ // thats the format of writing it. 
      cout << word << " is an alpha character" << endl; // output it's alpha, since it's x
   }

   else{
      cout << word << " is not an alpha character" << endl;
   }

// Lets say we dont to check just an alphabet, but an entire line string. We can use the concept of index. 

string name = "Taha is a good boy";
if (isalpha(name.at(3))){
   cout << "Yes alphabetical" << endl;
}
else{
   cout << "not alphabetical" << endl;
}



   return 0;
}