// Binary Search Tree (BST) 
// Non-recursive insert() function

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

class BST
{
	private:
		Node * root;
	public:
		BST()
		{
			root = NULL;	
		}
		
		void create()
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
				//insert(x);				`	//non-recursive insert() fun call
				root = insert_rec(root, x);		//recursive insert() fun call
			}
		}
		
		void insert(int x)			//non-recursive insert() function
		{
			if(root == NULL)
			{
				root = new Node(x);
				return;
			}
			Node * T = root;
			Node * P = NULL;
			while(T != NULL)
			{
				P = T;			//this is bcz, after loop ends, T becomes NULL & we want node T was refering just before becoming NULL
				if(x < T->data)
				{
					T = T->left;
				}
				else if(x > T->data)
				{
					T = T->right;
				}
				else
				{
					//means, (x == T->data), so it is duplicate value & duplicate values are not allowed in BST, hence return
					return;
				}
			}
			//after loop ends T is NULL & P is on correct Node
			if(x < P->data)
			{
				P->left = new Node(x);
			}
			else			//(x > P->data)
			{
				P->right = new Node(x);
			}
		}
		
		Node* insert_rec(Node* T,int x)				//Recursive insert() 
		{
			if(T == NULL)
			{
				T = new Node(x);
				return T;
			}
			if(x < T->data)
			{
				T->left = insert_rec(T->left, x);
				return T;
			}
			else if(x > T->data)
			{
				T->right = insert_rec(T->right, x);
				return T;
			}
			else
			{
				cout<<"Duplicate record\n";
				return T;
			}
		}
		
		void show()
		{
			cout<<"\n\nInorder Traversal of BST\n";
			Inorder(root);
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			Inorder(T->left);
			cout<<"  "<<T->data;
			Inorder(T->right);
		}
};

int main()
{
	BST T;
	T.create();
	T.show();
	
	return 0;
}

