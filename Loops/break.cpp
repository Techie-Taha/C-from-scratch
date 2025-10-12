// write a program to find the highest factor of a number 'n' (other than n itself)

#include<iostream>
using namespace std;
int main(){


int n;
cin >> n;

for(int i = n-1; i >= 1; i--){
    if(n%i == 0){ // this line helps to get the factor 
        cout << i << endl;
        break;
    }
    
        
    }

return 0;
}