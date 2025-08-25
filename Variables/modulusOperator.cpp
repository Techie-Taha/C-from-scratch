#include <iostream> 
using namespace std;
int main() {

    int x, y;
    cout << "Enter number x: "; // dont have to put endl
    cin >> x; // cin >> x; ask the user to enter anything, let's we put 6
    cout << "Enter number y: ";
    cin >> y;

    cout << "The answer is " << x%y; // x = 9, y = 3, in the terminal we will see 0, since there's no remainder. it's called remainder in python

// important point : 2 % 8 = 2, because if we divide it we get some decimal values and we don't want that. 
return 0;
}