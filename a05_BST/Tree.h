//
// Created by John on 4/20/2020.
//

#ifndef A05_BST_TREE_H
#define A05_BST_TREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<class DT>
struct Node
{
    Node<DT> *left;
    DT info;
    Node<DT> *right;
};

template <class DT>
class Tree
{
private:
    Node<DT>* root;
    int countNodes(Node<DT>*);
    void searchTree(Node<DT>*, DT&, bool&);
    void updateTree(Node<DT>*, DT&, bool&);
    void addBST(Node<DT>*&, DT);
    void deleteBST(Node<DT>*&, DT);
    void inPrint(Node<DT>*);
    void prePrint(Node<DT>*);
    void postPrint(Node<DT>*);
    void Destroy(Node<DT>*&);
    Node<DT>* SmallestNode(Node<DT>*);
    Node<DT>* LargestNode(Node<DT>*);
    int height(Node<DT>*);
    int max(int, int);
    void graphAux(int indent,
    Node<DT>* subtreeRoot);

public:

    Tree(); // constructor
    ~Tree(); // destructor
    int numberOfNodes();
    // Function: Determines the number of elements in the tree.
    // Post: Function value = number of elements in the tree.
    bool search(DT &item);
    // Function: Retrieves item whose key matches item's key
    //           (if present).
    // Pre:  Key of item has been initialized.
    // Post: If there is an item someItem whose key matches item's
    //       key, then found is true and item is a copy of someItem;
    //       otherwise found is false and item is unchanged.
    //       The tree is unchanged.
    void add(DT item);
    // Function: Adds item to the tree.
    // Pre:  Tree is not full; item is not in the tree.
    // Post: item is in the tree.
    //       Binary search property is maintained.
    bool update(DT item);
    // Function: Updates an item in the tree.
    // Pre:  Item is in the tree.
    // Post: item is updated in the tree.
    //       Binary search property is maintained.
    bool remove(DT item);
    // Function: Deletes the item whose key matches item's key.
    // Pre:  Key of item has been initialized.
    //       One and only one item in the tree has a key matching
    //       item's key.
    // Post: No element in tree has key matching item's key
    //void Tree<DT>::PrintTree(ofstream& outFile) const
    void printPre();
    // Calls recursive function prePrint to print items in the tree in preOrder sequence.
    void printIn();
    // Calls recursive function inPrint to print items in the tree in ascending sequence.
    void printPost();
    // Calls recursive function postPrint to print items in the tree in post order sequence.
    DT smallest();
    // Calls recursive function smallestNode to find the smallest item in the tree.
    DT largest();
    // Calls recursive function largestNode to find the largest item in the tree.
    int treeHeight();
    // Calls recursive function height to find the height of the tree.
    void graph();
    // Calls recursive function graphAux to display a diagram of the tree.
};

template<class DT>
Tree<DT>::Tree()
{
    root = nullptr;
}

template<class DT>
Tree<DT>::~Tree()
{
   delete root;
}

//***   Add tree node
template<class DT>
void  Tree<DT>::addBST(Node<DT> *&root, DT item)
{
    Node<DT> * newNode = new Node<DT>;
    newNode -> info = item;

    if (root == nullptr) {
        root = newNode;
    } else {
        if (newNode->info < root->info) {
            addBST(root->left, item);
        } else {
            addBST(root->right, item);
        }
    }
}

template <class DT>
void  Tree<DT>::add(DT item)
{
    addBST(root, item);
}

//***   Display the tree graphically
template<class DT>
void Tree<DT>::graphAux(int indent, Node<DT> *root)
{
    if (root != nullptr) {
        graphAux(indent + 8, root->right);
        cout << setw(indent) << " " << root->info << endl;
        graphAux(indent + 8, root->left);
    }
}

template <class DT>
void Tree<DT>::graph()
{
    graphAux(8, root);
}

template<class DT>
void Tree<DT>::prePrint(Node<DT> *root)
{
    if (root != nullptr) {
        cout << root->info << " " << endl;
        prePrint(root->left);
        prePrint(root->right);
    }
}

