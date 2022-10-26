// TBT recursive traversals :-

#include<iostream>
using namespace std;

class TBTNode
{
	public:
		int data;
		TBTNode *left, *right;
		int lbit, rbit;
		int child;
		
		TBTNode()
		{
			data = 0;
			left = right = NULL;
			lbit = rbit = 0;
			child = -1;
		}
		TBTNode(int x)
		{
			data = x;
			left = right = NULL;
			lbit = rbit = 0;
			child = -1;
		}
};

class TBT
{
	private:
		TBTNode * root;
	public:
		TBT()
		{
			root = new TBTNode(-1);
			root->left = root;
			root->right = root;
		}
		
		void create()
		{
			create_rec(root, 0);
		}
		
		void create_rec(TBTNode * father,int child)
		{
			int x;
			cout<<"\nEnter data or -1 to stop : ";
			cin>>x;
			if(x == -1)
			{
				return;
			}
			TBTNode * T = new TBTNode(x);
			if(child == 0)
			{
				//update child node T
				T->child = 0;
				T->left = father->left;
				T->right = father;
				//update father
				father->left = T;
				father->lbit = 1;
			}
			if(child == 1)
			{
				//update child node T
				T->child = 1;
				T->right = father->right;
				T->left = father;
				//update father
				father->right = T;
				father->rbit = 1;	
			}
			//create left & right of T
			cout<<"Enter left of "<<x;
			create_rec(T, 0);
			cout<<"Enter right of "<<x;
			create_rec(T, 1);
		}
		
		void show()
		{
			cout<<"\n\nRec Preorder Traversal\n";
			Preorder_rec(root->left);
			cout<<"\n\nRec Inorder Traversal\n";
			Inorder_rec(root->left);
			cout<<"\n\nRec Postorder traversal\n";
			Postorder_rec(root->left);
		}
		
		void Preorder_rec(TBTNode * T)
		{
			if(T == root)
			{
				return;
			}
			cout<<"  "<<T->data;
			if(T->lbit == 1)
			{
				Preorder_rec(T->left);
			}
			if(T->rbit == 1)
			{
				Preorder_rec(T->right);
			}
		}
		
		void Inorder_rec(TBTNode * T)
		{
			if(T == root)
			{
				return;
			}
			if(T->lbit == 1)
			{
				Inorder_rec(T->left);
			}
			cout<<"  "<<T->data;
			if(T->rbit == 1)
			{
				Inorder_rec(T->right);
			}
		}
		
		void Postorder_rec(TBTNode * T)
		{
			if(T == root)
			{
				return;
			}
			if(T->lbit == 1)
			{
				Postorder_rec(T->left);
			}
			if(T->rbit == 1)
			{
				Postorder_rec(T->right);
			}
			cout<<"  "<<T->data;
		}
};

int main()
{
	TBT obj;
	obj.create();
	obj.show();
	
	return 0;
}
