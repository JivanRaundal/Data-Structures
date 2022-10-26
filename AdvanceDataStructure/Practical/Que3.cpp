// Q.3] Non-Recursive Inorder Traversal of Binary Search Tree :-

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

class BST
{
		Node* root;
	public:
		BST()
		{
			root = NULL;
		}
		
		void create()
		{
			int x;
			cout<<"\nKeep entering data or -1 to stop\n";
			while(1)
			{
				cin>>x;
				if(x == -1)
				{
					break;
				}
				root = insert_rec(root, x);		
			}
		}
		
		Node* insert_rec(Node* T,int x)				//recursive
		{
			if(T == NULL)
			{
				T = new Node(x);
				return T;
			}
			if(x < T->data)
			{
				T->left = insert_rec(T->left, x);
				return T;
			}
			else if(x > T->data)
			{
				T->right = insert_rec(T->right, x);
				return T;
			}
			else
			{
				cout<<"Duplicate record\n";
				return T;
			}
		}
		
		void nonrec_inorder()				//Non-recursive inorder function
		{
			cout<<"\n\nNon-recursive Inorder Traversal\n";
			
			Stack S;
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
};

int main()
{
	BST T;
	T.create();
	T.nonrec_inorder();
	
	return 0;
}



