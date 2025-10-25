#include <iostream>

using namespace std;
int main (){

   char name1, name2;

   cin >> name1 >> name2;

   if((!isalpha(name1)) && isalpha(name2)){ // here we are saying if name1 is not alpha lets say a digit and name2 is alpha print got em
cout << "Got em";
   }

else{
    name1= tolower(name1); // if both are alpha, we saying print name1 as a lower case, 
    name2 = toupper(name2); // print name2 as an upper case

    cout << name1 << endl << name2 << endl;


}

   return 0;
}