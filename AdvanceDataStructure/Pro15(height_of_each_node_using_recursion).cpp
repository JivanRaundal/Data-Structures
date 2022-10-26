// Finding height of each node using recursion (using postorder traversal)
// we will use postorder here

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
		
		void height_of_node()
		{
			cout<<"\n\nHeight of each node according to postorder traversal";
			int h = postorder_height(root);
			cout<<"\n\nHeight of root node = "<<h;
		}
		
		int postorder_height(Node * T)
		{
			if(T == NULL)
			{
				return -1;
			}
			else
			{
				int left_h = postorder_height(T->left);
				int right_h = postorder_height(T->right);
				int max_h = (left_h > right_h ? left_h : right_h) + 1;		//find max height from left & right subtree & add 1 to it
				cout<<"\nHeight of node "<<T->data<<" = "<<max_h;
				return max_h;
			}
		}
};

int main()
{
	Tree T;
	T.create();
	T.height_of_node();
	
	return 0;
}
