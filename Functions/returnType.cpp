#include<iostream>

using namespace std;
void greet() {


    cout << "Hello there" << endl;
return; // Once we put this return, it kind of works like a break statement, like in the terminal we won't see stranger things, only hello there.
    cout << "Stranger things" << endl;
}


int main() {
    greet();

}