//
// Created by John on 4/20/2020.
//

#ifndef A05_BST_TREE_H
#define A05_BST_TREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class DT>
struct treeNode
{
    treeNode();
    treeNode<DT> *left;
    DT info;
    treeNode<DT> *right;
};

template<class DT>
treeNode<DT>::treeNode(){
    right = nullptr;
    left = nullptr;
}

//***   Add tree node
template<class DT>
void addBST(treeNode<DT> *&root, treeNode<DT> *newNode)
{
    if (root == nullptr) {
        root = newNode;
    } else {
        if (newNode->info < root->info) {
            addBST(root->left, newNode);
        } else {
            addBST(root->right, newNode);
        }
    }
}

//***   Display the tree graphically
template<class DT>
void graphAux(int indent, treeNode<DT> *root)
{
    if (root != nullptr) {
        graphAux(indent + 8, root->right);
        cout << setw(indent) << " " << root->info << endl;
        graphAux(indent + 8, root->left);
    }
}

template<class DT>
void preOrder(treeNode<DT> *&root)
{
    if (root != nullptr) {
        cout << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}

//***  Find the smallest value
template<class DT>
treeNode<DT> *smallestNode(treeNode<DT> *root)
{
    if (root->left == nullptr)
        return root;
    else
        return smallestNode(root->left);
}

//***  Find the largest value
template<class DT>
treeNode<DT> *largestNode(treeNode<DT> *root)
{
    if (root->right == nullptr)
        return root;
    else
        return largestNode(root->right);
}

//*** Height of a tree (including max function)
template<class DT>
int max(int first, int second)
{
    if (first > second)
        return first;
    else
        return second;
}

template<class DT>
int height(treeNode<DT> *&root)
{
    if (root == nullptr)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

//***   Search for a value in the tree
template<class DT>
void searchTree(treeNode<DT> *root, treeNode<DT> *&returnNode, char &item, bool &found)
{
    if (root == nullptr)
        found = false;        // item is not found.
    else if (item < root->info.key)    // Search left subtree.
        searchTree(root->left, returnNode, item, found);
    else if (item > root->info.key)    // Search right subtree
        searchTree(root->right, returnNode, item, found);
    else {
        item = root->info.key;            // item is found.
        found = true;
        returnNode = root;
    }
}
//
// // Deletes item from tree.
// void deleteBST(treeNode*& root, char item)
// {
// treeNode* tempPtr;
// if (item < root->key)
// 		deleteBST(root->left, item);
// else if (item > root->key)
// 		deleteBST(root->right, item);
// else
// //****   item==root->key  ****
// {
// 		if (root->left == nullptr)
// 		{
// 			tempPtr=root;
// 			root = root->right;
// 			delete tempPtr;
// 		}
// 		else if (root->right == nullptr)
// 		{
// 			tempPtr=root;
// 			root = root->left;
// 			delete tempPtr;
// 		}
// 		else
// 		{
// 			tempPtr=root->left;
// 			while(tempPtr->right != nullptr)
// 				tempPtr=tempPtr->right;
// 			root->key = tempPtr->key;
// 			deleteBST(root->left,tempPtr->key);
// 		}
// 	}
// }
//

#endif //A05_BST_TREE_H
