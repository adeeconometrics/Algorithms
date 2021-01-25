#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct product{
  int product_no;
  string product_name;
  float product_price;
};

void Accept();
void Display(int count, struct product *products);
int main(){
	Accept();
}

void Accept(){
    int count;
    product *products;
    cout << "Enter number of products: ";
    cin  >> count;
    products = new product[count];
    for (int i=0; i<count; i++){
        products[i].product_no = i+1;
        cout << endl << "Product No   : " << products[i].product_no << endl;
        cout << "Product Name : ";
        cin.ignore();
        getline(cin, products[i].product_name);
        cout << "Product Price: ";
        cin  >> products[i].product_price;  
    } 
    
    Display(count, products);
}

void Display(int count, struct product *products){
	cout << fixed;
    cout << endl << "Products encoded..." << endl;
    cout << setw(15) << "Product No" << setw(15) << "Product Name" << setw(20) << "Product Price" << endl;
    for (int i=0; i<count; i++)
       cout << setw(15) << products[i].product_no << setw(15) << products[i].product_name 
            << setw(20) << setprecision(2) << products[i].product_price << endl; 
}
