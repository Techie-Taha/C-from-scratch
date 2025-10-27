#include<iostream>
#include<vector>
using namespace std;
int main (){

    // This is how we write a vector, that's the format.
    vector<string> foods= {"apple", "mango"}; // We can do direct initialization like create vector with value already in it.

    foods.push_back("Carrot"); // or we can create an empty vector and then by using push back we can store values into it. 

    cout << foods.at(2); // since it's a list we print out each values by using at function like each index
    // les say in the list, apple is index 0, mango is index 1
    return 0;
}