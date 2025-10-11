#include <iostream> 
using namespace std;
int main() {
    int x;
     
    cout << "Enter x : ";
    cin >> x ;
    
    
    if (x > 99 and x < 1000) { // and operator can also be written as &&
    
        cout << "3 digit number" << endl;
    }

    int y;

    cout << "Enter y : ";
    cin >> y;


    if (y < 10 || y > 20){ // or
        cout << "Hi";
    }
    else {
        cout << "Bye";
    }
   

return 0;
}