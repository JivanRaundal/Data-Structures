// OUTPUT RESTRICTED DEQUEUE (ORDEQueue) - Output is regular i.e. from front end

#include<iostream>
#define MAX 5
using namespace std;

class ORDEQueue
{
    private:
        int data[MAX];
        int front, rear;
    public:
        ORDEQueue()
        {
            front = rear = -1;
        }
        int empty()
        {
            if(front == -1)
                return 1;
            return 0;
        }
        int fullF()         //fullF - full from front end
        {
            if(front == 0)
                return 1;
            return 0;
        }
        int fullR()         //fullR - full from rear end
        {
            if(rear == MAX-1)
                return 1;
            return 0;
        }
        void enqueueR(int x)
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
                cout<<"\nQueue is full from rear end";
            }
        }
        int dequeueF()              //dequeue is from front only
        {
            if(!empty())
            {
                int x = data[front];
                if(front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
                return x;
            }
            else
            {
                cout<<"\nQueue is empty ";
                return -1;
            }
        }
        void enqueueF(int x)             //enqueue from front end
        {
            if(!fullF())
            {
                if(front == -1)
                {
                    front = rear = 0;
                }
                else
                {
                    front--;
                }
                data[front] = x;
            }
            else
            {
                cout<<"\nQueue is full from front end";
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
    ORDEQueue Q;
    Q.enqueueR(10);
    Q.enqueueR(20);
    cout<<"\nDEQUEUE\n"<<Q.dequeueF();
    Q.enqueueF(8);
    Q.enqueueF(5);
    Q.enqueueR(30);
    Q.enqueueF(2);
    Q.enqueueR(40);

    Q.display();

    cout<<"\n\nDequeue\n";
    cout<<Q.dequeueF()<<endl;
    cout<<Q.dequeueF()<<endl;

    Q.display();

    Q.enqueueR(70);
    Q.enqueueF(7);
    Q.enqueueF(4);

    Q.display();

    return 0;
}