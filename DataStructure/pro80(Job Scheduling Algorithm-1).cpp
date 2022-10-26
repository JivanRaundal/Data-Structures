// JOB SCHEDULING ALGORITHM

#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

typedef struct Job		//OR use class
{
	int Job_no;
	int Job_time;
}Job;

class CQueue					//circular queue
{
		Job data[MAX];			//array of objects
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
			if((rear+1)%MAX == front)		//OR if((front==0 && rear==MAX-1) || (rear+1==front))
			{
				return 1;
			}
			return 0;
		}
		
		void enqueue(Job T)
		{
			if(!full())
			{
				if(empty())		//OR if(front==-1)
				{
					front = rear = 0;
				}
				else
				{
					rear = (rear+1)%MAX;
				}
				data[rear] = T;
			}
			else
			{
				cout<<"\nQueue Full";
			}
		}
		
		Job dequeue()
		{
			Job T;
			if(!empty())
			{
				T = data[front];
				if(front == rear)		// if Queue contains only 1 element
				{
					front = rear = -1;
				}
				else
				{
					front = (front+1)%MAX;
				}
				return T;
			}
			else
			{
				cout<<"\nQueue Empty";
				return T;
			}
		}
};

int main()
{
	int n, tp;		//n = no of jobs, tp = time period for which one job will execute at a time for tp amount.
	CQueue CQ;
	Job T;
	
	cout<<"\nHow many Job's ? ";
	cin>>n;
	cout<<"\n\nEnter Job details\n";
	for(int i=1; i<=n; i++)
	{
		cout<<"\nEnter Job Number : ";
		cin>>T.Job_no;
		cout<<"\nEnter Job Time   : ";
		cin>>T.Job_time;
		CQ.enqueue(T);							//enqueue job in queue
	}
	
	cout<<"\n\nEnter time period : ";
	cin>>tp;
	
	cout<<"\n\nSequence in which Job's will get executed : ";
	while(!CQ.empty())
	{
		T = CQ.dequeue();
		T.Job_time = T.Job_time - tp;
		
		if(T.Job_time > 0)
		{
			CQ.enqueue(T);
		}
		else
		{
			cout<<"\nJob "<<T.Job_no<<" completed";
		}
	}
	return 0;
}


