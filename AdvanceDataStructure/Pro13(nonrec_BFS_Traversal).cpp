// Non-recursive BFS Traversal of Tree
// Breadth First Traversal (level by level traversal) (Queue datastructure is used)

#include<iostream>
#define MAX 20
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		Node()
		{
			data = 0;
			left = right = NULL;	
		}
		Node(int x)
		{
			data = x;
			left = right = NULL;
		}
};

//Defining normal Queue, can use PICT Queue also
class Queue
{
	private:
		Node* data[MAX];
		int front, rear;
	public:
		Queue()
		{
			front = rear = -1;	
		}
		void init()			//used to initialized Queue (to make Queue logically empty)
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
			if(rear == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void enqueue(Node * x)
		{
			if(!full())
			{
				if(front == -1)
				{
					front++;		//front = 0;
				}
				rear++;
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue is full";
			}
		}
		Node* dequeue()
		{
			if(!empty())
			{
				Node * x;
				x = data[front];
				if(front == rear)		//Queue contains only one element
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
				cout<<"\nQueue is empty";
				return NULL;
			}
		}
};

class Tree
{
		Node * root;
	public:
		Tree()
		{
			root = NULL;
		}
		
		
		void create()
		{
			root = rec_create();
		}
		
		Node* rec_create()
		{
			int x;
			cout<<"\nEnter data or -1 to stop : ";
			cin>>x;
			if(x == -1)
			{
				return NULL;
			}
			Node * p;
			p = new Node(x);
			cout<<"Enter left of "<<x;
			p->left = rec_create();
			cout<<"Enter right of "<<x;
			p->right = rec_create();
			return p;
		}
			
		void nonrec_BST()		//non-recursive function for breadth first search traversal 
		{
			cout<<"\n\nBreadth First Traversal\n";
			
			Queue Q1, Q2;
			Node * T = root;
			
			cout<<"  "<<T->data;
			Q1.enqueue(T);
			
			while(1)
			{
				while(!Q1.empty())			//i.e. while(Q1 is not empty)
				{
					T = Q1.dequeue();
					if(T->left != NULL)
					{
						cout<<"  "<<T->left->data;
						Q2.enqueue(T->left);
					}
					if(T->right != NULL)
					{
						cout<<"  "<<T->right->data;
						Q2.enqueue(T->right);
					}
				}
				Q1 = Q2;			//assign Q2 to Q2
				Q2.init();			//make Q2 empty
				if(Q1.empty())		//if Q1 is still empty after assignment, STOP process
				{
					break;
				}
			}
		}
};

int main()
{
	Tree T;
	T.create();
	T.nonrec_BST();
	
	return 0;
}
