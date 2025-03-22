#include <iostream> 
#include <string>
#define tax 0.15
using namespace std; 

int main(){
    // introductory message 
    cout << "This program analyzes product sales and inverntory for a store." << endl; 
    cout << "c++ is a compiled language" << "\n\n" << endl;
    // variable declaration for product details                           
    string name;
    int catagory, initialInventoryQuantity, numberOfItemsSold;
    float pricePerUnit;
    // defining constants
    const float tax_rate = 0.15;                                             
    // input from the User                                           
    cout << "enter the name of the product: " << endl;
    getline (cin, name); 
    cout << "Catagory List \t" << endl;
    cout << "Catagory 1: Electronics" << endl;
    cout << "Catagory 2: Groceries" << endl;
    cout << "Catagory 3: Clothing" << endl; 
    cout << "Catagory 4: Stationery" << endl;
    cout << "Catagory 5: Miscellaneous" << endl;
    while (true) {
        cout << "enter the catagory of the product from 1-5" << endl; 
        cin >> catagory;
        if (catagory >= 1 and catagory <= 5){
            break;
        }else{
            cout << "catagory must be between 1 and 5" << endl;
            continue;
        } 
    } 
    cout << "enter the initial inventory: " << endl; 
    cin >> initialInventoryQuantity;            
    cout << "enter the price of the prouct: " << endl; 
    cin >> pricePerUnit;               
    while (true){
        cout << "enter the number of items sold: " << endl; 
        cin >> numberOfItemsSold;
        if (numberOfItemsSold <= initialInventoryQuantity){
            break;
        }else{
            cout << "number of items sold can't be greater than initial inventory!" << endl;
            continue;
        }
    }
    int Initial = initialInventoryQuantity; // store the "initialInventoryQuantity" in a new variable for a later use, as later on it is decreamented and hold another value
    cout << "\n\n";  
    // computed variable declaration/ calculations
    initialInventoryQuantity -= numberOfItemsSold; // use compound operator
    float totalSales = numberOfItemsSold * pricePerUnit;
    //helper variables 
    auto totalSalesCopy = totalSales;
    decltype(initialInventoryQuantity) helper = 100; // assigning value to the deduced declaration 
    // ternary condtion 
    string InventoryStat = initialInventoryQuantity < 10 ? "Low Inventory" : "Sufficient Inventory";            
    // if else and switch statement 
    if (catagory >= 1 and catagory <= 5) {
        switch(catagory) {
           case 1: 
                cout << "Catagory 1: Electronics"<< "\n\n" << endl; 
                  break; 
           case 2: 
                  cout << "Catagory 2: Groceries" << "\n\n" << endl; 
                  break; 
           case 3: 
                  cout << "Catagory 3: Clothing"  << "\n\n" << endl; 
                  break; 
           case 4: 
                 cout << "Catagory 4: Stationery" << "\n\n" << endl; 
                 break;  
           case 5: 
                 cout << "Catagory 5: Miscellaneous" << "\n\n" << endl; 
                 break;  
     }}else { 
     cout << "Product catagory must be between 1 and 5" << "\n\n" << endl;

 }
     //receipt printing simulation
     for (int reciptIteration = 1; reciptIteration <= numberOfItemsSold; ++reciptIteration) {
         cout << "item " << reciptIteration << " Price:" << pricePerUnit << endl; 
    }
    cout << "\n\n";
    //out-put of all informations                                                                                        
    cout << "The tax rate from the preprocessor constant is " << tax << endl; 
    cout << "The tax rate from the \"const\" variable is " << tax_rate << "\n\n" <<endl;                    
    cout << "Product details: " << endl; 
    cout << "Name: " << name << endl;
    cout << "Catagory: " << catagory << endl;
    cout << "Initial Inventory: " << Initial << endl;
    cout << "Items Sold: " << numberOfItemsSold << endl;
    cout << "Price: " << pricePerUnit << "\n\n" << endl; 
    cout << "Total sales: " << totalSales << endl; 
    cout << "New Inventory: " << initialInventoryQuantity << "\n\n" << endl; 
    cout << "Inventory Status: " << InventoryStat << "\n\n" << endl;                       
    cout << "Helper variable 1: " << totalSalesCopy << endl; 
    cout << "Helper variable 2: " << helper << "\n\n" << endl;
    return 0;
}