// Q.7] create simple binary tree, search data in tree & find the leaf node of that data.

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
				
		void create();			  	  //helper
		Node* rec_create();
		
		void rec_traversal();			//helper
		void Inorder(Node*);
		
		Node* search_rec(Node*,int);
		Node* findLeaf(Node*);
		void leafNode();		//helper
};

void Tree::create()
{
	root = rec_create();
}

Node* Tree::rec_create()
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

void Tree::rec_traversal()
{
	cout<<"\n\nRecursive Inorder Traversal\n";
	Inorder(root);
}

void Tree::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	cout<<"  "<<T->data;
	Inorder(T->right);
}

Node* Tree::search_rec(Node* T,int x)		
{
	if(T == NULL)
	{
		return NULL;
	}
	if(T->data == x)
	{
		return T;
	}
	else
	{
		Node * P = NULL;
		P = search_rec(T->left, x);
		if(P == NULL)
		{
			P = search_rec(T->right, x);
		}
		return P;
	}
}

Node* Tree::findLeaf(Node * T)
{
	while(T->left!=NULL || T->right!=NULL)
	{
		if(T->left != NULL)
		{
			T = T->left;
		}
		else if(T->right != NULL)
		{
			T = T->right;
		}
	}
	return T;
}

void Tree::leafNode()
{
	Node *T, *P;
	int x;	
	cout<<"\n\nEnter data to search : ";
	cin>>x;
	T = search_rec(root, x);
	if(T == NULL)
	{
		cout<<"data not found";
		return;
	}
	//data found
	P = findLeaf(T);
	cout<<"\n\nLeaf Node of "<<T->data<<" = "<<P->data;
}

int main()
{
	Tree T;
	T.create();
	T.rec_traversal();
	T.leafNode();
		
	return 0;
}





