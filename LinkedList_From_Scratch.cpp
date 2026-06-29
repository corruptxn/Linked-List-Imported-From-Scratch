#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
class List
{
    Node* head=nullptr;
    Node* tail=nullptr;
    public:
    void push_front(int val)
    {
        Node* newNode=new Node(val); //allocates the container's (Node) memory in the heap
        if (head==nullptr)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        else
        {
            (*newNode).next=head;
            head=newNode;
        }
    }
    void push_back(int val)
    {
        Node* newNode=new Node(val);
        if (head==nullptr)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        else
        {
            (*tail).next=newNode;
            tail=newNode;
        }
    }
    void pop_front()
    {
        if (head==nullptr)
        {
            cout << "Your list is empty!" << endl;
            return;
        }
        Node* temp=head;
        head=(*head).next;
        (*temp).next=nullptr;
        delete temp;
    }   
    void pop_back()
    {
        if (head==nullptr)
        {
            cout << "Your list is empty!" << endl;
            return;
        }
        Node* temp=head;
        while((*temp).next!=tail)
        {
            temp=(*temp).next;
        }
        (*temp).next=nullptr;
        delete tail;
        tail=temp;
    }
    void insert(int val,int pos)
    {
        if (pos<0)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos==0)
        {
            push_front(val);
            return;
        }
        Node* temp=head;
        int i;
        for (i=0;i<pos-1;i++)
        {
            if (temp==nullptr)
            {
                cout << "Invalid position!" << endl;
                return;
            }
            temp=(*temp).next;
        }
        Node* newNode=new Node(val);
        (*newNode).next=(*temp).next;
        (*temp).next=newNode;
    }
    void search(int key)
    {
        Node* temp=head;
        int idx=0;
        while (temp!=nullptr)
        {
            if ((*temp).data==key)
            {
                cout << "Element found at index " << idx << "!" << endl;
                return;
            }
            temp=(*temp).next;
            idx++;
        }
        cout << "Element not found!" << endl;
    }
    void printLL()
    {
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout << (*temp).data << " -> ";
            temp=(*temp).next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    List ll;
    
    /*BODY*/

    return 0;
}