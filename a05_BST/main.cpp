#include <iostream>

using namespace std;

void process();

int main() {
    process();
    return 0;
}

int getChoice()
{
    int choice;
    bool valid;

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

    do
    {
        cin >> choice;

        switch(choice)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 10:
            case 11:
            case 12:
            case 13: valid = true;
                break;
            default : valid = false;
                cout << "\aInvalid choice\n"
                     << "Please try again: ";
                break;

        }
    }
    while (!valid);

    return choice;
}

void process()
{

    do
    {

        switch (getChoice())
        {
            case 1 : cout << '1' << endl;
                break;
            case 2 : cout << '2' << endl;
                break;
            case 3 : cout << "3 \n";
                break;
            case 4 : cout << "4 \n";
                break;
            case 5 : cout << "5 \n";
                break;
            case 6 : cout << "6 \n";
                break;
            case 7 : cout << "7 \n";
                break;
            case 8 : cout << "8 \n";
                break;
            case 9 : cout << '1' << endl;
                break;
            case 10 : cout << '2' << endl;
                break;
            case 11 : cout << "3 \n";
                break;
            case 12 : cout << "3 \n";
                break;
            case 13 : break;
        }
    }
    while (getChoice() != 13);
}