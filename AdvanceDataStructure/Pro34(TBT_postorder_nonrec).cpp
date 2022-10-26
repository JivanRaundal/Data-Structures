// TBT non-recursive postorder traversal (using loop only not even stack) :-

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
		
		void Postorder_nonrec()
		{
			cout<<"\n\nNon-rec Postorder Traversal of TBT\n";
			
			TBTNode * T = root->left;
			//take T on first node of Postorder traversal
			while(T->lbit==1 || T->rbit==1)
			{
				if(T->lbit == 1)			//priority is given to left, if no child on left, go to right
				{
					T = T->left;
				}
				else if(T->rbit == 1)
				{
					T = T->right;
				}
			}
			//now, T is on first node of postorder traversal
			while(T != root)
			{
				cout<<"  "<<T->data;
				T = Postorder_succ(T);
			}
		}
		
		TBTNode* Postorder_succ(TBTNode * T)
		{
			TBTNode * P;
			//if T is right child of it's parent, then it's parent is postorder successor
			if(T->child == 1)
			{
				P = T;
				while(P->lbit == 1)
				{
					P = P->left;
				}
				P = P->left;
				//now, P is on parent of T
				return P;
			}
			//T is left child of it's parent
			//find parent of T, if parent has right subtree then find 1st node of postorder traversal in right subtree & return it
			//If parent does not have right subtree, then parent will be postorder successor of T, return parent
			P = T;
			while(P->rbit == 1)
			{
				P = P->right;
			}
			P = P->right;
			//now, P is on parent of T
			if(P->rbit == 0)		//P has no right child / right subtree
			{
				return P;
			}
			//parent of T i.e. P now has right subtree, find 1st node of post-succ in right subtree
			P = P->right;			//taken P on root node of right subtree
			while(P->lbit==1 || P->rbit==1)
			{
				if(P->lbit == 1)
				{
					P = P->left;
				}
				else if(P->rbit == 1)
				{
					P = P->right;
				}
			}
			return P;
		}
};

int main()
{
	TBT obj;
	obj.create();
	obj.Postorder_nonrec();
	
	return 0;
}


