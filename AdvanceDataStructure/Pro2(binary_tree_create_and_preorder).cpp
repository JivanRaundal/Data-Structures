// Recursive rec_create() function and preorder traversal for Normal Binary Tree.

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
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
		Node* root;			//private by default
	public:
		Tree()
		{
			root = NULL;
		}
		
		void create()		//will work as a helper for rec_create() function 
		{
			root = rec_create();
		}
		Node* rec_create()					//recursive create function
		{
			int x;
			cout<<"\nEnter data or -1 to STOP : ";
			cin>>x;
			if(x == -1)
			{
				return NULL;
			}
			Node* p;
			p = new Node(x);
			p->left  = rec_create();				//will create left subtree
			p->right = rec_create();				//will create right subtree
			return p;
		}
		
		void show()				//helper
		{
			//Preorder traversal of tree
			cout<<"\n\npreorder traversal of binary tree\n";
			preorder(root);
		}
		void preorder(Node* p)
		{
			if(p == NULL)
			{
				return;
			}
			cout<<"  "<<p->data;		//visit root
			preorder(p->left);			//visit left subtree
			preorder(p->right);			//visit right subtree
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	
	return 0;
}


