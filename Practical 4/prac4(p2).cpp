#include <iostream>
using namespace std;

struct Node 
{
    int token;
    Node* next;
};

Node* head = NULL;

void insertEnd(int token) 
{
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteToken(int token) 
{
    if (head == NULL)
        return;

    if (head->token == token) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != NULL && current->next->token != token) 
    {
        current = current->next;
    }

    if (current->next != NULL) 
    {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void displayForward() 
{
    Node* temp = head;

    while (temp != NULL) 
    {
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayReverse(Node* temp) 
{
    if (temp == NULL)
        return;

    displayReverse(temp->next);
    cout << temp->token << " ";
}

int main() 
{
    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertEnd(104);
    insertEnd(105);

    cout << "Initial Queue (Front to Back): ";
    displayForward();

    deleteToken(103);

    cout << "After Deleting Token 103: ";
    displayForward();

    cout << "Queue in Reverse (Last to First): ";
    displayReverse(head);
    cout << endl;

    return 0;
}