template <class DT>
void Tree<DT>::printPre()
{
    prePrint(root);
}

template<class DT>
void Tree<DT>::postPrint(Node<DT> *root)
{
    if (root != nullptr) {
        postPrint(root->left);
        postPrint(root->right);
        cout << root->info << " " << endl;
    }
}

template <class DT>
void Tree<DT>::printPost()
{
    postPrint(root);
}

template<class DT>
void Tree<DT>::inPrint(Node<DT> *root)
{
    if (root != nullptr) {
        inPrint(root->left);
        cout << root->info << " " << endl;
        inPrint(root->right);
    }
}

template <class DT>
void Tree<DT>::printIn()
{
    inPrint(root);
}

template<class DT>
int Tree<DT>::height(Node<DT> *root)
{
    if (root == nullptr)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

template <class DT>
int Tree<DT>::treeHeight()
{
    return height(root);
}

template<class DT>
int Tree<DT>::countNodes(Node<DT> *root)
//  returns the number of nodes in the tree.
{
    if (root == nullptr)
        return 0;
    else
        return countNodes(root->left) +
               countNodes(root->right) + 1;
}

template<class DT>
int Tree<DT>::numberOfNodes()
{
    return countNodes(root);
}


//***  Find the smallest value
template<class DT>
Node<DT> *smallestNode(Node<DT> *root)
{
    if (root->left == nullptr)
        return root;
    else
        return smallestNode(root->left);
}

template <class DT>
DT Tree<DT>:: smallest()
{
    return smallestNode(root) -> info;
}

//***  Find the largest value
template<class DT>
Node<DT> *largestNode(Node<DT> *root)
{
    if (root->right == nullptr)
        return root;
    else
        return largestNode(root->right);
}

template <class DT>
DT Tree<DT>:: largest()
{
    return largestNode(root) -> info;
}

//*** Height of a tree (including max function)
template<class DT>
int Tree<DT>::max(int first, int second)
{
    if (first > second)
        return first;
    else
        return second;
}

//***   Search for a value in the tree
template<class DT>
void Tree<DT>::searchTree(Node<DT> *root, DT &item, bool &found)
{
    if (root == nullptr)
        found = false;        // item is not found.
    else if (item < root->info)    // Search left subtree.
        searchTree(root->left, item, found);
    else if (item > root->info)    // Search right subtree
        searchTree(root->right, item, found);
    else {
        item = root->info;            // item is found.
        found = true;
    }
}

template <class DT>
bool Tree<DT>::search(DT &item)
{
    bool found;

    searchTree(root, item, found);

    return found;
}

template<class DT>
void Tree<DT>::updateTree(Node<DT> *root, DT &item, bool &found)
{
    if (root == nullptr)
        found = false;        // item is not found.
    else if (item < root->info)    // Search left subtree.
        updateTree(root->left, item, found);
    else if (item > root->info)    // Search right subtree
        updateTree(root->right, item, found);
    else {
        root->info = item;            // item is found.
        found = true;
    }
}

template <class DT>
bool Tree<DT>::update(DT item)
{
    bool found;

    updateTree(root, item, found);

    return found;
}


// Deletes item from tree.
template<class DT>
void Tree<DT>::deleteBST(Node<DT> *&root, DT item)
{
    Node<DT> *tempPtr;
    if (item < root->info)
        deleteBST(root->left, item);
    else if (item > root->info)
        deleteBST(root->right, item);
    else
        //****   item==root->key  ****
    {
        if (root->left == nullptr) {
            tempPtr = root;
            root = root->right;
            delete tempPtr;
        } else if (root->right == nullptr) {
            tempPtr = root;
            root = root->left;
            delete tempPtr;
        } else {
            tempPtr = root->left;
            while (tempPtr->right != nullptr)
                tempPtr = tempPtr->right;
            root->info = tempPtr->info;
            deleteBST(root->left, tempPtr->info);
        }
    }
}

template <class DT>
bool Tree<DT>::remove(DT item)
{
    bool found = search(item);

    if(found) {
        deleteBST(root, item);
    }

    return found;
}

#endif //A05_BST_TREE_H
