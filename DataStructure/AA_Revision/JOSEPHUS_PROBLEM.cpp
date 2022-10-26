// Josepus Problem (using CLL)

#include<iostream>
#define MAX 20
using namespace std;

class CQueue
{
    private:
        int data[MAX];
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
        void enqueue(int x)
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
        int dequeue()
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
                    front = (front+1)%MAX;
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
    //Josephus Problem
    CQueue CQ;
    int n,roll;
    int magic_no = 0;
    cout<<"\nHow many students participated in game ? ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"\nEnter roll of student "<<i<<" : ";
        cin>>roll;
        CQ.enqueue(roll);
    }
    cout<<"\n\nEnter Magic Number : ";
    cin>>magic_no;

    //Now, from 'n' students, 'n-1' will be eliminated & only 1 will be winner
    for(int j=1; j<=n-1; j++)
    {
        for(int i=1; i<=magic_no-1; i++)
        {
            roll = CQ.dequeue();
            CQ.enqueue(roll);
        }
        //one student will be eliminated in each iteration of loop
        cout<<"\nStudent with roll no "<<CQ.dequeue()<<" is eliminated";
    }
    //Now, Queue will contain only 1 element & i.e. the winner
    int winner = CQ.dequeue();
    cout<<"\n\nWINNER STUDENT'S ROLL NO = "<<winner<<endl;

    return 0;
}