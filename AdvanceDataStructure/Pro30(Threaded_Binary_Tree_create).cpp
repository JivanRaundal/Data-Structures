// Threaded Binary Tree (TBT) :- 
// create() & inorder()
//NOTE:- for child => 0 means left child & 1 means right child
//       for lbit & rbit => 0 means threaded link & 1 means normal link

#include<iostream>
using namespace std;

class TBTNode
{
	public:
		int data;
		TBTNode *left, *right;
		int lbit, rbit;
		int child;
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
			//NOTE:- root always contains address of dummy node in TBT
			root = new TBTNode(-1);
			root->left = root;
			root->right = root;
		}
		
		void create()
		{
			create_rec(root, 0);		//0 is passed to mention that new node is created at the left of root(dummy node)
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
			TBTNode * T;
			T = new TBTNode(x);
			if(child == 0)					//T is left child of father
			{
				//update child node T
				T->child = 0;
				T->left = father->left;
				T->right = father;
				//update father node
				father->left = T;
				father->lbit = 1;			//normal link
			}
			else if(child == 1)
			{
				//update child node T
				T->child = 1;
				T->right = father->right;
				T->left = father;
				//update father node
				father->right = T;
				father->rbit = 1;			//normal link
			}
			//child node is linked properly, now let's create left & right of T
			cout<<"Enter left of "<<x;
			create_rec(T, 0);
			cout<<"Enter right of "<<x;
			create_rec(T, 1);
 		}
 		
 		void iterative_inorder()
 		{
 			cout<<"\n\nInorder Traversal of TBT\n";
 			TBTNode * T = root;
 			while(T->lbit != 0)			//while left link is not a threaded link
 			{
 				T = T->left;	
			}
			while(T != root)			
			{
				cout<<"  "<<T->data;
				if(T->rbit == 0)			//if right link is threaded link it will get print in next iteration
				{
					T = T->right;
				}
				else					//if right link is normal link, go to it's leftmost node and repeat
				{
					T = T->right;
					while(T->lbit != 0)			//if left of T is not a threaded link
					{
						T = T->left;
					}
				}
			}
		}
};

int main()
{
	TBT obj;
	obj.create();
	obj.iterative_inorder();
	
	return 0;
}
