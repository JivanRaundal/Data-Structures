// Delete data/node in Threaded binary tree

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
			root = new TBTNode(-1);			//for dummy node
			root->left = root;
			root->right = root;
		}
		
		void create()
		{
			create_rec(root->left, 0);			//0 to mention that first node will be left child of root/dummy node
		}
		
		void create_rec(TBTNode * father, int child)
		{
			int x;
			cout<<"\nEnter data or -1 to stop : ";
			cin>>x;
			if(x == -1)
			{
				return;
			}
			TBTNode * T;
			T = new TBTNode(x);
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
			cout<<"\n\nNon-rec inorder of TBT\n";
			
			TBTNode * T = root->left;
			while(T->lbit == 1)
			{
				T = T->left;
			}
			while(T != root)
			{
				cout<<"  "<<T->data;
				T = in_successor(T);
			}
		}
		
		TBTNode* in_successor(TBTNode * T)
		{
			if(T->rbit == 0)
			{
				return T->right;
			}
			T = T->right;
			while(T->lbit == 1)
			{
				T = T->left;
			}
			return T;
		}
		
		//recursive search function for TBT
		TBTNode* search_rec(TBTNode * T,int x)
		{
			//Note, as their is no NULL value in TBT, hence this condition is checked first to compare leaf node data
			if(T->data == x)
			{
				return T;
			}
			if(T->lbit==0 && T->rbit==0)
			{
				return NULL;
			}
			TBTNode * P = NULL;
			if(T->lbit == 1)
			{
				P = search_rec(T->left, x);
			}
			if(T->rbit==1 && P==NULL)
			{
				P = search_rec(T->right, x);	
			}
			return P;
		}
		
		//function to find leaf node of given TBT node
		TBTNode* findLeaf(TBTNode * T)
		{
			while(T->lbit==1 || T->rbit==1)
			{
				if(T->lbit == 1)
				{
					T = T->left;
				}
				else if(T->rbit == 1)
				{
					T = T->right;
				}
			}
			return T;
		}
		
		//delete data from TBT
		void delete_data()
		{
			TBTNode *T, *P;
			int x;
			int done = 0;		//flag
			cout<<"\n\nEnter data to be deleted : ";
			cin>>x;
			//search x in TBT
			T = search_rec(root->left, x);
			if(T == NULL)
			{
				cout<<"Data Not Found";
				return;
			}
			//data found
			//now, find the lead node of T and replace data of T with it's leaf node & delete that leaf node from TBT
			P = findLeaf(T);
			T->data = P->data;
			delete_rec(root, root->left, P, done);		//done is working as flag & is pass by reference
		}
		
		void delete_rec(TBTNode * father,TBTNode * T,TBTNode * P,int& done)		//done is by reference
		{
			if(T == P)
			{
				if(T->child == 0)			//it is left child of it's father, hence maintain father's left link
				{
					father->left = T->left;
					father->lbit = 0;
				}
				if(T->child == 1)			//it is right child of it's father, hence maintain father's right link
				{
					father->right = T->right;
					father->rbit = 0;
				}
				delete T;
				done = 1;
				return;
			}
			if(T->lbit==1 && done==0)
			{
				delete_rec(T, T->left, P, done);
			}
			if(T->rbit==1 && done==0)
			{
				delete_rec(T, T->right, P, done);
			}
			return;
		}
};

int main()
{
	TBT obj;
	obj.create();
	obj.Inorder_nonrec();
	//deleting data
	obj.delete_data();
	obj.Inorder_nonrec();
	obj.delete_data();
	obj.Inorder_nonrec();
	obj.delete_data();
	obj.Inorder_nonrec();
	obj.delete_data();
	obj.Inorder_nonrec();
	obj.delete_data();
	obj.Inorder_nonrec();
	obj.delete_data();
	obj.Inorder_nonrec();
	
	return 0;
}
