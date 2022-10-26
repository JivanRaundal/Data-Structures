// Priority Queue
// Dequeue Priority Queue (dequeueP) - dequeue is by priority, enqueue is normal 
// Priority Condition => Let us consider greater integer has higher priority. 

#include<iostream>
#define MAX 5
using namespace std;

class DEQP
{
    private:
        int data[MAX];
        int front, rear;
    public:
        DEQP()
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
        void enqueue(int x)         //enqueue is normal
        {
            if(!full())
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
        int largest()           //this method will return index of greater element in queue
        {
            int ind = front;        //OR ind = 0;
            int max = data[0];
            for(int i=front; i<=rear; i++)
            {
                if(max < data[i])
                {
                    max = data[i];
                    ind = i;
                }
            }
            return ind;
        }
        int dequeueP()      //dequeue is by priority
        {
            if(!empty())
            {
                int x;
                if(front == rear)
                {
                    x = data[front];
                    front = rear = -1;
                }
                else
                {
                    int ind = largest();        //ind will have index of largest element
                    x = data[ind];          //largest element will be returned 
                    for(int i=ind; i<=rear; i++)
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
};

int main()
{
    DEQP Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(5);
    Q.enqueue(50);
    Q.enqueue(40);

    cout<<"\n\nDequeue Queue\n";
    while(!Q.empty())
    {
        cout<<Q.dequeueP()<<"\n";
    }
    cout<<Q.dequeueP()<<endl;

    return 0;
}