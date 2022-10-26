// Q.5] Normal Binary Tree All In One :-

#include<iostream>
#define MAX 20
using namespace std;

//forward declaration
class Node;
class StackNode;

template<class mytype>
class Stack
{
	private:
		mytype data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top == -1)
				return 1;
			return 0;
		}
		void push(mytype x)
		{
			if(!full())
			{
				top++;
				data[top] = x;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		mytype pop()
		{
			mytype x;
			if(!empty())
			{
				x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStack is empty";
				return x;
			}
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

//tree code starts
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

//class StackNode for postorder traversal without recursion, i.e. using stack
class StackNode
{
	public:
		Node * address;
		int flag;
		StackNode()
		{
			address = NULL;
			flag = 0;
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
		void Preorder(Node*);
		void Inorder(Node*);
		void Postorder(Node*);
		
		void nonrec_preorder();
		void nonrec_inorder();
		void nonrec_postorder();
		
		void countNodes();				//helper
		int count_rec(Node*);			//will count total nodes in tree
		void count_nonrec();
		void search(int);
		Node* search_rec(Node*, int);
		Node* search_nonrec(int);
};

//function definations

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
	cout<<"\n\nRecursive Preorder Traversal\n";
	Preorder(root);
	cout<<"\n\nRecursive Inorder Traversal\n";
	Inorder(root);
	cout<<"\n\nRecursive Postorder Traversal\n";
	Postorder(root);
}

void Tree::Preorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	cout<<"  "<<T->data;
	Preorder(T->left);
	Preorder(T->right);
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

void Tree::Postorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Postorder(T->left);
	Postorder(T->right);
	cout<<"  "<<T->data;
}

void Tree::nonrec_preorder()
{
	cout<<"\n\nNon-recursive Preorder Traversal\n";
	
	Stack<Node*> S;
	Node * T = root;
	while(T != NULL)
	{
		cout<<"  "<<T->data;
		S.push(T);
		T = T->left;
	}
	while(!S.empty())
	{
		T = S.pop();
		T = T->right;
		while(T != NULL)
		{
			cout<<"  "<<T->data;
			S.push(T);
			T = T->left;
		}
	}
}

void Tree::nonrec_inorder()
{
	cout<<"\n\nNon-recursive Inorder Traversal\n";
	
	Stack<Node*> S;
	Node * T = root;
	while(T != NULL)
	{
		S.push(T);
		T = T->left;
	}
	while(!S.empty())
	{
		T = S.pop();
		cout<<"  "<<T->data;
		T = T->right;
		while(T != NULL)
		{
			S.push(T);
			T = T->left;
		}
	}
}

void Tree::nonrec_postorder()
{
	cout<<"\n\nNon-recursive Postorder Traversal\n";
	
	Stack<StackNode> S;
	StackNode st;
	Node * T = root;
	while(T != NULL)
	{
		st.address = T;
		st.flag = 0;
		S.push(st);
		T = T->left;
	}
	while(!S.empty())
	{
		st = S.pop();
		T = st.address;
		if(st.flag == 0)
		{
			st.flag = 1;
			S.push(st);
			T = T->right;
			while(T != NULL)
			{
				st.address = T;
				st.flag = 0;
				S.push(st);
				T = T->left;
			}
		}
		else if(st.flag == 1)
		{
			cout<<"  "<<T->data;
		}
	}
}

void Tree::countNodes()
{
	cout<<"\n\nTotal nodes in tree = "<<count_rec(root);
}

int Tree::count_rec(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	int lc = count_rec(T->left);
	int rc = count_rec(T->right);
	return lc + rc + 1;
}

void Tree::count_nonrec()				//nonrecursive count function
{
	Queue Q;
	Node * T = root;
	int count=0;
	Q.enqueue(T);
	//cout<<"  "<<T->data;
	while(!Q.empty())		//while Q is not empty
	{
		T = Q.dequeue();
		count++;
		if(T->left != NULL)
		{
			//cout<<"  "<<T->left->data;
			Q.enqueue(T->left);
		}
		if(T->right != NULL)
		{
			//cout<<"  "<<T->right->data;
			Q.enqueue(T->right);
		}
	}
	cout<<"\n\nTotal Nodes = "<<count;
}

void Tree::search(int x)
{
	Node * p = search_rec(root, x);
	if(p == NULL)
	{
		cout<<"\nNot Found";
	}
	else
	{
		cout<<"\nFound";
	}
}

Node* Tree::search_rec(Node * T,int x)
{
	if(T == NULL)
	{
		return NULL;
	}
	if(T->data == x)
	{
		return T;
	}
	else
	{
		Node * P = NULL;
		P = search_rec(T->left, x);
		if(P == NULL)			//if node found in left, search in right
		{
			P = search_rec(T->right, x);
		}
		return P;
	}
}

Node* Tree::search_nonrec(int x)			//non-recursove search (searching by BFT logic)
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
		if(T->left != NULL)
		{
			Q.enqueue(T->left);
		}
		if(T->right != NULL)
		{
			Q.enqueue(T->right);
		}
	}
	return NULL;			//not found
}

int main()
{
	Tree T;
	T.create();
	T.rec_traversal();
	T.nonrec_preorder();
	T.nonrec_inorder();
	T.nonrec_postorder();
	T.countNodes();
	T.count_nonrec();
	int x;
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	T.search(x);
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	Node * P = T.search_nonrec(x);
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


