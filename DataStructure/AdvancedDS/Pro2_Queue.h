
#define MAX 20
using namespace std;

class Node;

class Queue
{
	Node* data[MAX];
	int front,rear;
	
	public:
		Queue()
		{
			front = rear = -1;
		}
		
		int full()
		{
			if(rear == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(front==-1)		//OR if(rear==-1)
				return 1;
			return 0;
		}
		void enqueue(Node* x)
		{
			if(!full())
			{
				if(empty())
				{
					front = 0;
				}
				rear++;
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue full";
			}
		}
		Node* dequeue()
		{
			if(!empty())
			{
				Node * x;
				x = data[front];
				if(front == rear)
				{
					front = rear = -1;
				}
				else
				{
					int i;
					//shifting to left
					for(i=0; i<=rear-1; i++)
					{
						data[i] = data[i+1];
					}
					rear--;
				}
				return x;
			}
			else
			{
				cout<<"\nQueue empty;";
				return NULL;
			}
		}
};
