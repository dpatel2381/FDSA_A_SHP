#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string song;
    Node* prev;
    Node* next;
    Node(string s) : song(s), prev(nullptr), next(nullptr) {}
};

class Playlist 
{
    private:
        Node* head;
        Node* tail;
        Node* current;
        int count;

    public:
        Playlist() : head(nullptr), tail(nullptr), current(nullptr), count(0) {}

        void addToBeginning(string song) 
        {
            Node* newNode=new Node(song);
            if(!head) 
            {
                head=newNode;
                tail=newNode;
            } 
            else 
            {
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
            count++;
            display();
        }

        void addToEnd(string song) 
        {
            Node* newNode=new Node(song);
            if(!tail) 
            {
                head=newNode;
                tail=newNode;
            } 
            else 
            {
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
            count++;
            display();
        }

        void insertAfterCurrent(string song) 
        {
            if(!current) 
            {
                cout<<"No current song selected. Adding to end."<<endl;
                addToEnd(song);
                return;
            }

            Node* newNode=new Node(song);
            newNode->next=current->next;
            newNode->prev=current;
            if(current->next)
            {
                current->next->prev=newNode;
                current->next=newNode;
            }
            if(current==tail)
            {
                tail=newNode;
            }
            count++;
            display();
        }

        void removeFirst() 
        {
            if(!head) 
            {
                cout<<"Playlist is empty."<<endl;
                return;
            }

            Node* temp=head;
            head=head->next;
            if(head)
            {
                head->prev=nullptr;
            }
            else
            {
                tail=nullptr;
            }
            delete temp;
            count--;
            display();
        }

        void setCurrent(string song) 
        {
            Node* temp=head;
            while(temp) 
            {
                if(temp->song==song) 
                {
                    current=temp;
                    cout<<"Now playing: "<<song<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"Song not found in playlist."<<endl;
        }

        void display() 
        {
            cout<<"Playlist ("<<count<<" songs): ";
            Node* temp = head;
            while(temp) 
            {
                cout<<temp->song;

                if(temp->next)
                {
                    cout<<" -> ";
                }

                temp=temp->next;
            }
            cout<<endl;
        }
};

int main() 
{
    Playlist pl;
    pl.addToBeginning("SongA");
    pl.addToEnd("SongB");
    pl.addToEnd("SongC");
    pl.setCurrent("SongB");
    pl.insertAfterCurrent("SongX");
    pl.removeFirst();
    pl.addToBeginning("SongY");
    pl.display();
    return 0;
}
