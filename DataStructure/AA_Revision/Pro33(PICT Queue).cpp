// PICT Queue

#include<iostream>
#define MAX 5
using namespace std;

class Queue
{
	private:
		int data[MAX];
		int front, rear;
	public:
		Queue()
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
		void enqueue(int x)
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
					//front++;		//for simple Queue
					//But for PICT Queue (shifting will require towards left side
					for(int i=front; i<=rear-1; i++)
					{
						data[i] = data[i+1];
					}
					rear--;		//decrement rear;
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
	Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);		
    
    cout<<"\n\nDequeue 2 elements\n";
    cout<<Q.dequeue()<<endl;
    cout<<Q.dequeue()<<endl;
  
    Q.enqueue(70);
    Q.enqueue(80);
	
    cout<<"\n\nDequeue elements from queue\n";
    while(!Q.empty())
    {
        cout<<Q.dequeue()<<endl;
    }
    cout<<Q.dequeue();
	return 0;
}


