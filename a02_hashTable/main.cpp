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
        cout << "Enter a product's UPC to locate(0 to end or X to delete)" << endl;
        cin >> p.upc;

        if (p.upc == "X")
        {
            cout << "Enter product upc to delete " << endl;
            cin >> p.upc;
            if (productTable.deleteItem(p))
                cout << p.upc << " has been deleted" << endl;
        }
        else if (productTable.retrieve(p))
        {
            cout << "Will Search For " << p.upc << endl;
            cout << "retrieved from hashtable" << p << endl;
        }
        else if (p.upc != "0")
        {
            cout << "Could not find " << p.upc << endl;
        }

        cout << "------------------------------------------------------------------------------------------------------"
             <<  endl;
    } while (p.upc != "0");

    cout << "The number of collisions is " << List<Product> :: getCollisionCounter();

    return 0;
}

int hf1(const Product & product)
{
    int  upcInt = stoi(product.upc);
    int index = int(0.618033 * upcInt) % SIZE;
    return index;
}
