#include<iostream>
#include<vector>
using namespace std;
int main (){




    vector<int> num(365);

    for(int i = 0; i < num.size(); i++){


        cout << num.at(i) << endl;
    }




    return 0;

}