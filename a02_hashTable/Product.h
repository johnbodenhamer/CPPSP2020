#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

using namespace std;

struct Product {
    string upc;
    string productDescription;
    double productCost;
    double productInventory;

    friend ostream & operator << (ostream & out, const Product & data);
    bool operator  == (const Product & data) const;
};

ostream & operator << (ostream & out, const Product & data)
{
  out << data.upc << " " << data.productDescription << " " << data.productCost << " " << data.productInventory;
  return out;
}

bool Product :: operator  == (const Product & data) const
{
  return (this -> upc == data.upc);
}

#endif
