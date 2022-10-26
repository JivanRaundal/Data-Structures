// BST delete_node() & delete_rec() function :-
// NOTE:- refer to notebook theory for delete_rec() function.

/* NOTE:- sequence for the delete_rec() function (think of all possibilities sequentially)
1) search for the data to be deleted
2) check for the leaf node
3) check for the node with one child
4) check for the node with two children
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
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
			char str[10];
			int x;
			cout<<"\nKeep entering data or STOP to stop\n";
			while(1)
			{
				cin>>str;
				if(strcmp(str,"STOP") == 0)
				{
					break;
				}
				x = atoi(str);
				root = insert_rec(root, x);		//recursive insert() function call
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
		
		void show()				//helper
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
			//---------------Data to be deleted is Found------------------
			//check if node containing data to be deleted is Leaf Node or not
			if(T->left==NULL && T->right==NULL)
			{
				delete T;
				return NULL;
			}
			//if above condition is false, means node has either 1 child or 2 child
			//check if node has single right child
			if(T->left == NULL)			//means right child is present
			{
				Node * p = T->right;
				delete T;
				return p;
			}
			//if above condition is also false, then
			//check if node has single left child
			if(T->right == NULL)		//means left child is present
			{
				Node * p = T->left;
				delete T;
				return p;
			}
			//if above all conditions are false, means node has 2 child
			Node * p;
			p = findmin_rec(T->right);			//find smallest node in right subtree of node to be deleted
			T->data = p->data;					//replce data of node to be deleted with smallest data in right subtree of T
			T->right = delete_rec(T->right, p->data);			//delete smallest node from right subtree 
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





