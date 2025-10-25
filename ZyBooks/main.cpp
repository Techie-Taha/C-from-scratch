//#include<cmath>
//#include<iomanip>
#include <iostream>
//#include <cstdlib>
using namespace std;
int main (){

   double celsiusValue; // first variable
   double fahrenheitValue; // second variable
   char userChar;

   celsiusValue = 0.0; // initialization
   userChar = 'y';

   while (userChar == 'y') {
      fahrenheitValue = (celsiusValue * 9.0 / 5.0) + 32.0;

      cout << celsiusValue << " C is ";
      cout << fahrenheitValue << " F" << endl; 

      cout << "Type y to continue, any other to quit: ";
      cin >> userChar;

      celsiusValue = celsiusValue + 5;
      cout << endl;
   }

   cout << "Goodbye." << endl;




   return 0;
}