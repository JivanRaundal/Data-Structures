// Tree

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *left,*right;
		
		Node()
		{
			data = 0;
			left = right = NULL;
		}
		
		Node(int data)
		{
			this->data = data;
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
		
		Node * Insert(Node * p,int data)
		{
			if(p == NULL)
			{
				p = new Node(data);
				return p;	
			}
			else if(data < p->data)
			{
				p->left = Insert(p->left,data);
			}
			else
			{
				p->right = Insert(p->right,data);
			}
			return p;
		}
		
		void Insert(int data)
		{
			root = Insert(root,data);
		}
		
		void Inorder(Node * p)
		{
			if(p != NULL)
			{
				Inorder(p->left);
				cout<<" "<<p->data;
				Inorder(p->right);
			}
		}
		
		void show()
		{
			cout<<"\n\n------------Inorder Traversal of BST------------\n";
			Inorder(root);
			cout<<"\n-------------------------------------------------";
		}
};

int main()
{
	cout<<"\nWelcome To Bineary Search Tree\n";
	
	BST B;
	int i,n,x;
	
	cout<<"\n\nHow many elements ? ";
	cin>>n;
	
	cout<<"\nEnter "<<n<<" elements\n";
	for(i=0; i<n; i++)
	{
		cin>>x;
		B.Insert(x);
	}
	cout<<"\n\nBST created Successfully";

	B.show();
	
	return 0;
}








