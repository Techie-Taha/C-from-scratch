#include <iostream>

using namespace std;
int main (){

   string name = "Taha is bad"; // usual string
   // what find operator does is, they print index. lets say 
   cout << name.find("is"); // This will print out 5, like find only print the index of the first letter. In this case it's i, not s or is . only i which is 5

   // name.find(good) is equal to npos meaning no position like good is not there.
   
   if((name.find("good")) == string::npos ){  // since the condition matches it will print Hi.
cout << "Hi";


}
else{
    cout << "bye";
}
   return 0;
}