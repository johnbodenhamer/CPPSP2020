#include <iostream>
#include <string>
#include<istream>
#include<fstream>
using namespace std;

#include "HashTable.h"

struct Product {
    string upc;
    string productDescription;
    double productCost;
    double productInventory;
};

int hf1(const Product &);
const int SIZE = 6;

int main() {
    HashTable<Product> productTable(hf1, SIZE);
    Product p;
    string fileName = "Inventory.csv";
    ifstream fileIn;
    fileIn.open(fileName);
    string cStr;

    while(getline(fileIn, p.upc, ','))
    {
        getline(fileIn, cStr, ',');
        p.productDescription = cStr;
        getline(fileIn, cStr, ',');
        p.productCost = stod(cStr);
        getline(fileIn, cStr, ',');
        p.productInventory = stod(cStr);

//        productTable.insert(p);

        cout << p.productDescription << endl;
    }

    fileIn.close();

    return 0;
}

int hf1(const Product & product)
{
    int  upcInt = stoi(product.upc);
    int index = int(0.618033 * upcInt) % SIZE;
    return index;
}

