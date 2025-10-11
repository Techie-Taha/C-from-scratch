#include <iostream> 
using namespace std;
int main() {
    int costPrice, sellingPrice;

    cout << "Enter costPrice : ";
    cin >> costPrice;
    cout << "Enter sellingPrice: ";
    cin >> sellingPrice;
    
    if (costPrice < sellingPrice) {
        
        cout << "Profit is " << sellingPrice - costPrice << "$";
    }
    else if (costPrice > sellingPrice) {
        cout << "You lost " << costPrice - sellingPrice << "$";
    }
    else if (costPrice == sellingPrice) {
        cout << "No profit no loss";
    }
    
    
   

return 0;
}