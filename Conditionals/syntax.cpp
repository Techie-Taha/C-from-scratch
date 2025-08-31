#include <iostream> 
using namespace std;
int main() {
    int x;
    cout << "Enter the temp: ";
    cin >> x;
    if(x > 30){   // write the condition inside of the parenthesis
        cout << "It's hot";
// use curly braces after that, and inside the curly braces we can write our block of code. 
// as long as the codntion is true, it will print it in the terminal


    }
    
    else{
        cout<<"it's cold" << endl;
// same with else
    }
    cout<< endl <<"It's good"; // This is outside of curly braces so doesn't matter what's the condition is, it will print it anyway. 
    
   

return 0;
}