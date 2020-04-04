#include <iostream>
#include <string>
#include<istream>
#include<fstream>
using namespace std;

#include "List.h"
#include "HashTable.h"

struct Product {
    string upc;
    string productDescription;
    double productCost;
    double productInventory;
};

int main() {
    Product p;
    string fileName = "Inventory.csv";
    ifstream fileIn;
    fileIn.open(fileName);
    string cStr;

    getline(fileIn, cStr);
    while(getline(fileIn, p.upc, ','))
    {
        getline(fileIn, cStr, ',');
        p.productDescription = cStr;
        getline(fileIn, cStr, ',');
        p.productCost = stod(cStr);
        getline(fileIn, cStr, ',');
        p.productInventory = stod(cStr);
    }

    return 0;
}