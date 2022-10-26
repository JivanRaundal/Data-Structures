// BST deleteAll() function to delete all the nodes:

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

class BST
{
		Node * root;
	public:
		BST()
		{
			root = NULL;
		} 
		
		void create()
		{
			int x;
			cout<<"\n\nKeep entering data or -1 to stop\n";
			while(true)
			{
				cin>>x;
				if(x == -1)
				{
					break;
				}
				insert(x);						//non-rec insert()
			}
		}
		
		void insert(int x)
		{
			if(root == NULL)
			{
				root = new Node(x);
				return;
			}
			Node * T = root;
			Node * P = NULL;
			while(T != NULL)
			{
				P = T;
				if(x < T->data)
				{
					T = T->left;
				}
				else if(x > T->data)
				{
					T = T->right;
				}
				else			//(x == T->data)
				{
					cout<<"Duplicate data\n";
					return;						//duplicate data not allowed hence return
				}
			}
			//after loop p is on valid node
			if(x < P->data)
			{
				P->left = new Node(x);
			}
			else
			{
				P->right = new Node(x);
			}
		}
		
		void show()
		{
			cout<<"\n\nInorder Traversal\n";
			Inorder(root);
		}
		
		void Inorder(Node * T)
		{
			if(T != NULL)
			{
				Inorder(T->left);
				cout<<"  "<<T->data;
				Inorder(T->right);
			}
		}
		
		void deleteAll()
		{
			//root = delete_rec(root);
			delete_rec(root);
			root = NULL;
		}
		
		//deleting all nodes using Postorder logic (Note- don't use pre/in order)
		/*Node* delete_rec(Node * T)
		{
			if(T == NULL)
			{
				return NULL;
			}
			else
			{
				delete_rec(T->left);
				delete_rec(T->right);
				delete T;
				return NULL;
			}
		}
		*/
		
		//OR
		void delete_rec(Node * T)
		{
			if(T == NULL)
			{
				return;
			}
			else
			{
				delete_rec(T->left);
				delete_rec(T->right);
				delete T;
				return;
			}
		}
};

int main()
{
	BST T;
	T.create();
	T.show();
	T.deleteAll();
	T.show();
	
	return 0;
}

