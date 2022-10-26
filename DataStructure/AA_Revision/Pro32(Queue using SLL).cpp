// Simple Queue Using SLL

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

class Queue
{
    private:
        Node* front;
        Node* rear;
    public:
        Queue()
        {
            front = rear = NULL;
        }
        int empty();
        //No full condition for SLL
        void enqueue(int x); 
        int dequeue();
};

int Queue::empty()
{
	if(front == NULL)
		return 1;
	return 0;
}

void Queue::enqueue(int x)
{
    if(front == NULL)       //or rear==NULL
    {
        front = new Node(x);
        rear = front;
    }
    else
    {
        rear->next = new Node(x);
        rear = rear->next;
    }
}

int Queue::dequeue()
{
    if(!empty())
    {   
        int x = front->data;
        if(front == rear)       //Queue contains only one element/node
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node * p = front;
            front = front->next;
            delete p;
        }
        return x;
    }
    else
    {
        cout<<"\nQueue is empty ";
        return -1;
    }
}

int main()
{
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    cout<<"\n\nDequeue Queue\n";
    while(!Q.empty())
    {
        cout<<Q.dequeue()<<endl;
    }
    Q.dequeue();
    return 0;
}
