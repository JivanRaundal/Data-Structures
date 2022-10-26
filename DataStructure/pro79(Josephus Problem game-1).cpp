// JOSEPHUS PROBLEM (Circular Queue)

#include<iostream>
#define MAX 20
using namespace std;

class CQueue	//circular Queue
{
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
			{
				return 1;
			}
			return 0;
		}
		
		int full()
		{
			if((rear+1)%MAX == front)	//OR if((front==0 && rear==MAX-1) || (rear+1==front))
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(int x)
		{
			if(!full())
			{
				if(empty())
				{
					front = rear = 0;
				}
				else
				{
					rear = (rear+1)%MAX;
				}
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue Full";
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
				cout<<"\nQueue Empty";
				return -1;
			}
		}
		
		void show_Q()
		{
			cout<<"\n\nDisplaying Queue :\n";
			if(!empty())
			{
				int i=front;
				do
				{
					cout<<" "<<data[i];
					i = (i+1)%MAX;
				}while(i != (rear+1)%MAX);
			}
			else
			{
				cout<<"\nEmpty Queue";
			}
		}
};

int main()
{
	//Josephus Problem Logic
	CQueue Q;
	int n,roll,m;			//n = total student's, roll = roll no, m = magic number
	int i,j,winner;
	
	cout<<"\nHow many student's want to play game ? ";
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cout<<"\nEnter roll number : ";
		cin>>roll;
		Q.enqueue(roll);
	}
	
	cout<<"\n\nEnter Magic Number : ";
	cin>>m;
	//Note = To find winner, we have dequeue total (n-1) student's from (n) student's & last one remaining is winner.
	for(j=1; j<=n-1; j++)
	{
		for(i=1; i<=m-1; i++)		//m = magic number
		{
			roll = Q.dequeue();
			Q.enqueue(roll);
		}
		Q.dequeue();				//this is eliminated student in each iteration
	}
	// Note = as (n-1) students are removed from Queue. So Queue contains only one element & that is winner.
	//Q.show_Q();
	winner = Q.dequeue();
	cout<<"\n\nWinner Student's roll number is = "<<winner;
	
	return 0;
}
