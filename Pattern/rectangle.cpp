// Rectangle

#include<iostream>
using namespace std;
int main(){

  
    int m, n;
    cin >> m; // m is the number of rows
    cin >> n; // n is the number of columns
    for( int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << "* "; 
        }
        cout << endl;
    }

return 0;
}