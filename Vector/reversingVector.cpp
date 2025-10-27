#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 8;
   vector<int> revVector;
   unsigned int i;
   int userInput;
   int tempValue;

   cout << "Enter integer values..." << endl;
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      cin >> userInput;
      revVector.push_back(userInput);
   }

   // Reverse

   for (i = 0; i < revVector.size() / 2; ++i) {
      tempValue = revVector.at(i); // These 3 statements swap
      revVector.at(i) = revVector.at(revVector.size() - 1 - i);
      revVector.at(revVector.size() - 1 - i) = tempValue;
   }

   cout << "Updated vector:";
   for (i = 0; i < revVector.size(); ++i) {
      cout << " " << revVector.at(i);
   }
   cout << endl;

   return 0;
}