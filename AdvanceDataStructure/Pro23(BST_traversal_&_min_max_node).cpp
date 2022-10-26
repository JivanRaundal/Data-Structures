// BST Traversals & min, max nodes in BST :-
// Recursive Preorder, Inorder & Postorder.
// NOTE:- Minumum node is at extreme left of BST 
//        Maximum node is at extreme Right of BST

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
				//insert(x);					//non-rec insert() function call
				root = insert_rec(root, x);		//recursive insert() function call
			}
		}
		
		void insert(int x)						//non-recurive
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
				P = T;
				if(x < T->data)
				{
					T = T->left;
				}
				else if(x > T->data)
				{
					T = T->right;
				}	
				else			//(x == T->data)
				{
					return;
				}
			}
			//after loop, P is on correct node
			if(x < P->data)
			{
				P->left = new Node(x);
			}
			else
			{
				P->right = new Node(x);
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
			cout<<"\n\nPreorder Traversal of BST\n";
			this->Preorder(root);
			cout<<"\n\nInorder Traversal of BST\n";
			this->Inorder(root);
			cout<<"\n\nPostorder Traversal of BST\n";
			this->Postorder(root);
		}
		
		void Preorder(Node * T)
		{
			if(T == NULL)
				return;
			cout<<"  "<<T->data;
			Preorder(T->left);
			Preorder(T->right);
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
				return;
			Inorder(T->left);
			cout<<"  "<<T->data;
			Inorder(T->right);
		}
		
		void Postorder(Node * T)
		{
			if(T == NULL)
				return;
			Postorder(T->left);
			Postorder(T->right);
			cout<<"  "<<T->data;
		}
		
		void min_max_node()
		{
			Node * T;
			T = findmin_nonrec();
			cout<<"\n\nnon-recursive min node = "<<T->data;
			T = findmax_nonrec();
			cout<<"\nnon-recursive max node = "<<T->data;
			
			T = findmin_rec(root);
			cout<<"\nrecursive min node = "<<T->data;
			T = findmax_rec(root);
			cout<<"\nrecursive max node = "<<T->data;
		}
		
		Node* findmin_nonrec()			//will return node with min data (i.e. extreme left side node)
		{
			if(root == NULL)
			{
				return NULL;
			}
			Node *  T = root;
			while(T->left != NULL)
			{
				T = T->left;
			}
			return T;
		}
		
		Node* findmax_nonrec()			//will return node with max data (i.e. extreme right side node)		
		{
			if(root == NULL)
			{
				return NULL;
			}
			Node * T = root;
			while(T->right != NULL)
			{
				T = T->right;
			}
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
		
		Node* findmax_rec(Node * T)
		{
			if(T == NULL)
			{
				return NULL;
			}
			if(T->right == NULL)
			{
				return T;
			}
			return findmax_rec(T->right);
		}
};

int main()
{
	BST T;
	T.create();
	T.show();
	T.min_max_node();
	
	return 0;
}





