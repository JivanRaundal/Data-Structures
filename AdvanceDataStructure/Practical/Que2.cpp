// Q.2] create BST & delete data from BST.

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
		Node * root;
	public:
		BST()
		{
			root = NULL;
		}
		
		void create()
		{
			int x;
			cout<<"\nKeep entering data or -1 to stop\n";
			while(1)
			{
				cin>>x;
				if(x == -1)
				{
					break;
				}
				root = insert_rec(root, x);		
			}
		}
		
		Node* insert_rec(Node* T,int x)				//recursive
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
			this->Inorder(root);
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
				return;
			Inorder(T->left);
			cout<<"  "<<T->data;
			Inorder(T->right);
		}
		
		void delete_node()
		{
			int x;
			cout<<"\n\nEnter data to be deleted : ";
			cin>>x;
			root = delete_rec(root, x);
		}
		
		Node* delete_rec(Node * T,int x)
		{
			//search for the node to be deleted
			if(T == NULL)
			{
				cout<<"\nData Not Found";
				return NULL;
			}
			if(x < T->data)
			{
				T->left = delete_rec(T->left, x);
				return T;
			}
			else if(x > T->data)
			{
				T->right = delete_rec(T->right, x);
				return T;
			}
			//data found now delete data
			if(T->left==NULL && T->right==NULL)
			{
				delete T;
				return NULL;
			}
			if(T->left == NULL)		
			{
				Node * p = T->right;
				delete T;
				return p;
			}
			if(T->right == NULL)		
			{
				Node * p = T->left;
				delete T;
				return p;
			}
			Node * p;
			p = findmin_rec(T->right);			
			T->data = p->data;					
			T->right = delete_rec(T->right, p->data);			
			return T;
		}
		
		Node* findmin_rec(Node * T)
		{
			if(T == NULL)
			{
				return NULL;
			}
			if(T->left == NULL)
			{
				return T;
			}
			return findmin_rec(T->left);
		}
};

int main()
{
	BST T;
	T.create();
	T.show();
	
	T.delete_node();
	T.show();
	T.delete_node();
	T.show();
	T.delete_node();
	T.show();
	T.delete_node();
	T.show();
	
	return 0;
}





