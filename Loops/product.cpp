// write a program to print product of digits of a given number

#include<iostream>
using namespace std;
int main (){

    int number;
    cin >> number;
    int product;
    product = 1; // not 0 because 0 * something will be 0
    for (int i = number; number != 0; number /= 10 ){ // number /= 10 helps to decrease the number of digits after each iteration and one point it will be 0.
        int lastDigit = number % 10;
        product *= lastDigit;
    }
    cout << product;

    return 0;
}