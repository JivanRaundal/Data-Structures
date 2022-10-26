// Josepus Problem (using CLL)

#include<iostream>
#define MAX 10
using namespace std;

typedef struct Job
{
    int Jno;
    int Jtime;
}Job;

class CQueue
{
    private:
        Job data[MAX];
        int front, rear;
    public:
        CQueue()
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
            if((rear+1)%MAX == front)
                return 1;
            return 0;
        }
        void enqueue(Job x)
        {
            if(!full())
            {
                if(front == -1)
                {
                    front = 0;
                }
                rear = (rear+1)%MAX;
                data[rear] = x;
            }
            else
            {
                cout<<"\nQueue is full";
            }
        }
        Job dequeue()
        {
            Job x;
            if(!empty())
            {
                x = data[front];
                if(front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front = (front+1)%MAX;
                }
                return x;
            }
            else
            {
                cout<<"\nQueue is empty ";
                return x;
            }
        }
};

int main()
{
    //Job Scheduling Algorithm
    CQueue CQ;
    Job obj;
    int n, tp;
    cout<<"\nHow many job's you want to schedule ? ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"\nEnter job number : ";
        cin>>obj.Jno;
        cout<<"\nEnter Job Time   : ";
        cin>>obj.Jtime;

        CQ.enqueue(obj);
    }

    cout<<"\n\nEnter time period : ";
    cin>>tp;

    cout<<"\n\nJob's will be executed in the following sequence : ";
    while(!CQ.empty())
    {
        obj = CQ.dequeue();
        obj.Jtime = obj.Jtime - tp;
        if(obj.Jtime > 0)
        {
            //reschedule it
            CQ.enqueue(obj);
        }
        else
        {
            cout<<"\nJob No "<<obj.Jno<<" executed completely";
        }
    }

    return 0;
}