#include<cmath>
#include<iostream> 
using namespace std;
int main (){


int userNum, divNum;



cin >> userNum >> divNum;



for( int i = 1; i <= 3; i++){
    int userNum = userNum / divNum;
    cout << userNum << " ";
    
}
cout << endl;



    return 0;
}