#include <iostream>

using namespace std;
int main (){

   char num =  '2'; // we gonna define a char variable. as long as there is an digit in it, it will work. 

   if(isdigit(num)){ // thats the format of writing it. 
      cout << num << " is an digit character" << endl; // output it's a digit, since it's 2
   }

   else{
      cout << num << " is not an digit character" << endl;
   }

// Lets say we dont to check just an digit, but an entire line string. We can use the concept of index. 

string num2 = "2345678";
if (isdigit(num2.at(3))){
   cout << "Yes digit" << endl;
}
else{
   cout << "not digit" << endl;
}



   return 0;
}