#include<iostream>
using namespace std;
int main(){

  
    int m;
    cin >> m;
   
   
    for(int i = 1; i <= m; i++){ // for rows
        for(int j = 1; j <= m-i; j++){ // for spaces
            cout << "  ";
        }
        for(int j = 1; j <= i; j++){ // for columns
            cout <<"* "; 
        }
        cout << endl;
    }

return 0;
}