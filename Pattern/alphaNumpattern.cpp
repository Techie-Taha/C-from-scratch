// Triangle with both numbers and alphabets 
#include<iostream>
using namespace std;
int main(){

  
    int m;
    cin >> m;
   
   
    for( int i = 1; i <= m; i++){ // the row is fixed
        if(i % 2 != 0){
            for (int j = 1; j <= i; j++){ // this loop will work if and and if the row is odd
                cout << j;

            }
            } 
        else{
            for (int j = 1; j <= i; j++){ // this loop will work if and and if the row is even
                cout << (char)(j+64);
        }
        
        }
        cout << endl;

    }
return 0;
}