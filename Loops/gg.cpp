#include<iostream>
using namespace std;
int main(){


int a = 3;
int n;
cin >> n;

for(int i = 4; i <= 3*n+1; i= i+3){
    
        cout << a << endl; // before printing just put a condition. just print i
        a = a *3;
    }

return 0;
}