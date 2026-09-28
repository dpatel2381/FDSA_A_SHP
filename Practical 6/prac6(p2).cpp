#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page)
{
    Node* newNode = new Node();

    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Current Page: " << top->page << endl;
}

void back()
{
    if (top == NULL)
    {
        cout << "Error: No history available\n";
    }
    else
    {
        Node* temp = top;
        top = top->next;

        delete temp;

        if (top != NULL)
            cout << "Current Page: " << top->page << endl;
        else
            cout << "Current Page: No Page\n";
    }
}

int main()
{
    int n, choice;
    string page;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n1. Visit Page\n2. Back\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter page name: ";
            cin >> page;
            visit(page);
        }
        else if (choice == 2)
        {
            back();
        }
        else
        {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}