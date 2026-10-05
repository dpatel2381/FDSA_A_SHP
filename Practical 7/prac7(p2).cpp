#include <iostream>
using namespace std;

struct Node 
{
    string patient;
    Node* next;
};

class Queue 
{
    Node* front;
    Node* rear;

    public:
    Queue() 
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(string patient) 
    {
        Node* newNode = new Node();

        newNode->patient = patient;
        newNode->next = NULL;

        if (rear == NULL) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front Patient: " << front->patient << endl;
    }

    void attend() 
    {
        if (front == NULL) 
        {
            cout << "Error: No patients waiting!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Attended Patient: " << front->patient << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;

        if (front != NULL)
        {
            cout << "Front Patient: " << front->patient << endl;
        }
        else
        {
            cout << "Ward is Empty" << endl;
        }
    }
};

int main() 
{
    Queue q;

    q.arrive("101 Dhanvi");
    q.arrive("102 Diya");
    q.arrive("103 Heer");

    q.attend();
    q.attend();

    q.arrive("104 Lavanya");

    q.attend();

    return 0;
}