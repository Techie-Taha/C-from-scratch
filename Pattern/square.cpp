// write a Square pattern with 12345 when n = 5;

#include<iostream>
using namespace std;
int main(){

  
    int n;
   // since square we can have only one variable for both rows and columns
    cin >> n; // n is the number of columns
    for( int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << j; 
        }
        cout << endl;
    }

return 0;
}