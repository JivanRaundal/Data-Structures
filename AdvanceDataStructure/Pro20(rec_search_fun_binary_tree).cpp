// recursive search() function 

#include<iostream>
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
		
		void show()
		{
			cout<<"\n\nPreorder Traversal of Tree\n";
			preorder(root);
		}
		
		void preorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			cout<<"  "<<T->data;
			preorder(T->left);
			preorder(T->right);
		}
		
		int search(int x)
		{
			return rec_search(root, x);
		}
		
		int rec_search(Node * T,int x)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->data == x)			//data found
			{
				return 1;
			}
			int res1 = rec_search(T->left, x);
			if(res1 == 1)			//means data found in left subtree, return 1 & no need to check right subtree
			{
				return 1;
			}
			//if data not found in left subtree, then check right subtree and return it's result
			int res2 = rec_search(T->right, x);
			return res2;
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	int x;
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	if(T.search(x))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not Found";
	}
	
	return 0;	
}
