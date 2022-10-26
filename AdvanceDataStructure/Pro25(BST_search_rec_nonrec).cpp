// BST search() functions:-
//recursive & non-recursive search() function

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
		
		Node* search_nonrec(int x)
		{
			Node * T = root;
			while(T != NULL)
			{
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
					return T;	//return 1;
				}
			}
			//T is NULL, means data not found
			return NULL; 		//return 0;
		}
		
		void search()
		{
			int x;
			cout<<"\n\nEnter data to be search : ";
			cin>>x;
			Node * p = search_rec(root, x);
			if(p != NULL)
			{
				cout<<"Data Found";
			}
			else
			{
				cout<<"Data Not Found";
			}
		}
		
		Node* search_rec(Node * T,int x)
		{
			if(T == NULL)
			{
				return NULL;				//return 0; if returntype is int
			}
			if(x < T->data)
			{
				return search_rec(T->left, x);
			}
			else if(x > T->data)
			{
				return search_rec(T->right, x);
			}
			else			//(x == T->data)
			{
				return T;					//return 1; if returntype is int
			}
		}
		
		//OR0
		/*
		int search_rec(Node * T,int x)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->data == x)
			{
				return 1;
			}
			else if(x < T->data)
			{
				return search_rec(T->left, x);
			}
			else
			{
				return search_rec(T->right, x);
			}
		}
		*/
};

int main()
{
	BST T;
	T.create();
	T.show();
	int x;
	cout<<"\n\nEnter data to be search : ";
	cin>>x;
	Node * p = T.search_nonrec(x);		//non_rec search()
	if(p != NULL)					//means, P has address of valid node & not null	
	{
		cout<<"Data Found";
	}
	else
	{
		cout<<"Data Not Found";
	}
	T.search();					//helper for search_rec()
	
	return 0;
}





