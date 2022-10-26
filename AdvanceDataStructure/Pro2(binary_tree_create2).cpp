// rec_create() function using STOP string to stop scanning and preorder traversal for Normal Binary Tree.

#include<iostream>
#include<stdlib.h>
#include<string.h>
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
		Node* root;
	public:
		Tree()
		{
			root = NULL;
		}
		
		void create()			//helper
		{
			root = rec_create();
		}
		Node* rec_create()
		{
			char str[10];
			cout<<"\nEnter data or STOP to stop : ";
			cin>>str;
			if(strcmp(str, "STOP") == 0)
			{
				return NULL;
			}
			Node* p;
			p = new Node(atoi(str));			//converting String into int using atoi() function
			cout<<"Enter left of "<<atoi(str);
			p->left = rec_create();
			cout<<"Enter right of "<<atoi(str);
			p->right = rec_create();
			return p;
		}
		
		void show()				//helper
		{
			//Preorder traversal of tree
			cout<<"\n\npreorder traversal of binary tree\n";
			preorder(root);
		}
		void preorder(Node* p)
		{
			if(p == NULL)
			{
				return;
			}
			cout<<"  "<<p->data;			//visit root
			preorder(p->left);				//visit left subtree
			preorder(p->right);				//visit right subtree
		}
};

int main()
{
	Tree T;
	T.create();
	T.show();
	
	return 0;
}
