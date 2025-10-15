// Write a program to print sum of digits of a given number 

#include<iostream>
using namespace std;
int main (){

    int number; // initialization
    cin >> number; // Then we ask let's say 55
    int sum;
    sum = 0; // for now, and this will store the result as the loop works 


    while(number != 0){ // after each iteration, number can't be 0
        
        int lastDigit = number % 10;
        
        sum += lastDigit;
        number = number / 10;


    }
    cout << sum;

    return 0;
}

// first iteration:
//number 55; last digit becomes 5 because 55 % 10 is 5. then number becomes 5 because 55 / 10 is 5. Then we add last digit to sum like 0+5 = 5

// second iteration:
// now number is 5; last digit becomes 5 because 5 % 10 is. Then number becomes 0 because 5 / 10 is 0. Then we add last digit to sum like 5+5 = 10
// There's no 3rd iteration because now number is equal to 0 and the condtion says number can't 0.