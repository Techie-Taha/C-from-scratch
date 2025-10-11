#include <iostream> 
using namespace std;
int main() {
    int x = 6; 
    cout << x <<endl; // 6 in the terminal
// example of post increment
    cout << x++ <<endl; // first it will print 6 again, then will increment the value by one 
    cout << x <<endl; // here will print 7

    int y = 9; 
    cout << y <<endl; // 9 in the terminal
// example of pre increment
    cout << ++y <<endl; // first, it will increment the value by one then will print 10
    cout << y <<endl; // here will print 10 again

return 0;
}