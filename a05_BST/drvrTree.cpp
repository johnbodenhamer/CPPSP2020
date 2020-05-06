#include <iostream>
#include <fstream>

using namespace std;


#include "Tree.h"
#include "Category.h"

string process(Tree<Category> myTree);

void readCSV(const string fileName, Tree<Category> myTree);

void getNewCategory(Tree<Category> myTree);

void updateCategoryDescription(Tree<Category> myTree);

void deleteCategory(Tree<Category> myTree);

void searchCategory(Tree<Category> myTree);

int main()
{
    Tree<Category> myTree;

    readCSV("Categories.csv", myTree);

    process(myTree);
    return 0;
}

void readCSV(const string fileName, Tree<Category> myTree)
{

    Category c;
    ifstream fileIn;
    string cStr;
    int i = 0;

    fileIn.open(fileName);

    while (getline(fileIn, cStr, ',')) {
        Tree<Category> *newTree = new Tree<Category>;
        c.key = cStr[0];
        getline(fileIn, cStr, '\n');
        c.description = cStr.substr(0, cStr.length() - 1);
        myTree.add(c);
        i++;
    }

    fileIn.close();
}


string process(Tree<Category> myTree)
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
                getNewCategory(myTree);
                break;
            case 2:
                updateCategoryDescription(myTree);
                break;
            case 3:
                deleteCategory(myTree);
                break;
            case 4:
                searchCategory(myTree);
                break;
            case 5:
                cout << myTree.numberOfNodes() << " nodes in tree" << endl;
                break;
            case 6:
                cout << "The smallest category is: " << myTree.smallest() << endl;
                break;
            case 7:
                cout << "The largest category is: " << myTree.largest() << '\n' << endl;
                break;
            case 8:
                cout << "The Tree's height is: " << myTree.treeHeight() << '\n' << endl;
                break;
            case 9:
                myTree.printIn();
                break;
            case 10:
                myTree.printPre();
                break;
            case 11:
                myTree.printPost();
                break;
            case 12:
                myTree.graph();
                break;
            case 13:
                isDone = true;
                break;
        }
    } while (!isDone);

    return choice;
}

void getNewCategory(Tree<Category> myTree)
{
    Category c;
    char newKey;
    string newDesc;
    bool isDone = false;

    while (!isDone) {

        cout << "Enter a character, press 0 to quit" << endl;
        cin >> newKey;
        if (newKey == '0') {
            isDone = true;
            break;
        }

        if (myTree.search(c)) {
            cout << "Already Exists, try again" << endl;
            continue;
        }
        cout << "Enter a description" << endl;
        cin >> newDesc;

        c.description = newDesc;

        myTree.add(c);
    }
}

void updateCategoryDescription(Tree<Category> myTree)
{
    char searchKey;
    string newDesc;
    Category c;

    cout << "Enter a Key to update" << endl;
    cin >> searchKey;

    if (myTree.search(c)) {
        cout << "Current Description: " << c.description << endl;
        cout << "Enter a new Description: ";
        cin >> newDesc;
        c.description = newDesc;
        myTree.update(c);
    } else {
        cout << "Tree not found!" << endl;
    }

}

void deleteCategory(Tree<Category> myTree)
{
    Category c;

    cout << "Enter a key to delete" << endl;

    cin >> c.key;

    if (myTree.remove(c)) {
        cout << "Category " << c << " deleted" << endl;
    } else {
        cout << "Key not found" << endl;
    }

}

void searchCategory(Tree<Category> myTree)
{
    bool found;
    Category c;

    cout << "Enter a key to search" << endl;

    cin >> c.key;

    if (myTree.search(c)) {
        cout << c << endl;
    } else {
        cout << "Key not found" << endl;
    }
}


