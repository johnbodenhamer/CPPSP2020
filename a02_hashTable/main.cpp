#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Product.h"
#include "HashTable.h"

int hf1(const Product &);
const int SIZE = 6;

int main() {
    HashTable<Product> productTable(hf1, SIZE);
    Product p;
    List<int> intList();
    string fileName = "Inventory.csv";
    ifstream fileIn;
    fileIn.open(fileName);
    string cStr;
    string upc;

    while(getline(fileIn, p.upc, ','))
    {
        getline(fileIn, cStr, ',');
        p.productDescription = cStr;
        getline(fileIn, cStr, ',');
        p.productCost = stod(cStr);
        getline(fileIn, cStr, '\n');
        p.productInventory = stod(cStr);

        cout << p << " is being added" << endl;

        productTable.insert(p);
        cout << "------------------------------------------------------------------------------------------------------"
        <<  endl;
    }

    fileIn.close();

    do {
        cout << "Enter a product's UPC to locate(0 to end)" << endl;
        cin >> p.upc;
        cout << "Will Search For " << p.upc << endl;
        if (productTable.retrieve(p))
        {
            cout << "retrieved from hashtable" << p << endl;
        }
        else if (p.upc != "0")
        {
            cout << "Could not find " << p.upc << endl;
        }

        cout << "------------------------------------------------------------------------------------------------------"
             <<  endl;
    } while (p.upc != "0");

    cout << "The number of collisions is " << productTable.getCollisions();

    return 0;
}

int hf1(const Product & product)
{
    int  upcInt = stoi(product.upc);
    int index = int(0.618033 * upcInt) % SIZE;
    return index;
}
