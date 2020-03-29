#include <iostream>
using namespace std;

char getChoice();
void process();
void sumOfIntegers();
int recursiveSumOfIntegers(int num);

int main()
{
    process();
    return 0;
}

char getChoice()
{
    char choice;
    bool valid;

    cout << "======== Menu ========\n"
         << " 1.   Sum of n integers \n"
         << " 2.   Sum of Odds or Evens in n integers \n"
         << " 3.   Multiply by addition \n"
         << " 4.   Determine the square root of a number \n"
         << " 5.   Greatest Common Divisor \n"
         << " 6.   Determine the sum of the digits of an integer \n"
         << " 7.   Raise the power of a number \n"
         << " 8.   Search for array elements  \n"
         << " 9.   Quit       \n\n";

    do
    {
        cin >> choice;

        switch(choice)
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': valid = true;
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
    char choice;

    do
    {
        choice = getChoice();

        switch (choice)
        {
            case '1' : sumOfIntegers();
                break;
            case '2' : cout << "2 \n";
                break;
            case '3' : cout << "3 \n";
                break;
            case '4' : cout << "4 \n";
                break;
            case '5' : cout << "5 \n";
                break;
            case '6' : cout << "6 \n";
                break;
            case '7' : cout << "7 \n";
                break;
            case '8' : cout << "8 \n";
                break;
            case '9' : break;
        }
    }
    while (choice != '9');
}

void sumOfIntegers()
{
    int input,
        result;

    cout << "Enter an integer" << endl;

    cin >> input;

    result = recursiveSumOfIntegers(input);
    cout << result;
}

int recursiveSumOfIntegers(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num + recursiveSumOfIntegers(num - 1);
}
