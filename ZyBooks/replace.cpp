#include <iostream>

using namespace std;
int main (){

   string name = "Taha ahmed"; // started with a string

   cout << name.replace(5, 5, "Grey");
//cout << name.replace(5(start_postion), 5(length), "Grey(new string)"); we are basically saying start at index 5 where we have ahmed, replace that with grey, an entire different string


   return 0;
}