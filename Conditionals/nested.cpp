//Take 3 positive integers input and print the greatest of them using nested loop, don't use and or


#include <iostream> 
using namespace std;
int main() {
    int a, b, c;
     
    cout << "Enter the 1st number : ";
    cin >> a;
    cout << "Enter the 2nd number : ";
    cin >> b;
    cout << "Enter the 3rd number : ";
    cin >> c;
    
    if(a>b){ // it will enter into the nested part only if this condition is true, so this one has to be true other wise, this line will be ignored.
        if(a>c){
            cout << a << " is the greatest number";
        }
        else{
            cout << c << " is the greatest number";

        } 
    }
    else if(b>a){ // it will enter into the nested part only if this condition is true, so this one has to be true other wise, this line will be ignored.
        if(b>c){
            cout << b << " is the greatest number";
        }
        else {
            cout << c << " is the greatest number";
        }
    }
    else if(c>a){  // it will enter into the nested part only if this condition is true, so this one has to be true other wise, this line will be ignored.
        if(c>b){
            cout << c << " is the greatest number";
        }
        else{
            cout << b << " is the greatest number";
        }
    }
else{
    cout << "Invalid action";
}



    return 0;





}