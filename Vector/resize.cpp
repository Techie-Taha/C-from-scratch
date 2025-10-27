#include<iostream>
#include<vector>
using namespace std;
int main() {

    vector<int> num(5); // initializing vector with 5 elements, and each of them are 0.
int valDel;
cin >> valDel;
// now we can use the concept of index to update the value from 0 to another value.  
// in the vector it looks like this {12, 13, 5, 20, 21}
num.at(0) = 12;
num.at(1) = 13;
num.at(2) = 5;
num.at(3) = 20;
num.at(4) = 21;
// now we can run a for loop to print values from the vector num
for(int i = 0; i < num.size(); i++){

    cout << num.at(i) << " "; // num.at(i) means num is our vector, at.num(i) where i is 0 right now, print index 0, which is 12. After each iteration, the index will increase
}
cout << endl;

// now we need to resize, means by using an int value, we will delete the size of the vector, like it is 5 right now, then it will be 4

num.resize(num.size() - valDel); // numsize() is 4 right if valDel is 1. Depends on the user, so we updated the size
for(int i = 0; i < num.size(); i++){

    cout << num.at(i) << " "; // num.at(i) means num is our vector, at.num(i) where i is 0 right now, print index 0, which is 12. After each iteration, the index will increase
}

    return 0;
}

