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
};

ostream & operator << (ostream & out, const Product & data)
{
  out << data.upc << " " << data.productDescription;
  return out;
}
#endif
