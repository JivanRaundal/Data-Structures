// delete() function for simple/Normal Binary Tree :-
// IMP & complicated to understand (think of stackframes)

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
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
		Node* root;			//private by default
	public:
		Tree()
		{
			root = NULL;
		}
		
		void create()		//will work as a helper for rec_create() function 
		{
			root = rec_create();
		}
		Node* rec_create()					//recursive create function
		{
			int x;
			cout<<"\nEnter data or -1 to STOP : ";
			cin>>x;
			if(x == -1)
			{
				return NULL;
			}
			Node* p;
			p = new Node(x);
			cout<<"Enter left of "<<x;
			p->left  = rec_create();				//will create left subtree
			cout<<"Enter right of "<<x;
			p->right = rec_create();				//will create right subtree
			return p;
		}
		
		void show()				//helper
		{
			cout<<"\n\npreorder traversal of binary tree\n";
			preorder(root);
		}
		void preorder(Node* p)
		{
			if(p == NULL)
			{
				return;
			}
			cout<<"  "<<p->data;		
			preorder(p->left);			
			preorder(p->right);			
		}
		
		//following all functions are define for deleting the data from Normal Binary Tree
		//search function for simple binary tree
		Node* search_rec(Node * T,int x)
		{
			if(T == NULL)
			{
				return NULL;
			}
			if(T->data == x)			//data found
			{
				return T;
			}
			else
			{
				Node * P = NULL;
				P = search_rec(T->left, x);			//search in left subtree
				if(P == NULL)						//if not found in left, then only go to right
				{
					P = search_rec(T->right, x);
				}
				return P;
			}
		}
		
		//this function will return leaf node of the node which is passed as a parameter in T
		Node* findLeaf(Node * T)
		{
			while(T->left!=NULL || T->right!=NULL)
			{
				if(T->left != NULL)
				{
					T = T->left;
				}
				else if(T->right != NULL)
				{
					T = T->right;
				}
			}
			return T;			//returning leaf node 
		}
		
		//deleteData() function
		void deleteData()
		{
			int x;
			cout<<"\n\nEnter data to be deleted : ";
			cin>>x;
			Node *P, *T;
			int done = 0;						//working as a flag for delete_rec() function
			T = search_rec(root, x);			//search data in tree
			if(T == NULL)
			{
				cout<<"\nData Not Found";
				return;
			}
			//data found
			P = findLeaf(T);					//this function will return the one of the leaf node of T
			T->data = P->data;					//replace data of T with P
			root = delete_rec(root, P, done);	//delete that leaf node from tree
		}
		
		//delete_rec() function for simple binary tree
		Node* delete_rec(Node* T,Node* P,int & done)				//NOTE:- done is passed as a reference
		{
			if(T == P)
			{
				delete T;
				done = 1;
				return NULL;
			}
			if(T->left!=NULL && done==0)
			{
				T->left = delete_rec(T->left, P, done);
			}
			if(T->right!=NULL && done==0)
			{
				T->right = delete_rec(T->right, P, done);
			}
			return T;
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	T.deleteData();
	T.show();
	T.deleteData();
	T.show();
	T.deleteData();
	T.show();
	
	return 0;
}


