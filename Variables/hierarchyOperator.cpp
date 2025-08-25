#include <iostream> 
using namespace std;
int main() {
    float b;
    b = 7/22*(3.14+2)*3/5; 
    
    
    // first the operation within the the bracket will happen which is 5.14, then it will perform the operation from left to right
    //7/22 which is 0.3181818182 multiplied by 5.14 then multipled by 3 then divided by 5
    cout << b << endl; // in the terminal we will see 0

    int a; 
    a = 4 + 2 % -8; // just like division multiplication, modulus operator also have first priority.
    //  2 % -8 where 2 is divided by 8, where the remainder is in decimal and we don't want that. So output is 2 then added by 4. 
    cout <<a <<endl;









    
return 0;
}