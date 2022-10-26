// Preparation For AVL Tree :-

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

class AVL
{
	private:
		Node * root;
	public:
		AVL()
		{
			root = NULL;
		}
		
		void create();
		Node* insert(Node* T, int x);
		void show();
		void Inorder(Node* T);
		void heightOfNode();
		int height(Node* T);
		int balanceFactor(Node * T);
};

void AVL::create()
{
	int x;
	cout<<"\nKeep entering data or enter -1 to stop\n";
	while(1)
	{
		cin>>x;
		if(x == -1)
		{
			break;
		}
		root = insert(root, x);		//NOTE- insert() will insert only one node at a time
	}
}

Node* AVL::insert(Node * T,int x)			//BST insert()
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
		//duplicate record
		return T;
	}
}

void AVL::show()
{
	cout<<"\n\nInorder Traversal of Tree\n";
	Inorder(root);
}

void AVL::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	cout<<T->data<<"  height = "<<height(T)<<"  balance factor = "<<balanceFactor(T)<<"\n";
	Inorder(T->right);
}

void AVL::heightOfNode()
{
	cout<<"\n\nHeight of root node = "<<height(root);
	cout<<"\nBalance Factor of root node = "<<balanceFactor(root);
}

int AVL::height(Node * T)
{
	if(T==NULL || (T->left==NULL && T->right==NULL))
	{
		return 0;
	}
	int lh=0,rh=0;
	if(T->left != NULL)
	{
		lh = 1 + height(T->left);
	}
	if(T->right != NULL)
	{
		rh = 1 + height(T->right);
	}
	//return the max(lh, rh)
	if(lh > rh)
	{
		return lh;
	}
	return rh;
}

int AVL::balanceFactor(Node * T)
{
	int lh=0,rh=0;
	if(T->left != NULL)
	{
		lh = 1 + height(T->left);
	}
	if(T->right != NULL)
	{
		rh = 1 + height(T->right);
	}
	//Balance Factor = (left height - right height)
	return (lh - rh);
}

int main()
{
	AVL T;
	T.create();
	T.show();
	T.heightOfNode();
	
	return 0;
}


