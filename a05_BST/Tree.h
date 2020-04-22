//
// Created by John on 4/20/2020.
//

#ifndef A05_BST_TREE_H
#define A05_BST_TREE_H

#include <iostream>
#include <iomanip>
using namespace std;

struct treeNode
{
    treeNode* left;
    char key;
    treeNode* right;
};

void addBST(treeNode* & root, treeNode* newNode)
{
    if(root==nullptr)
        root=newNode;
    else
        if(newNode -> key < root -> key)
            addBST(root -> left, newNode);
        else
            addBst(root -> right, newNode);
}

int main()
{
    char inChar;
    treeNode* tree;
    treeNode* pNew;

    tree = nullptr;

    cout << "Input a character to add: ";
    cin >> inChar;

    while (isalpha(inChar))
    {
        pNew = new treeNode;
        pNew -> key = inChar;
        pNew -> right = nullptr;
        pNew -> left = nullptr;

        addBST(tree, pNew);
        cout << "Input a character to add: ";
        cinn >> inChar;
    }

    return 0;
}

void preOrder(treeNode* root)
{
    if(root != nullptr)
    {
        cout << root -> key;
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

preOrder(tree);
cout << endl;

#endif //A05_BST_TREE_H
