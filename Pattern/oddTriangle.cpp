// Triangle with odd values only

#include<iostream>
using namespace std;
int main(){

  
    int m;
    cin >> m;
   
   
    for( int i = 1; i <= m; i++){ // the row is fixed
        int a = 1;
            for (int j = 1; j <= i; j++){
                cout << a;
                a+=2;

            }
            cout << endl;
            }
            
            return 0;
    }