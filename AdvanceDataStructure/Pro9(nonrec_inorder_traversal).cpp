// Non-Recursive Inorder Traversal of Binary Tree :-

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

class Stack
{
		Node* data[MAX];
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
		void push(Node * p)
		{
			if(!full())
			{
				top++;
				data[top] = p;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		Node* pop()
		{
			if(!empty())
			{
				Node * p;
				p = data[top];
				top--;
				return p;
			}
			else
			{
				cout<<"\nStack is empty";
				return NULL;
			}
		}
};

class Tree
{
		Node* root;
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
		
		void nonrec_inorder()				//Non-recursive preorder function
		{
			cout<<"\n\nNon-recursive Inorder Traversal\n";
			
			Node * T = NULL;
			Stack S;
			T = root;
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
};

int main()
{
	Tree T;
	T.create();
	T.nonrec_inorder();
	
	return 0;
}



