// recursive fuction to find height of binary tree

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
		
		void height()
		{
			cout<<"\n\nHeight of binary tree = "<<rec_height(root);	
		}
		
		int rec_height(Node * T)
		{
			if(T == NULL)
			{
				return 0;				//OR return -1; (-1 to ensure that tree is empty)
			}
			if(T->left==NULL && T->right==NULL)
			{
				return 0;
			}
			int lh = rec_height(T->left);			//will give height of left subtree
			int rh = rec_height(T->right);			//will give height of right subtree
			//now find max(lh, rh) and add 1 to it & return it
			if(lh > rh)				//left height is max
				return lh + 1;
			else
				return rh + 1;		//right height is max or both are equal
		}
		
		
		//OR
		/*
		int rec_height(Node * T)
		{
			if(T == NULL)
			{
				return -1;
			}
			int lh = rec_height(T->left);
			int rh = rec_height(T->right);
			if(lh > rh)
				return lh + 1;
			else
				return rh + 1;
		}
		*/
};

int main()
{
	Tree T;
	T.create();
	T.show();
	T.height();
	
	return 0;	
}
