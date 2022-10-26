// INPUT RESTRICTED DEQUEUE (IRDEQueue) - Input is regular i.e. from rear end

#include<iostream>
#define MAX 5
using namespace std;

class IRDEQueue
{
    private:
        int data[MAX];
        int front, rear;
    public:
        IRDEQueue()
        {
            front = rear = -1;
        }
        int empty()
        {
            if(front == -1)
                return 1;
            return 0;
        }
        int fullF()             //will return 1 if Queue is full from front
        {
            if(front == 0)
                return 1;
            return 0;
        }
        int fullR()             //will return 1 if Queue is full from rear
        {
            if(rear == MAX-1)
                return 1;
            return 0;
        }
        void enqueueR(int x)            //enqueue from rear end
        {
            if(!fullR())
            {
                if(front == -1)
                {
                    front++;
                }
                rear++;
                data[rear] = x;
            }
            else
            {
                cout<<"\nQueue is full";
            }
        }
        int dequeueF()              //dequeue from front end
        {
            if(!empty())
            {
                int x;
                x = data[front];
                if(front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    //left shifting
                    for(int i=front; i<=rear-1; i++)
                    {
                        data[i] = data[i+1];
                    }
                    rear--;
                }
                return x;
            }
            else
            {
                cout<<"\nQueue is empty ";
                return -1;
            }
        }
        int dequeueR()              //dequeue from rear end
        {
            if(!empty())
            {
                int x;
                x = data[rear];
                if(front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    rear--;
                }
                return x;
            }
            else
            {
                cout<<"\nQueue is empty ";
                return -1;
            }
        }
        void display()
        {
            cout<<"\n\nQueue\n";
            for(int i=front; i<=rear; i++)
            {
                cout<<data[i]<<endl;
            }
        }
};

int main()
{
    IRDEQueue Q;
    Q.enqueueR(10);
    Q.enqueueR(20);
    Q.enqueueR(30);
    Q.enqueueR(40);
    Q.enqueueR(50);
    Q.enqueueR(60);

    cout<<"\n\nDequeue\n";
    Q.dequeueF();
    Q.dequeueR();

    Q.display();

    Q.enqueueR(60);
    Q.enqueueR(70);
    
    Q.display();
    return 0;
}