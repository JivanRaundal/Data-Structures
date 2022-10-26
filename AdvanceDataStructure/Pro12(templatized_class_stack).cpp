// Non-recursive Preorder, Inorder & Postorder Traversals :

#include<iostream>
#define MAX 20
using namespace std;

class Node;
class StackNode;

//Templatized class Stack
template<class T>
class Stack
{
		T data[MAX];			//T is templatized variable
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
		void push(T x)
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
		T pop()
		{
			T x;
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
		
		void nonrec_preorder()
		{
			cout<<"\n\nPreorder Traversal\n";
			
			//here, stack will store Node* type values
			Stack<Node*> S;			//using templatized class Stack
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
			cout<<"\n\nInorder Traversal\n";
			
			//here, stack will store Node* type values
			Stack<Node*> S;			//using templatized class Stack
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
		
		void nonrec_postorder()
		{
			cout<<"\n\nPostorder Traversal\n";
			
			//here, stack will store StackNode type values
			Stack<StackNode> S;		//using templatized class Stack
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
};

int main()
{
	Tree T;
	T.create();
	T.nonrec_preorder();
	T.nonrec_inorder();
	T.nonrec_postorder();
	
	return 0;
}


