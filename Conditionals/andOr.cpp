#include <iostream> 
using namespace std;
int main() {
    int x;
     
    cout << "Enter : ";
    cin >> x;
    
    if (x > 99 and x < 1000) { // and operator can also be written as &&
    
        cout << "3 digit number";
    }
    else {
        cout << "Not a 3 digit number";
    
    }
   

return 0;
}