// Normal Binary Tree All In One :-

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
		
		//function declarations
		
		void create();			  	  //helper
		Node* rec_create();
		
		//recursive traversal functions
		void rec_traversal();			//helper
		void Preorder(Node*);
		void Inorder(Node*);
		void Postorder(Node*);
		
		//nonrec traversal functions
		void nonrec_preorder();
		void nonrec_inorder();
		void nonrec_postorder();
		
		//BFS traversal (level by level)
		void BFT();						//for BFT traversal
		
		//printing height of node by BFT logic & recursion logic
		void height();			//helper
		void preorder_height(Node*);
		int BFT_height(Node*);			//for returning height of node
		int rec_height(Node*);         //height of node using recursive function
		
		//recursive count functions
		void countNodes();				//helper
		int countTotal(Node*);			//will count total nodes in tree
		int count0(Node*);				//will count leaf nodes
		int count1(Node*);				//will count nodes with degree 1
		int count2(Node*);				//will count nodes with degree 2
		
		//rec search() fun to search node in tree
		int search(int);				//helper
		int rec_search(Node*, int);
		
		//deletdata() for deleting data from node
		Node* search_rec(Node*, int);		//will return node if data found
		Node* findLeaf(Node*);				//will return leaf node of mentioned node
		void deleteData();
		Node* delete_rec(Node*,Node*,int&);		//rec delete() fun for deleting data (Node:- 3rd para is pass by ref)
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

void Tree::BFT()
{
	cout<<"\n\nBreadth First Traversal\n";
	
	Queue Q1, Q2;
	Node * T = root;
	cout<<"  "<<T->data;
	Q1.enqueue(T);
	while(1)
	{
		while(!Q1.empty())
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
		Q1 = Q2;
		Q2.init();
		if(Q1.empty())
		{
			break;
		}
	}
}

void Tree::height()
{
	cout<<"\n\nHeight of root node using BFT logic = "<<BFT_height(root);
	cout<<"\n\nHeight of each node in tree using BFT logic";
	preorder_height(root);			//NOTE:- BFT_height() is called from preorder height, can also use in/post orde
	cout<<"\n\nHeight of tree using recursion = "<<rec_height(root);
}

void Tree::preorder_height(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	cout<<"\nHeight of node "<<T->data<<" = "<<BFT_height(T);
	preorder_height(T->left);
	preorder_height(T->right);
}

int Tree::BFT_height(Node * p)
{
	Queue Q1, Q2;
	int count = 0 ;
	Node * T = p;
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

int Tree::rec_height(Node * T)
{
	if(T == NULL)
	{
		return 0;			//or return -1;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	int lh = rec_height(T->left);
	int rh = rec_height(T->right);
	if(lh > rh)
		return lh + 1;
	else
		return rh + 1;
}

//OR rec_height()
/*
int Tree::rec_height(Node * T)
{
	if(T == NULL)
	{
		return -1;
	}
	int lh = rec_create(T->left);
	int rh = rec_create(T->right);
	if(lh > rh)
		return lh + 1;
	else
		return rh + 1;
}
*/

void Tree::countNodes()
{
	cout<<"\n\nTotal nodes in tree = "<<countTotal(root);
	cout<<"\n\nLeaf nodes in tree  = "<<count0(root);
	cout<<"\n\nNodes with degree 1 = "<<count1(root);
	cout<<"\n\nNodes with degree 2 = "<<count2(root);
}

int Tree::countTotal(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	int lc = countTotal(T->left);
	int rc = countTotal(T->right);
	return lc + rc + 1;
}

int Tree::count0(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)				//leaf node
	{
		return 1;
	}
	return count0(T->left) + count0(T->right);
}

int Tree::count1(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	if(T->left == NULL)
	{
		return 1 + count1(T->right);
	}
	if(T->right == NULL)
	{
		return 1 + count1(T->left);
	}
	return count1(T->left) + count1(T->right);
}

int Tree::count2(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	if(T->left == NULL)
	{
		return count2(T->right);
	}
	if(T->right == NULL)
	{
		return count2(T->left);
	}
	return count2(T->left) + count2(T->right) + 1;
}

int Tree::search(int x)
{
	return rec_search(root, x);
}

int Tree::rec_search(Node * T,int x)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->data == x)
	{
		return 1;
	}
	int res1 = rec_search(T->left, x);
	if(res1 == 1)				//means, data fount in left subtree, no need to check right subtree
		return res1;	
	int res2 = rec_search(T->right, x);		//if not found in left subtree, return the result of right subtree
	return res2;
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

Node* Tree::findLeaf(Node * T)			//will return leaf node of tree
{
	while(T->left!=NULL || T->right!=NULL)
	{
		if(T->left != NULL)
		{
			T = T->left;
		}
		else if(T->right != NULL)
		{
			T = T->right;
		}
	}
	return T;
}

void Tree::deleteData()
{
	Node *P, *T;
	int x, done=0;	
	cout<<"\n\nEnter data to be deleted : ";
	cin>>x;
	T = search_rec(root, x);
	if(T == NULL)
	{
		cout<<"data not found";
		return;
	}
	//data found
	P = findLeaf(T);
	T->data = P->data;			//replacing data of T with P
	root = delete_rec(root, P, done);			//delete leaf node pointed by P
}

Node* Tree::delete_rec(Node* T,Node* P,int & done)			//3rd para is passed by reference
{
	if(T == P)
	{
		delete T;
		done = 1;
		return NULL;
	}
	if(T->left!=NULL && done==0)
	{
		T->left = delete_rec(T->left, P, done);
	}
	if(T->right!=NULL && done==0)
	{
		T->right = delete_rec(T->right, P, done);
	}
	return T;
}

int main()
{
	Tree T;
	T.create();
	T.rec_traversal();
	T.nonrec_preorder();
	T.nonrec_inorder();
	T.nonrec_postorder();
	T.BFT();
	T.height();
	T.countNodes();
	int x;
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	if(T.search(x))
	{
		cout<<"FOUND";
	}
	else
	{
		cout<<"NOT FOUND";
	}
	
	T.deleteData();
	T.rec_traversal();
	T.deleteData();
	T.rec_traversal();
	T.deleteData();
	T.rec_traversal();
	
	return 0;
}


