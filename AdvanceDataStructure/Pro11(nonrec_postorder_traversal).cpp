// Non-recursive Postorder Traversal :-

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

class StackNode
{
	public:
		Node* address;
		int flag;
		StackNode()
		{
			address = NULL;
			flag = 0;
		}	
};

class Stack
{
	private:
		StackNode data[MAX];			//array of objects
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
		void push(StackNode st)
		{
			if(!full())
			{
				top++;
				data[top] = st;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		StackNode pop()
		{
			StackNode st;
			if(!empty())
			{
				st = data[top];
				top--;
				return st;
			}
			else
			{
				cout<<"\nStack is empty";
				return st;
			}
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
			p->left = rec_create();
			cout<<"Enter right of "<<x;
			p->right = rec_create();
			return p;
		}
		
		void nonrec_postorder()
		{
			cout<<"\n\nNon-recursive postorder traversal\n";
			
			Stack S;
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
				
				if(st.flag == 0)			//means left subtree is visited, now go to right subtree
				{
					st.flag = 1;			//update the flag
					S.push(st);				//push st back in stack
					T = T->right;
					
					while(T != NULL)
					{
						st.address = T;
						st.flag = 0;
						S.push(st);
						T = T->left;
					}
				}
				else if(st.flag == 1)		//means, both left & right subtree visited
				{
					cout<<"  "<<T->data;				//now visit the Node
				}
			}
		}
};

int main()
{
	Tree T;
	T.create();
	T.nonrec_postorder();
	
	return 0;
}
