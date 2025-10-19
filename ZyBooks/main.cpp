#include<cmath>
#include<iomanip>
#include<iostream> 
using namespace std;
int main (){


string num;
cin >> num;
cout << "(" << num.substr(0, 3) << ")" << num.substr(4,6) << " -" << num.substr(7,9) << endl;








    return 0;
}