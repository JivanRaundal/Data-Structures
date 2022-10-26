// Tree Mirror

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
		Node(int data)
		{
			this->data = data;
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
		
		void create();
		Node* create_rec();
		void show();
		void inorder(Node*);
		void mirror_img();
		void mirror(Node*);
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
	cout<<"\n\nInorder Traversal\n";
	inorder(root);
}

void Tree::inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	inorder(T->left);
	cout<<"  "<<T->data;
	inorder(T->right);
}

void Tree::mirror_img()
{
	cout<<"\n\nMirroring Tree";
	mirror(root);
}

void Tree::mirror(Node * T)			//using postorder traversal logic for mirroring binary tree
{
	if(T == NULL)
	{
		return;
	}
	mirror(T->left);
	mirror(T->right);
	//swapping left & right pointers during backtracking
	Node * temp;
	temp = T->left;
	T->left = T->right;
	T->right = temp;
}

int main()
{
	Tree T;
	T.create();
	cout<<"\nBefore Mirroring Tree\n";
	T.show();
	
	T.mirror_img();
	cout<<"\n\nAfter Mirroring Tree";
	T.show();
	
	return 0;
}


