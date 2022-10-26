// Converting Normal Binary Tree To Threaded Binary Tree

#include<iostream>
#include<vector>
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
			root->left = create_rec();
			
			cout<<"\n\nNormal BT Preorder\n";
			Preorder(root->left);
		}
		
		TBTNode* create_rec()				//normal create function for normal binary tree
		{
			int x;
			cout<<"\nEnter data or -1 to stop : ";
			cin>>x;
			if(x == -1)
			{
				return NULL;
			}
			TBTNode * T;
			T = new TBTNode(x);
			cout<<"Enter left of "<<x;
			T->left = create_rec();
			cout<<"Enter right of "<<x;
			T->right = create_rec();
			return T;
		}
	
		void Preorder(TBTNode * T)
		{
			if(T)
			{
				cout<<"  "<<T->data;
				Preorder(T->left);
				Preorder(T->right);	
			}	
		}
		
		//function to traverse array in inorder sequence & store nodes in array & update their child
		void inorderSequence(TBTNode * father,TBTNode* T,vector<TBTNode*>& arr,int child)		
		{
			if(T == NULL)
			{
				return;
			}
			inorderSequence(T, T->left, arr, 0);
			arr.push_back(T);
			T->child = child;
			if(child == 0)
			{
				father->lbit = 1;
			}
			if(child == 1)
			{
				father->rbit = 1;
			}
			inorderSequence(T, T->right, arr, 1);
		}
		
		void convert_to_TBT()
		{
			vector<TBTNode*> inSeq;			//STL vector
			//find inorder sequence of given binary tree & store it in array using Inorder Sequence
			inorderSequence(root, root->left, inSeq, 0);		//0 is to mention that first node is left child of dummy node
			//Now, inSeq vector/array has all nodes of BT in Inorder Sequence
			
			//for leftmost node in tree, it's left thread refers to dummy node (root node)
			TBTNode * T;
			T = inSeq[0];
			T->left = root;
			if(T->right == NULL)
			{
				T->right = inSeq[1];
			}
			//for last rightmost node, it's right thread refers to dummy node
			int n = inSeq.size();
			T = inSeq[n-1];
			T->right = root;
			if(T->left == NULL)
			{
				T->left = inSeq[n-2];
			}
			//for remaining nodes
			for(int i=1; i<=n-2; i++)
			{
				T = inSeq[i];
				if(T->left == NULL)
				{
					T->left = inSeq[i-1];
				}
				if(T->right == NULL)
				{
					T->right = inSeq[i+1];
				}
			}
			
		}
		
		void Preorder_nonrec()				//non-rec/iterative preorder
		{
			cout<<"\n\nNon-rec Preorder Of TBT\n";
			
			TBTNode * T = root->left;
			while(T != root)
			{
				cout<<"  "<<T->data;
				T = preorder_succ(T);				//preorder_succ() fun will return preorder successor of T
			}
		}
		
		TBTNode* preorder_succ(TBTNode * T)
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
};

int main()
{
	TBT obj;
	obj.create();
	obj.convert_to_TBT();
	obj.Preorder_nonrec();
	
	return 0;
}


