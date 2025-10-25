#include<iostream>
using namespace std;
int main(){

    string val; 
    string rep;

    int len;

    getline(cin, val);
    getline(cin, rep);
    cin >> len;

    cout << val.replace(0, len, rep);

    return 0;
}