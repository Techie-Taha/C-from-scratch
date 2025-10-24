//#include<cmath>
//#include<iomanip>
#include<iostream> 
using namespace std;
int main (){

   double x;

   cin >> x;
   if(x<30.5 || x > 75.5){
cout << "Skip" << endl;
   }
   else {
    cout << "Authorize" << endl;
   }



    return 0;
}