// Diameter of Binary Tree (width of binary tree) :-
//NOTE :- Diameter of tree (sometimes called width of tree) is the number of nodes on longest path between two leaves/end nodes in tree.

#include<iostream>
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
		void diameterOfTree();
		int diameter(Node* T);
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

void Tree::diameterOfTree()
{
	cout<<"\n\nDiameter of Tree = "<<diameter(root);
}

int Tree::height(Node * T)
{
	if(T==NULL)			//NOTE:- do not use this condition -> if(T==NULL || (T->left==NULL && T->right==NULL))
	{
		return 0;
	}
	int lh = height(T->left);
	int rh = height(T->right);
	return (lh > rh) ? (lh+1) : (rh+1);
}

//function to find diameter of binary tree
int Tree::diameter(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	//find height of left & right subtrees'
	int lh = height(T->left);
	int rh = height(T->right);
	//find diameter of left & right subtrees
	int ldiameter = diameter(T->left);
	int rdiameter = diameter(T->right);
	//new, return the max(lh+rh+1, ldiameter, rdiameter)  i.e. return the max of three
	return max(lh+rh+1, max(ldiameter, rdiameter));
}

int max(int a,int b)
{
	return (a > b) ? a : b;
}

int main()
{
	Tree T;
	T.create();
	T.show();
	T.diameterOfTree();
	
	return 0;
}

