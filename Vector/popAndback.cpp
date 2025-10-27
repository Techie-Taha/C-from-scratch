#include<iostream>
#include<vector>
using namespace std;
int main (){

    // This is how we write a vector, that's the format.
    vector<string> foods= {"apple"}; // has only one element 

foods.pop_back(); // pop back remove the last element, so 0 elements for now

cout << foods.back(); // will print the last element, but since doesn't have anything so print nothing. 
}