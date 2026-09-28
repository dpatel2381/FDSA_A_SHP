#include <iostream>
using namespace std;

#define MAX 5

int stackArr[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Error: Stack is FULL\n";
    }
    else
    {
        top++;
        stackArr[top] = value;
        cout << "Top: " << stackArr[top] << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Error: Stack is EMPTY\n";
    }
    else
    {
        cout << "Removed: " << stackArr[top] << endl;
        top--;

        if (top != -1)
            cout << "Top: " << stackArr[top] << endl;
        else
            cout << "Top: EMPTY\n";
    }
}

int main()
{
    int n, choice, value;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n1. Place tray\n2. Take tray\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter tray number: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else
        {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}