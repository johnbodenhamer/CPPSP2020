//
// Created by John on 4/20/2020.
//

#ifndef A05_BST_TREE_H
#define A05_BST_TREE_H

#include <iostream>
#include <iomanip>
using namespace std;

template <class DT>
struct treeNode
{
  treeNode<DT>* left;
  DT info;
  treeNode<DT>* right;
};

//***   Add tree node
template <class DT>
void addBST(treeNode<DT>* root, treeNode<DT>* newNode)
{
  if(root==nullptr) {
    root=newNode;
  } else if(newNode -> info < root -> info) {
    addBST(root -> left, newNode);
  } else {
    addBst(root -> right, newNode);
  }
}

//***   Display the tree graphically
template <class DT>
void  graphAux(int indent, treeNode<DT>* root)
{
  if (root != nullptr)
    {
      graphAux(indent + 8, root->right);
      cout << setw(indent) << " " << root->info << endl;
      graphAux(indent + 8, root->left);
    }
}

// void preOrder(treeNode* root)
// {
//     if(root != nullptr)
//     {
//         cout << root -> key;
//         preOrder(root -> left);
//         preOrder(root -> right);
//     }
// }
//
// //***  Find the smallest value
// treeNode* smallestNode (treeNode* root)
// {
// 	if (root->left == nullptr)
// 		return root;
// 	else
// 		return smallestNode(root->left);
// }
//
// //***  Find the largest value
// treeNode* largestNode (treeNode* root)
// {
// 	if (root->right == nullptr)
// 		return root;
// 	else
// 		return largestNode(root->right);
// }
//
// //***   Search for a value in the tree
// void searchTree(treeNode* root, char& item, bool& found)
// {
//     if (root == nullptr)
// 		found = false;		// item is not found.
//     else if (item < root ->key)	// Search left subtree.
// 	  	searchTree (root ->left, item, found);
// 	else if (item > root ->key)	// Search right subtree
// 		searchTree (root ->right, item, found);
//     else
//     {
// 	item = root ->key;			// item is found.
// 	found = true;
//     }
// }
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
// //*** Height of a tree (including max function)
// int max(int first, int second)
// {
//     if(first > second)
//        return first;
//     else
//        return second;
// }
// int height(treeNode*root)
// {
//     if(root == nullptr)
//        return 0;
//     else
//        return 1 + max(height(root->left), height(root->right));
// }

#endif //A05_BST_TREE_H
