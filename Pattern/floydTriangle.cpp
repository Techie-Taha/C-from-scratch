#include<iostream>
using namespace std;
int main (){

    int number ;
    cin >> number;
    int count;
    count = 1; // initialize it outside, kind of same as sum
    for (int i = 1; i <= number; i++){
        for(int j = 1; j <= i; j++){

            cout << count;
            count++;

        }
        cout << endl;
    }

    return 0;
}