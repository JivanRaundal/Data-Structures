// Normal Binary Tree Preorder & Inorder Traversal

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
		
		void create();				//helper
		Node* rec_create();			//recursive create function
		void show();				//helper
		void Preorder(Node * T);	//preorder traversal of tree
		void Inorder(Node * T);		//Inorder traversal of tree
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

void Tree::show()
{
	cout<<"\n\nPreorder traversal of tree\n";
	Preorder(root);
	
	cout<<"\n\nInorder traversal of tree\n";
	Inorder(root);
}

void Tree::Preorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	else
	{
		cout<<"  "<<T->data;				//visit root
		Preorder(T->left);					//visit left subtree
		Preorder(T->right);					//visit right subtree
	}
}

void Tree::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	else
	{
		Inorder(T->left);					//visit left subtree
		cout<<"  "<<T->data;				//visit root
		Inorder(T->right);					//visit right subtree
	}
}

int main()
{
	Tree T;
	T.create();
	T.show();
	
	return 0;
}

