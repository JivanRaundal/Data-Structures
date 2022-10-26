// Q.8] AVL Tree

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left, *right;
		Node(int x)
		{
			data = x;
			left = right = NULL;
		}
};

class AVL
{
		Node * root;
	public:
		AVL()
		{
			root = NULL;
		}
		
		Node* rotateleft(Node * T)
		{
			Node * P = T->right;
			T->right = P->left;
			P->left = T;
			return P;
		}
		
		Node* rotateright(Node * T)
		{
			Node * P = T->left;
			T->left = P->right;
			P->right = T;
			return P;
		}
		
		Node* leftright(Node * T)
		{
			T->left = rotateleft(T->left);
			T = rotateright(T);
			return T;
		}
		
		Node* rightleft(Node * T)
		{
			T->right = rotateright(T->right);
			T = rotateleft(T);
			return T;
		}
		
		void create()
		{
			int x;
			cout<<"\nKeep entering data or -1 to stop\n";
			while(1)
			{
				cin>>x;
				if(x == -1)
				{
					break;
				}
				root = insert(root, x);		
			}
		}
		
		Node* insert(Node * T,int x)
		{
			if(T == NULL)
			{
				T = new Node(x);
				return T;
			}
			if(x < T->data)
			{
				T->left = insert(T->left, x);
				if(BF(T) == 2)
				{
					if(x < T->left->data)
						T = rotateright(T);
					else
						T = leftright(T);
				}
				return T;
			}
			if(x > T->data)
			{
				T->right = insert(T->right, x);
				if(BF(T) == -2)
				{
					if(x > T->right->data)
						T = rotateleft(T);
					else
						T = rightleft(T);
				}
				return T;
			}
			else
			{
				cout<<"duplicate data\n";
				return T;
			}
		}
		
		int height(Node * T)
		{
			if(T==NULL || (T->left==NULL && T->right==NULL))
			{
				return 0;
			}
			int lh=0,rh=0;
			if(T->left != NULL)
			{
				lh = 1 + height(T->left);
			}
			if(T->right != NULL)
			{
				rh = 1 + height(T->right);
			}
			return lh > rh ? lh : rh;
		}
		
		int BF(Node * T)
		{
			int lh=0,rh=0;
			if(T->left != NULL)
			{
				lh = 1 + height(T->left);
			}
			if(T->right != NULL)
			{
				rh = 1 + height(T->right);
			}
			return (lh - rh);
		}
		
		void show()				
		{
			cout<<"\n\nInorder Traversal of BST\n";
			this->Inorder(root);
		}
		
		void Inorder(Node * T)
		{
			if(T == NULL)
				return;
			Inorder(T->left);
			cout<<"  "<<T->data;
			Inorder(T->right);
		}
		
		Node* getroot()
		{
			return root;
		}
};

int main()
{
	AVL T;
	T.create();
	T.show();
	cout<<"\n\nBalance Factor of root node = "<<T.BF(T.getroot());
	
	return 0;
}





