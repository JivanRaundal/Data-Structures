// Recursive SLL

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int x)
        {
            data = x;
            next = NULL;
        }
};

class SLL
{
    private:
        Node * head;
    public:
        SLL()
        {
            head = NULL;
        }
        void create();
        Node* create_rec();
        void show();
        void show_rec(Node*);
        int search(int x);
        int search_rec(Node*,int);
        int count();
        int count_rec(Node*);
};

void SLL::create()
{
    head  = create_rec();
}

Node* SLL::create_rec()
{
    char str[10];
    cout<<"\nEnter data or 'STOP' to stop : ";
    cin>>str;
    if(strcmp(str,"STOP") == 0)
    {
        return NULL;
    }
    Node * p;
    p = new Node(atoi(str));
    p->next = create_rec();
    return p;       //linking will be done during backtracking process
}

void SLL::show()
{
    cout<<"\n\nLIST\n";
    show_rec(head);
}

void SLL::show_rec(Node * p)
{
    if(p == NULL)
    {
        return;
    }
    cout<<" "<<p->data;
    show_rec(p->next);
}

int SLL::count()
{
    return count_rec(head);
}

int SLL::count_rec(Node * p)
{
    if(p == NULL)
    {
        return 0;
    }
    return 1 + count_rec(p->next);
}

int SLL::search(int x)
{
    return search_rec(head, x);
}

int SLL::search_rec(Node * p,int x)
{
    if(p == NULL)
    {
        return 0;
    }
    if(p->data == x)
    {
        return 1;
    }
    return search_rec(p->next, x);
}

int main()
{
    SLL L;
    L.create();
    L.show();
    cout<<"\n\nTotal Nodes = "<<L.count();
    int x;
    cout<<"\n\nEnter element to be searched : ";
    cin>>x;
    if(L.search(x))
        cout<<"\nFound";
    else    
        cout<<"\nNot Found";
        
    return 0;
}