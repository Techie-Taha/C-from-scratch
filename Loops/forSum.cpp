#include<iostream>
using namespace std;
int main (){

    int number;
    cin >> number;
    int sum;
    sum = 0;
    for (int i = number; number != 0; number /= 10 ){
        int lastDigit = number % 10;
        sum += lastDigit;
    }
    cout << sum;

    return 0;
}