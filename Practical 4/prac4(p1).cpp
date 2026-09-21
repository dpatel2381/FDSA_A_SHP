#include <iostream>
using namespace std;

struct Node 
{
    int token;
    Node* next;
};

Node* head = NULL;

void insertFront(int token) 
{
    Node* newNode = new Node;
    newNode->token = token;
    newNode->next = head;
    head = newNode;
}

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

void insertPosition(int token, int pos) 
{
    Node* newNode = new Node;
    newNode->token = token;

    if (pos == 1) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{

    insertEnd(101);
    cout << "After adding routine patient 101: ";
    display();

    insertEnd(102);
    cout << "After adding routine patient 102: ";
    display();

    insertFront(201);
    cout << "After adding critical patient 201: ";
    display();

    insertPosition(150, 2);
    cout << "After inserting priority patient 150 at position 2: ";
    display();

    insertEnd(103);
    cout << "After adding routine patient 103: ";
    display();

    return 0;
}
