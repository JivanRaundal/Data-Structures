//Q.4] 

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
		void inorder_traversal(Node * T,Node ** Inorder);		
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

int ind = 0;				//global variable
void Tree::show()
{	
	Node* Inorder[20];						//array of nodes
	inorder_traversal(root, Inorder);		//will store all nodes of tree in Inorder sequence inside the Inorder array
	
	cout<<"\n\nInorder traversal of tree\n";
	for(int i=0; i<ind; i++)
	{
		cout<<"  "<<Inorder[i]->data;
	}
}

void Tree::inorder_traversal(Node * T,Node ** Inorder)
{
	if(T == NULL)
	{
		return;
	}
	else
	{
		inorder_traversal(T->left, Inorder);		
		Inorder[ind++] = T;
		inorder_traversal(T->right, Inorder);				
	}
}

int main()
{
	Tree T;
	T.create();
	T.show();
	
	return 0;
}

