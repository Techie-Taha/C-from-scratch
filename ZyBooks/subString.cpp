#include<iostream>
using namespace std;
int main(){
// here's whats happening 
    string val; 
    getline(cin, val); // let's say string is funny nose
    cout << val.substr(3, 4); // 3 here is the beginIndex, like we gonna start at n
    // 4 here is the length, so including n and spaces we have to print the result. 
    // output is ny n
    return 0;
}