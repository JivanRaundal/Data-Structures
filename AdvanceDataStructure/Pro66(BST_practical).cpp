// BST

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

class BST
{
		Node * root;
	public:
		BST()
		{
			root = NULL;
		}
		
		void create();
		Node* insert(Node*, int);
		void show();
		void inorder(Node*);
		void count_nodes();
		int countTotal(Node*);
		int count0(Node*);
		int count1(Node*);
		int count2(Node*);
};

void BST::create()
{
	int x;
	cout<<"\nKeep entering data or -1 to stop\n";
	while(1)
	{
		cin>>x;
		if(x == -1)
		{
			return;
		}
		root = insert(root, x);
	}
}

Node* BST::insert(Node * T,int x)
{
	if(T == NULL)
	{
		T = new Node(x);
		return T;
	}
	if(x < T->data)
	{
		T->left = insert(T->left, x);
		return T;
	}
	else if(x > T->data)
	{
		T->right = insert(T->right, x);
		return T;
	}
	else
	{
		cout<<"duplicate data\n";
		return T;
	}
}

void BST::show()
{
	cout<<"\nInorder Traversal\n";
	inorder(root);
}

void BST::inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	inorder(T->left);
	cout<<"  "<<T->data;
	inorder(T->right);
}

void BST::count_nodes()
{
	cout<<"\n\nTotal Nodes = "<<countTotal(root);
	cout<<"\nNodes with degree 0 = "<<count0(root);
	cout<<"\nNodes with degree 1 = "<<count1(root);
	cout<<"\nNodes with degree 2 = "<<count2(root);
}

int BST::countTotal(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	int lc = countTotal(T->left);
	int rc = countTotal(T->right);
	return 1 + lc + rc;
}

int BST::count0(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 1;
	}
	return count0(T->left) + count0(T->right);
}

int BST::count1(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right!=NULL)
	{
		return 1 + count1(T->right);
	}
	if(T->right==NULL && T->left!=NULL)
	{
		return 1 + count1(T->left);
	}
	return count1(T->left) + count1(T->right);
}

int BST::count2(Node * T)
{
	if(T == NULL || (T->left==NULL && T->right==NULL))
	{
		return 0;
	}
	if(T->left==NULL && T->right!=NULL)
	{
		return count2(T->right);
	}
	if(T->right==NULL && T->left!=NULL)
	{
		return count2(T->left);
	}
	return 1 + count2(T->left) + count2(T->right);
}

int main()
{
	BST T;
	T.create();
	T.show();
	T.count_nodes();
	
	return 0;
}







