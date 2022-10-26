// recursive count() functions
// countTotal() => will count total nodes in binary tree
// count0()     => will count leaf nodes in tree  (node with no child)
// count1()     => will count nodes with degree 1 (node with one child)
// count2()     => will count nodes with degree 2 (node with two child)

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
		
		void countNodes()
		{
			cout<<"\n\nTotal Nodes = "<<countTotal(root);
			cout<<"\n\nLeaf Nodes  = "<<count0(root);
			cout<<"\n\nNodes with one child = "<<count1(root);
			cout<<"\n\nNodes with two child = "<<count2(root);
		}
		
		int countTotal(Node *  T)			//this fun is used to count total nodes
		{
			if(T == NULL)
			{
				return 0;
			}
			else
			{
				int lc = countTotal(T->left);		//will return total nodes in left subtree
				int rc = countTotal(T->right);		//will return total nodes in right subtree
				return lc + rc + 1;					// +1 for the root node itself
				 
				//return 1 + count(T->left) + count(T->right);			//shortcut
			}
		}
		
		int count0(Node * T)				//this fun is used to count leaf nodes (with degree 0)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->left==NULL && T->right==NULL)
			{
				return 1;
			}
			int lc = count0(T->left);
			int rc = count0(T->right);
			return lc + rc;					//NOTE:- no need of +1 here
		}
		
		
		int count1(Node * T)
		{
			if(T == NULL)
			{
				return 0;
			}
			int lc = count1(T->left);
			int rc = count1(T->right);
			if((T->left==NULL && T->right!=NULL) || (T->left!=NULL && T->right==NULL))
			{
				return lc + rc + 1;
			}
			else
			{
				return lc + rc;
			}
		}
		
		int count2(Node * T)
		{
			if(T == NULL)
			{
				return 0;
			}
			int lc = count2(T->left);
			int rc = count2(T->right);
			if(T->left!=NULL && T->right!=NULL)
			{
				return lc + rc + 1;
			}
			else
			{
				return lc + rc;
			}
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	T.countNodes();
	
	return 0;	
}
