// Circular Queue using CLL

#include<iostream>
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

class CQueue
{
    private:
        Node * front;
        Node * rear;
    public:
        CQueue()
        {
            front = rear = NULL;
        }
        int empty()
        {
            if(front == NULL)
                return 1;
            return 0;
        }
        //No full condition for Linked List
        void enqueue(int x)
        {
            if(front == NULL)
            {
                front = new Node(x);
                front->next = front;
                rear = front;
            }
            else
            {
                rear->next = new Node(x);
                rear = rear->next;
                rear->next = front;
            }
        }
        int dequeue()
        {
            if(!empty())
            {
                int x = front->data;
                if(front == rear)
                {
                    delete front;
                    front = rear = NULL;
                }
                else
                {
                    Node * p = front;
                    front = front->next;
                    rear->next = front;
                    delete p;
                }
                return x;
            }
            else
            {
                cout<<"\nQueue is empty";
                return -1;
            }
        }
};

int main()
{
    CQueue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    cout<<"\n\nDequeing Queue\n";
    while(!Q.empty())
    {
        cout<<Q.dequeue()<<endl;
    }
    cout<<Q.dequeue();

    return 0;
}