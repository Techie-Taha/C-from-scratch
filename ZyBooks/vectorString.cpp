#include<iostream>
#include<vector>
using namespace std;
int main (){

    // This is how we write a vector, that's the format.
    vector<string> food; // here we are starting with a empty list

food.push_back("Apple"); // by using these we can fill our vector with values
food.push_back("Mango");
food.push_back("Kiwi");

food.push_back("Berry");

food.at(0) = "watermelon";
cout << food.at(0);
    return 0;

}
