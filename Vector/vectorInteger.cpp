#include<iostream>
#include<vector>
using namespace std;
int main (){

    
    vector<int> num; // with int values

num.push_back(1); // by using these we can fill our vector with values
num.push_back(2);
num.push_back(3);

num.push_back(4);

num.at(0) = 7;

for(int i = 0; i < num.size(); i++){
    cout << num.at(i) << endl;
}



    return 0;

}