// TBT non-recursive inorder traversal (using loop only not even stack) :-

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
				T->child = 0;
				T->left = father->left;
				T->right = father;
				father->left = T;
				father->lbit = 1;
			}
			if(child == 1)
			{
				T->child = 1;
				T->right = father->right;
				T->left = father;
				father->right = T;
				father->rbit = 1;
			}
			cout<<"Enter left of "<<x;
			create_rec(T, 0);
			cout<<"Enter right of "<<x;
			create_rec(T, 1);
		}
		
		void Inorder_nonrec()
		{
			cout<<"\n\nNon-rec Inorder Traversal of TBT\n";
			
			TBTNode * T = root->left;
			//take T on first node of inorder traversal
			while(T->lbit == 1)
			{
				T = T->left;
			}
			//T is on first node of inorder traversal
			while(T != root)
			{
				cout<<"  "<<T->data;
				T = Inorder_succ(T);
			}
		}
		
		TBTNode* Inorder_succ(TBTNode * T)
		{
			//if T has threaded link in right, then that threaded link directly referes to inorder successor of T
			if(T->rbit == 0)
			{
				return T->right;
			}
			//T has normal link in right
			T = T->right;
			//find first node of inorder successor in right subtree (i.e. find leftmost node if present)
			while(T->lbit == 1)
			{
				T = T->left;
			}
			return T;
		}
};

int main()
{
	TBT obj;
	obj.create();
	obj.Inorder_nonrec();
	
	return 0;
}


