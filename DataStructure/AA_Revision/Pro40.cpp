// Priority Queue
// Enqueue Priority Queue (enqueueP) - enqueue is by priority, dequeue is normal 
// Priority Condition => Let us consider greater integer has higher priority. 

#include<iostream>
#define MAX 5
using namespace std;

class EPQueue
{
    private:
        int data[MAX];
        int front, rear;
    public:
        EPQueue()
        {
            front = rear = -1;
        }
        int empty()
        {
            if(front == -1)
                return 1;
            return 0;
        }
        int full()
        {
            if(rear == MAX-1)
                return 1;
            return 0;
        }
        void enqueueP(int x)         //enqueue by priority
        {
            if(!full())
            {
                if(empty())         //OR if(front==-1)
                {
                    front = rear = 0;
                    data[rear] = x;
                }
                else
                {
                    int i;
                    //right shifting to maintain enqueue priority 
                    for(i=rear; i>=front && x>data[i]; i--)
                    {
                        data[i+1] = data[i];
                    }
                    data[i+1] = x;
                    rear++;
                }
            }
            else
            {
                cout<<"\nQueue is full";
            }
        }
        int dequeue()
        {
            if(!empty())
            {
                int x;
                x = data[front];
                if(front == rear)       //queue contains only one element
                {
                    front = rear = -1;
                }
                else
                {
                    for(int i=front; i<=rear-1; i++)
                    {
                        data[i] = data[i+1];            //left shifting
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
};

int main()
{
    EPQueue Q;
    Q.enqueueP(10);
    Q.enqueueP(20);
    Q.enqueueP(30);
    Q.enqueueP(5);
    Q.enqueueP(50);
    Q.enqueueP(40);

    cout<<"\n\nDequeue Queue\n";
    while(!Q.empty())
    {
        cout<<Q.dequeue()<<"\n";
    }
    cout<<Q.dequeue()<<endl;

    return 0;
}