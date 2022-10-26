// Print longest path from root to leaf in binary tree :-

#include<iostream>
#include<vector>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		Node(int x)
		{
			data = x;
			left = right = NULL;
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
		
		void create();
		Node* create_rec();
		void show();
		void preorder(Node* T);
		int height(Node * T);
		void longestPathTree();
		void longestPath(Node* T);
};

void Tree::create()
{
	root = create_rec();
}

Node* Tree::create_rec()
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
	p->left = create_rec();
	cout<<"Enter right of "<<x;
	p->right = create_rec();
	return p;
}

void Tree::show()
{
	cout<<"\n\nPreorder of Binary Tree\n";
	preorder(root);
}

void Tree::preorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	cout<<"  "<<T->data;
	preorder(T->left);
	preorder(T->right);
}

void Tree::longestPathTree()
{
	cout<<"\n\nLongest Path in Tree\n";
	longestPath(root);
}

int Tree::height(Node * T)
{
	if(T==NULL)			
	{
		return -1; 
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	int lh = height(T->left);
	int rh = height(T->right);
	return (lh > rh) ? (lh+1) : (rh+1);
}

//function to find longest path in binary tree
void Tree::longestPath(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	cout<<T->data<<"  ";
	if(height(T->left) > height(T->right))
	{
		longestPath(T->left);
	}
	else
	{
		longestPath(T->right);
	}
}


int main()
{
	Tree T;
	T.create();
	T.show();
	T.longestPathTree();
	
	return 0;
}

