#include <iostream>
using namespace std;

#define MAX 5

class Queue 
{
    int arr[MAX];
    int front, rear;

    public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    void join(int token) 
    {
        if (rear == MAX - 1) 
        {
            cout << "Error: Queue is Full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = token;

        cout << "Front Token: " << arr[front] << endl;
        cout << "Rear Token: " << arr[rear] << endl;
    }

    void serve() 
    {
        if (front == -1 || front > rear) 
        {
            cout << "Error: Queue is Empty!" << endl;
            return;
        }

        cout << "Served Token: " << arr[front] << endl;
        front++;

        if (front > rear) 
        {
            front = -1;
            rear = -1;
        }

        if (front != -1)
        {
            cout << "Front Token: " << arr[front] << endl;
        }
        else
        {
            cout << "Queue is Empty" << endl;
        }
    }
};

int main() 
{
    Queue q;

    q.join(101);
    q.join(102);
    q.join(103);

    q.serve();
    q.serve();

    q.join(104);
    q.join(105);

    return 0;
}