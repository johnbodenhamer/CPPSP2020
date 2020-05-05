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
        cout << root->info << " " << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

template<class DT>
void postOrder(treeNode<DT> *&root)
{
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " " << endl;}
}

template<class DT>
void inOrder(treeNode<DT> *&root)
{
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->info << " " << endl;
        inOrder(root->right);
    }
}


template<class DT>
int countNodes(treeNode<DT>* root)
//  returns the number of nodes in the tree.
{
    if (root == nullptr)
        return 0;
    else
        return countNodes(root->left) +
               countNodes(root->right) + 1;
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

 // Deletes item from tree.
 template<class DT>
 void deleteBST(treeNode<DT>*& root, char item)
 {
 treeNode<DT>* tempPtr;
 if (item < root->info.key)
 		deleteBST(root->left, item);
 else if (item > root->info.key)
 		deleteBST(root->right, item);
 else
 //****   item==root->key  ****
 {
 		if (root->left == nullptr)
 		{
 			tempPtr=root;
 			root = root->right;
 			delete tempPtr;
 		}
 		else if (root->right == nullptr)
 		{
 			tempPtr=root;
 			root = root->left;
 			delete tempPtr;
 		}
 		else
 		{
 			tempPtr=root->left;
 			while(tempPtr->right != nullptr)
 				tempPtr=tempPtr->right;
 			root->info = tempPtr->info;
 			deleteBST(root->left,tempPtr->info.key);
 		}
 	}
 }


#endif //A05_BST_TREE_H
