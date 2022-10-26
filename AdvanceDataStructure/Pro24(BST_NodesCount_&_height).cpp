// BST height() & count() for counting nodes :-

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
		
		void count()
		{
			cout<<"\n\nTotal Nodes = "<<countTotal(root);
			cout<<"\nLeaf Nodes = "<<count0(root);
			cout<<"\nNodes with degree 1 = "<<count1(root);
			cout<<"\nNodes with degree 2 = "<<count2(root);
		}
		
		int countTotal(Node * T)
		{
			if(T == NULL)
			{
				return 0;
			}
			int lc = countTotal(T->left);
			int rc = countTotal(T->right);
			return lc + rc + 1;
		}
		
		int count0(Node * T)
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
		
		int count1(Node * T)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->left==NULL && T->right==NULL)
			{
				return 0;
			}
			if(T->left == NULL)
			{
				return 1 + count1(T->right);
			}
			if(T->right == NULL)
			{
				return 1 + count1(T->left);
			}
			return count1(T->left) + count1(T->right);			
		}
		
		int count2(Node * T)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->left==NULL && T->right==NULL)
			{
				return 0;
			}
			if(T->left == NULL)
			{
				return count2(T->right);
			}
			if(T->right == NULL)
			{
				return count2(T->left);
			}
			return count2(T->left) + count2(T->right) + 1;			
		}
		
		void height()
		{
			cout<<"\n\nHeight of BST = "<<rec_height(root);
		}
		
		int rec_height(Node * T)
		{
			if(T == NULL)
			{
				return 0;				//return -1;
			}
			if(T->left==NULL && T->right==NULL)
			{
				return 0;
			}
			int lh = rec_height(T->left);
			int rh = rec_height(T->right);
			if(lh > rh)
			{
				return lh + 1;
			}
			else
			{
				return rh + 1;
			}
		}
};

int main()
{
	BST T;
	T.create();
	T.show();
	T.height();
	T.count();
	
	return 0;
}





