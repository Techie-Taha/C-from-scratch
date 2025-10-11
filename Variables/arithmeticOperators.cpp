#include <iostream> 
using namespace std;
int main() {
    int x = 5; // it's x = 5 
    x+=5; // now it's x = 10
    cout << x << endl; // printed x = 10 in the terminal
    x+=5; // now x = 15
    cout << x << endl; // printed x = 15 in the terminal
    float y = 6.1; // y = 6.1
    cout << x << endl << y << endl; // printed x = 15, y = 6.1 in the next line
    y+=1; // now y = 7.1
    cout << x/y; // 15  divided 7.1 which us 2.11268  in the terminal

// arithmetic oppeeation between float and integers, we have more like -=, *=, /=

return 0;
}