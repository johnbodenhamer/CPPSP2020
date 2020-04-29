//
// Created by John on 4/27/2020.
//

#ifndef A05_BST_CATEGORY_H
#define A05_BST_CATEGORY_H

struct Category {
    char key;
    string description;
    friend ostream & operator << (ostream & out, const Category & data);
    bool operator  == (const Category & data) const;
    bool operator > (const Category & data) const;
    bool operator < (const Category & data) const;
};

ostream & operator << (ostream & out, const Category & data)
{
    out << data.key << " " << data.description;
    return out;
}

bool Category :: operator  == (const Category & data) const
{
    return (this -> key == data.key);
}

bool Category :: operator  > (const Category & data) const
{
    return (this -> key > data.key);
}

bool Category :: operator  < (const Category & data) const
{
    return (this -> key < data.key);
}

#endif //A05_BST_CATEGORY_H
