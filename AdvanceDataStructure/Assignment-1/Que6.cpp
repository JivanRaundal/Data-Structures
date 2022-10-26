// Q.6] create a simple tree. Using BFT search given data in tree.

#include<iostream>
#define MAX 20
using namespace std;

class Node;

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
		void enqueue(Node* x)
		{
			if(!full())
			{
				if(front == -1)
				{
					front++;	//front=0;
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
			Node* x = NULL;
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
				return x;
			}
			else
			{
				cout<<"\nQueue is empty";
				return x;
			}
		}
};

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

class Tree
{
	private:
		Node * root;
	public:
		Tree()
		{
			root = NULL;
		}
				
		void create();			  	  //helper
		Node* rec_create();
		
		void rec_traversal();			//helper
		void Inorder(Node*);
		
		Node* search_BFT(int);		//search by BFT logic (non-rec)
};

void Tree::create()
{
	root = rec_create();
}

Node* Tree::rec_create()
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

void Tree::rec_traversal()
{
	cout<<"\n\nRecursive Inorder Traversal\n";
	Inorder(root);
}

void Tree::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	cout<<"  "<<T->data;
	Inorder(T->right);
}

Node* Tree::search_BFT(int x)		//searching by BFT logic
{
	Queue Q;
	Node * T = root;
	Q.enqueue(T);
	while(!Q.empty())
	{
		T = Q.dequeue();
		if(T->data == x)
		{
			return T;			//found
		}
		//enqueue child nodes of T in Queue
		if(T->left != NULL)
		{
			Q.enqueue(T->left);
		}
		if(T->right != NULL)
		{
			Q.enqueue(T->right);
		}
	}
	return NULL;			//if not found
}

int main()
{
	Tree T;
	T.create();
	T.rec_traversal();
	int x;
	cout<<"\n\nEnter data to be search : ";
	cin>>x;
	Node * P = T.search_BFT(x);
	if(P == NULL)
	{
		cout<<"\nNot Found";
	}
	else
	{
		cout<<"\nFound";
	}
		
	return 0;
}





