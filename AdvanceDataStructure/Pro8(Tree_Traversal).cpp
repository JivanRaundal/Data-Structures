/* Normal Binary Tree Code
-recursive create()
-rec preorder()
-rec inorder()
-rec postorder()
-nonrec preorder()
-nonrec inorder()
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
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
	private:
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
			char str[10];
			cout<<"\nEnter data or STOP to stop : ";
			cin>>str;
			if(strcmp(str,"STOP") == 0)
			{
				return NULL;
			}
			Node * p;
			p = new Node(atoi(str));
			cout<<"Enter left of "<<str;
			p->left = rec_create(); 
			cout<<"Enter right of "<<str;
			p->right = rec_create();
			return p;
		}
		
		void show()
		{
			cout<<"\n\nRecursive Preorder Traversal\n";
			Preorder(root);
			cout<<"\n\nRecursive Inorder Traversal\n";
			Inorder(root);
			cout<<"\n\nRecursive Postorder Traversal\n";
			Postorder(root);
		}
		
		void Preorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				cout<<"  "<<T->data;
				Preorder(T->left);
				Preorder(T->right);
			}
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				Inorder(T->left);
				cout<<"  "<<T->data;
				Inorder(T->right);
			}
		}
		
		void Postorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				Postorder(T->left);
				Postorder(T->right);
				cout<<"  "<<T->data;
			}
		}
		
		void nonrec_preorder()
		{
			cout<<"\n\nNon Recursive Preorder Traversal\n";
			Stack S;
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
		
		void nonrec_inorder()
		{
			cout<<"\n\nNon Recursive Inorder Traversal\n";
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
	Tree T;
	T.create();
	T.show();
	T.nonrec_preorder();
	T.nonrec_inorder();
	
	return 0;
}



