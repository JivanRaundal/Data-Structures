// Finding Height of each node using recursive Pre/In/Post order traversal & BFT logic :-
// NOTE:- we can use any Pre/In/Post order traversal.

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
		void init()
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
		void enqueue(Node * x)
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
		Node* dequeue()
		{
			Node * x = NULL;
			if(!empty())
			{
				x = data[front];
				if(front == rear)
				{
					front = rear = -1;
				}
				else
				{
					front++;
				}
			}
			else
			{
				cout<<"\nQueue is empty";
			}
			return x;
		}
};

class Tree
{
	private:
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
			p->left  = rec_create();
			cout<<"Enter right of "<<x;
			p->right = rec_create();
			return p;
		}
		
		void printHeight()
		{
			cout<<"\n\nPrinting height of each node using preorder traversal & BFT logic\n";
			preorder(root);
		}
		
		void preorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			cout<<"\nHeight of "<<T->data<<" = "<<height_BFT(T);
			preorder(T->left);
			preorder(T->right);
		}
		
		int height_BFT(Node * p)
		{
			Node * T = p;
			Queue Q1, Q2;
			int count = 0;
			Q1.enqueue(T);
			while(1)
			{
				while(!Q1.empty())
				{
					T = Q1.dequeue();
					if(T->left != NULL)
					{
						Q2.enqueue(T->left);
					}
					if(T->right != NULL)
					{
						Q2.enqueue(T->right);
					}
				}
				Q1 = Q2;
				Q2.init();
				if(Q1.empty())
				{
					break;
				}
				count++;
			}
			return count;
		}
};

int main()
{
	Tree T;
	T.create();
	T.printHeight();
	
	return 0;	
}
