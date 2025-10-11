// take integer "x" as input and print half of the number
#include <iostream> 
using namespace std;
int main() {

    int x;
    x = 5;
    float y = (float)x;
    cout << y/2; // in the terminal we see 2.5
    //cout << x; // in the terminal we see 2, 

/* but the answer was supposed to be 2.5, we can fix it by converting int to float but according to question it has
be int, so we have to use typecasting.
*/

return 0;
}