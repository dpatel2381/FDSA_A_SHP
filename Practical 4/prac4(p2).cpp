#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void insertEnd(Node*& head, int val) 
{
    Node* newNode = new Node(val);
    if (!head) 
    { 
        head = newNode; return; 
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node*& head, int val) 
{
    if (!head) return;
    if (head->data == val) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) 
    {
        temp = temp->next;
    }
    if (temp->next) 
    {
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}

void forwardPrint(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reversePrint(Node* head) 
{
    if (!head) return;
    reversePrint(head->next); // recursion
    cout << head->data << " ";
}

int main() 
{
    Node* head = NULL;

    cout << "Problem 2: Deletion and Traversals\n";

    // Initial queue
    insertEnd(head, 117);
    insertEnd(head, 287);
    insertEnd(head, 399);
    insertEnd(head, 401);

    cout << "Initial queue: ";
    forwardPrint(head);

    // Delete patient 301
    deleteByValue(head, 301);
    cout << "After deleting patient 301: ";
    forwardPrint(head);

    // Forward traversal
    cout << "Forward traversal (front to back): ";
    forwardPrint(head);

    // Reverse printing
    cout << "Reverse printing (back to front): ";
    reversePrint(head);
    cout << endl;

    return 0;
}
