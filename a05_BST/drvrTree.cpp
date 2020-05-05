#include <iostream>
#include <fstream>

using namespace std;


#include "Tree.h"
#include "Category.h"

string process(treeNode<Category> *&root);

void readCSV(const string fileName, treeNode<Category> *&root);

void getNewCategory(treeNode<Category> *&root);

void updateCategoryDescription(treeNode<Category> *&root);

void getHeight(treeNode<Category> *root);

void deleteCategory(treeNode<Category> *&root);

void searchCategory(treeNode<Category> *&root);

void getSmallestCategory(treeNode<Category> *root);

void getLargestCategory(treeNode<Category> *root);

int main()
{

    treeNode<Category> *root = nullptr;


    readCSV("Categories.csv", root);

    process(root);
    return 0;
}

void readCSV(const string fileName, treeNode<Category> *&root)
{

    Category c;
    ifstream fileIn;
    string cStr;
    int i = 0;

    fileIn.open(fileName);

    while (getline(fileIn, cStr, ',')) {
        treeNode<Category> *newNode = new treeNode<Category>;
        newNode->info.key = cStr[0];
        getline(fileIn, cStr, '\n');
        newNode->info.description = cStr.substr(0, cStr.length() - 1);
        addBST(root, newNode);
        i++;
    }

    fileIn.close();
}


string process(treeNode<Category> *&root)
{
    string choice;
    bool isDone = false;

    do {
        cout << "======== Menu ========\n"
             << " 1.   Add categories\n"
             << " 2.   Update an existing category's description \n"
             << " 3.   Delete a category \n"
             << " 4.   Search for a category \n"
             << " 5.   Determine number of nodes in the tree\n"
             << " 6.   Determine the smallest category in the tree \n"
             << " 7.   Determine the largest category in the tree\n"
             << " 8.   Determine the height of the tree  \n"
             << " 9.   Display the categories ascending   \n"
             << " 10.  Display the categories preOrder \n"
             << " 11.  Display the categories postOrder \n"
             << " 12.  Display the tree graphically  \n"
             << " 13.  Quit \n\n";

        cin >> choice;

        if (stoi(choice) < 1 || stoi(choice) > 13) {
            cout << choice << " is an invalid choice\n"
                 << "Please try again: ";
            continue;
        }

        switch (stoi(choice)) {
            case 1:
                getNewCategory(root);
                break;
            case 2:
                updateCategoryDescription(root);
                break;
            case 3:
                deleteCategory(root);
                break;
            case 4:
                searchCategory(root);
                break;
            case 5:
                cout << countNodes(root) << " nodes in tree" << endl;
                break;
            case 6:
                getSmallestCategory(root);
                break;
            case 7:
                getLargestCategory(root);
                break;
            case 8:
                getHeight(root);
                break;
            case 9:
                inOrder(root);
                break;
            case 10:
                preOrder(root);
                break;
            case 11:
                postOrder(root);
                break;
            case 12:
                graphAux(15, root);
                break;
            case 13:
                isDone = true;
                break;
        }
    } while (!isDone);

    return choice;
}

void getNewCategory(treeNode<Category> *&root)
{
    treeNode<Category> *foundNode;

    char newKey;
    string newDesc;
    bool isDone = false;
    bool found;

    while (!isDone) {

        cout << "Enter a character, press 0 to quit" << endl;
        cin >> newKey;
        if (newKey == '0') {
            isDone = true;
            break;
        }

        searchTree(root, foundNode, newKey, found);

        if (found) {
            cout << "Already Exists, try again" << endl;
            continue;
        }
        cout << "Enter a description" << endl;
        cin >> newDesc;

        treeNode<Category> *newNode = new treeNode<Category>;
        newNode->info.key = newKey;
        newNode->info.description = newDesc;

        addBST(root, newNode);
    }
}

void updateCategoryDescription(treeNode<Category> *&root)
{
    bool found;
    char searchKey;
    string newDesc;
    treeNode<Category> *foundNode;

    cout << "Enter a Key to update" << endl;

    cin >> searchKey;

    searchTree(root, foundNode, searchKey, found);

    if (found) {
        cout << "Current Description: " << foundNode->info.description << endl;
        cout << "Enter a new Description: ";
        cin >> newDesc;
        foundNode->info.description = newDesc;
    } else {
        cout << "Node not found!" << endl;
    }

}

void getHeight(treeNode<Category> *root)
{
    cout << "The Tree's height is: " << height(root) << '\n' << endl;
}

void deleteCategory(treeNode<Category> *&root)
{
    bool found;
    char searchKey;
    treeNode<Category> *foundNode;

    cout << "Enter a key to delete" << endl;

    cin >> searchKey;

    searchTree(root, foundNode, searchKey, found);

    if (found) {
        deleteBST(root, searchKey);
    } else {
        cout << "Key not found" << endl;
    }

}

void searchCategory(treeNode<Category> *&root)
{
    bool found;
    char searchKey;
    treeNode<Category> *foundNode;

    cout << "Enter a key to search" << endl;

    cin >> searchKey;

    searchTree(root, foundNode, searchKey, found);

    if (found) {
        cout << foundNode->info << endl;
    } else {
        cout << "Key not found" << endl;
    }
}

void getSmallestCategory(treeNode<Category> *root)
{
    treeNode<Category> *foundNode;
    foundNode = smallestNode(root);

    cout << "The smallest category is: " << foundNode->info << endl;
}

void getLargestCategory(treeNode<Category> *root)
{
    treeNode<Category> *foundNode;
    foundNode = largestNode(root);

    cout << "The largest category is: " << foundNode->info << endl;
}
