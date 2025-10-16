#include<iostream>
using namespace std;
int main(){

  
    int m;
    cin >> m;
   // m = 4
   
    for( int i = 1; i <= m; i++){ // for the rows
        for(int j = m; j >= i; j--){ // we did reverse 
     
        cout << j;
        
    }
    cout << endl;
    
        
    }



return 0;
}