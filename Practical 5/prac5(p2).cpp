#include <iostream>
#include <string>
using namespace std;

struct SNode 
{
    string name;
    SNode* next;
    SNode(string n) : name(n), next(nullptr) {}
};

class SinglyCircle 
{
    SNode* head;
    public:
    SinglyCircle() : head(nullptr) {}

    void add(string name, int pos) 
    {
        SNode* newNode=new SNode(name);
        if(!head) 
        {
            head=newNode;
            head->next=head;
        } 
        else if(pos==0) 
        {
            SNode* tail=head;
            while (tail->next!=head)
            {
                tail=tail->next;
                newNode->next=head;
                head=newNode;
                tail->next=head;
            }
        } 
        else 
        {
            SNode* temp=head;
            for (int i=0;i<pos-1 && temp->next!=head;i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
        display();
    }

    void remove(string name) 
    {
        if(!head) 
        {
            return;
        }
        if(head->name==name) 
        {
            if(head->next==head)
            { 
                delete head; 
                head=nullptr; 
            }
            else 
            {
                SNode* tail=head;
                while(tail->next!=head)
                {
                    tail=tail->next;
                }

                SNode* temp=head;
                head=head->next;
                tail->next=head;
                delete temp;
            }
        }
        else 
        {
            SNode* temp=head;
            while (temp->next!=head && temp->next->name!=name)
            {
                temp=temp->next;
            }
            if (temp->next->name==name) 
            {
                SNode* del=temp->next;
                temp->next=del->next;
                delete del;
            }
        }
        display();
    }

    void display() 
    {
        cout<<"Singly Circle: ";
        if(!head) 
        { 
            cout<<"Empty"<<endl; 
            return; 
        }
        SNode* temp=head;
        do 
        {
            cout<<temp->name<<" ";
            temp=temp->next;
        }while(temp!=head);

        cout<<endl;
    }
};

struct DNode 
{
    string name;
    DNode* next;
    DNode* prev;
    DNode(string n) : name(n), next(nullptr), prev(nullptr) {}
};

class DoublyCircle 
{
    DNode* head;
public:
    DoublyCircle() : head(nullptr) {}

    void add(string name, int pos) 
    {
        DNode* newNode=new DNode(name);
        if(!head) 
        {
            head=newNode;
            head->next=head->prev=head;
        } 
        else if(pos==0) 
        { 
            DNode* tail=head->prev;
            newNode->next=head;
            newNode->prev=tail;
            tail->next=newNode;
            head->prev=newNode;
            head=newNode;
        } 
        else 
        {
            DNode* temp=head;
            for (int i=0;i<pos-1 && temp->next!=head;i++)
            {
                temp = temp->next;
            }
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
        }
        display();
    }

    void remove(string name) 
    {
        if(!head)
        {
            return;
        }
        if (head->name==name) 
        {
            if(head->next==head)
            {
                delete head; 
                head = nullptr; 
            }
            else 
            {
                DNode* tail=head->prev;
                DNode* temp=head;
                head=head->next;
                tail->next=head;
                head->prev=tail;
                delete temp;
            }
        } 
        else 
        {
            DNode* temp=head;
            do 
            {
                if (temp->name==name) 
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp;
                    break;
                }
                temp=temp->next;
            } while (temp!=head);
        }
        display();
    }

    void display() 
    {
        cout<<"Doubly Circle: ";
        if(!head)
        {
            cout<<"Empty"<<endl; 
            return; 
        }
        DNode* temp=head;
        do 
        {
            cout<<temp->name<<" ";
            temp=temp->next;
        } while(temp!=head);

        cout<<endl;
    }
};

int main() 
{
    SinglyCircle sc;
    DoublyCircle dc;

    sc.add("A", 0);
    dc.add("A", 0);

    sc.add("B", 1);
    dc.add("B", 1);

    sc.add("C", 2);
    dc.add("C", 2);

    sc.remove("B");
    dc.remove("B");

    sc.add("D", 1);
    dc.add("D", 1);

    sc.remove("A");
    dc.remove("A");

    return 0;
}
