// TBT non-recursive preorder traversal (using loop only not even stack) :-

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
		
		void Preorder_nonrec()				//non-rec/iterative preorder
		{
			cout<<"\n\nNon-rec Preorder Of TBT\n";
			//take T to first node of traversal
			
			TBTNode * T = root->left;
			while(T != root)
			{
				cout<<"  "<<T->data;
				T = preorder_succ(T);				//preorder_succ() fun will return preorder successor of T
			}
		}
		
		TBTNode* preorder_succ(TBTNode * T)
		{
			//If T has valid left link, then it's preorder successor will be T->left
			if(T->lbit == 1)
			{
				return T->left;
			}
			//if left link is not valid, but it has valid link in right, then T->right will be pre-successor of T
			if(T->rbit == 1)
			{
				return T->right;
			}
			//if it has threaded link in both sides, find it's preorder successor using below condition
			while(T->rbit==0 && T!=root)
			{
				T = T->right;
			}
			T = T->right;
			return T;
		}
		
		//optimize preorder_succ() function
		/*TBTNode* preorder_succ(TBTNode * T)
		{
			if(T->lbit == 1)
			{
				return T->left;
			}
			while(T->rbit==0 && T!=root)
			{
				T = T->right;
			}
			T = T->right;
			return T;
		}
		*/
};

int main()
{
	TBT obj;
	obj.create();
	obj.Preorder_nonrec();
	
	return 0;
}


