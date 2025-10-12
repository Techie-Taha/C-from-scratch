// write a program to count digits of a given number
#include<iostream>
using namespace std;
int main(){

  
    int n; // n = 5241
    cin>>n; 
    int count = 0;

    while(n != 0){ 
        n = n/10;
        
        count++;
    }
   cout << count;
// so here what's happening: basically we saying 5241 is n. in condition it says n is not equal to 0, which is true, so it enters into the loop;
// 5241 divided by 10, which is 514.1 so new value of n is 514.1
// then we increament count to 1, it was 0 now it's 1 like it goes step by by step
// then 514 is again not equal to 0, divided by 10, and the loop continues as long as, n is not equal to 0. 





return 0;
}