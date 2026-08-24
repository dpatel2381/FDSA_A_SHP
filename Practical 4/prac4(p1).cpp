#include <iostream>
#include <list>
using namespace std;

void printQueue(const list<int>& q) 
{
    for (int patient : q) 
    {
        cout << patient << " ";
    }
    cout << endl;
}

int main() 
{
    list<int> queue;

    queue.push_front(101);
    cout << "After adding 101 (Critical) at front: ";
    printQueue(queue);

    queue.push_back(202);
    cout << "After adding 202 (Routine) at end: ";
    printQueue(queue);

    queue.push_back(303);
    cout << "After adding 303 (Routine) at end: ";
    printQueue(queue);

    int position = 2;
    int patient = 404;

    if (position <= queue.size()) 
    {
        auto it = queue.begin();
        advance(it, position - 1); 
        queue.insert(it, patient);
        cout << "After inserting 404 (Priority) at position " << position << ": ";
    } 
    else 
    {
        queue.push_back(patient);
        cout << "Position " << position << " exceeds length, so 404 added at end: ";
    }
    printQueue(queue);

    
    position = 10;
    patient = 505;

    if (position <= queue.size()) 
    {
        auto it = queue.begin();
        advance(it, position - 1);
        queue.insert(it, patient);
        cout << "After inserting 505 (Priority) at position " << position << ": ";
    } 
    else 
    {
        queue.push_back(patient);
        cout << "Position " << position << " exceeds length, so 505 added at end: ";
    }
    printQueue(queue);

    return 0;
}
