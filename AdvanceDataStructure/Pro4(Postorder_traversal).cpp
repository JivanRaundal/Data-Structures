// Binary Tree and it's Traversals :-

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
		
		void create()
		{
			root = rec_create();
		}
		
		Node* rec_create()
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
		
		void show()
		{
			cout<<"\n\nPreorder Traversal\n";
			Preorder(root);
			
			cout<<"\n\nInorder Traversal\n";
			Inorder(root);
			
			cout<<"\n\nPostorder Traversal\n";
			Postorder(root);
		}
		
		void Preorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{									
				cout<<"  "<<T->data;			//visit root
				Preorder(T->left);				//visit left subtree
				Preorder(T->right);				//visit right subtree
			}
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				Inorder(T->left);				//visit left subtree
				cout<<"  "<<T->data;			//visit root
				Inorder(T->right);				//visit right subtree
			}
		}
		
		void Postorder(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				Postorder(T->left);				//visit left subtree
				Postorder(T->right);			//visit right subtree
				cout<<"  "<<T->data;			//visit root
			}
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	
	return 0;
}


