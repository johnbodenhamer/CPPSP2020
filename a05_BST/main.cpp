#include <iostream>
#include <fstream>

using namespace std;


#include "Tree.h"
#include "Category.h"

int process(treeNode<Category> *&root);

void readCSV(const string fileName, treeNode<Category> *&root);

void getNewCategory(treeNode<Category> *&root);

int main()
{

    treeNode<Category> *root = NULL;


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


int process(treeNode<Category> *&root)
{
    int choice;
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

        if (choice < 1 || choice > 13) {
            cout << "\aInvalid choice\n"
                 << "Please try again: ";
            continue;
        }

        switch (choice) {
            case 1:
                getNewCategory(root);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
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

        searchTree(root, newKey, found);

        if (found)
        {
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

void updateCategoryDescription()
{

}

