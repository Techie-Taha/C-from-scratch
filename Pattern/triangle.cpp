// Triangle
#include<iostream>
using namespace std;
int main(){

  
    int m;
    cin >> m;
   
   
    for( int i = 1; i <= m; i++){
        for(int j = 1; j <= i; j++){
            cout << "* "; 
        }
        cout << endl;
    }

return 0;
}

// Here's whats happening :
// Lets say m = 5; i = 1 which is less than m, condition true, enters inside of the loop
// j = 1, j <= 1 true so print 1 star, then we increase the value by 1, now j is 2.
// Is j less than or equal to 1, no. so we break the loop and go to the next line, after the operation the value of i increases to 2. Is 2 <= m, yes so we enters into the loop again



// Now here is the important part, we gonna look at j = 1 first, dont be like j = 2 from first iteration, because that first iteration broke already. 