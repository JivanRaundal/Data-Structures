// Q.8] Binary Search Tree

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
		
		//function declarations
		void create();
		void insert(int);					//non-rec insert()
		Node* insert_rec(Node*, int);		//rec indert()
		void show();						//helper
		void Inorder(Node*);				//rec
		void min_max();						//helper
		Node* findmin_nonrec();				//non-rec
		Node* findmax_nonrec();				//non-rec
		Node* findmin_rec(Node*);			//rec
		Node* findmax_rec(Node*);			//rec
		void search();						//helper
		Node* search_nonrec(int);			//non-rec
		Node* search_rec(Node*, int);		//rec
		void height();						//helper
		int height_rec(Node*);				//rec
		void count();						//helper
		int countTotal(Node*);				//rec
		int count0(Node*);					//rec
		int count1(Node*);					//rec
		int count2(Node*);					//rec
		void delete_node();					//helper
		Node* delete_rec(Node*, int);		//rec delete()
		BST copy_BST();						//function to create exact copy of given BST/calling object of BST
		void preorder_copy(Node*, BST&);
};

void BST::create()
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
		//insert(x);						//non-rec insert()
		root = insert_rec(root, x);			//rec insert()
	}
}

void BST::insert(int x)
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

Node* BST::insert_rec(Node * T,int x)
{
	if(T == NULL)
	{
		T = new Node(x);
		return T;
	}
	if(x < T->data)
	{
		T->left	= insert_rec(T->left, x);
		return T;
	}
	else if(x > T->data)
	{
		T->right = insert_rec(T->right, x);
		return T;
	}
	else		//(x == T->data)
	{
		cout<<"Duplicate data\n";
		return T;
	}
}

void BST::show()
{
	cout<<"\n\nInorder Traversal\n";
	Inorder(root);
}

void BST::Inorder(Node * T)
{
	if(T == NULL)
		return;
	Inorder(T->left);
	cout<<"  "<<T->data;
	Inorder(T->right);
}

void BST::min_max()
{
	Node * T;
	T = this->findmin_nonrec();
	cout<<"\n\nNon-rec minimum data = "<<T->data;
	T = this->findmax_nonrec();
	cout<<"\n\nNon-rec maximum data = "<<T->data;
	
	T = this->findmin_rec(root);
	cout<<"\n\nRec minimum data = "<<T->data;
	T = this->findmax_rec(root);
	cout<<"\n\nRec maximum data = "<<T->data;
}

Node* BST::findmin_nonrec()
{
	if(root == NULL)
	{
		return NULL;
	}
	Node * T = root;
	while(T->left != NULL)
	{
		T = T->left;
	}
	return T;
}

Node* BST::findmax_nonrec()
{
	if(root == NULL)
	{
		return NULL;
	}
	Node * T = root;
	while(T->right != NULL)
	{
		T = T->right;
	}
	return T;	
}

Node* BST::findmin_rec(Node * T)
{
	if(T == NULL)
	{
		return NULL;
	}
	if(T->left == NULL)
	{
		return T;
	}
	return findmin_rec(T->left);
}

Node* BST::findmax_rec(Node * T)
{
	if(T == NULL)
	{
		return NULL;
	}
	if(T->right == NULL)
	{
		return T;
	}
	return findmax_rec(T->right);
}

void BST::height()
{
	cout<<"\n\nHeight of BST = "<<height_rec(root);
}

int BST::height_rec(Node * T)
{
	if(T == NULL)
	{
		return 0;			//return -1;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	int lh = height_rec(T->left);
	int rh = height_rec(T->right);
	if(lh > rh)
	{
		return lh + 1;
	}
	else
	{
		return rh + 1;
	}
}

void BST::count()
{
	cout<<"\n\nTotal Nodes = "<<countTotal(root);
	cout<<"\nLeaf Nodes = "<<count0(root);
	cout<<"\nNode with 1 child = "<<count1(root);
	cout<<"\nNode with 2 child = "<<count2(root);
}

int BST::countTotal(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	int lc = countTotal(T->left);
	int rc = countTotal(T->right);
	return lc + rc + 1;
}

int BST::count0(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 1;
	}
	return count0(T->left) + count0(T->right);
}

int BST::count1(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	if(T->left == NULL)
	{
		return 1 + count1(T->right);
	}
	if(T->right == NULL)
	{
		return 1 + count1(T->left);
	}
	return count1(T->left) + count1(T->right);
}

int BST::count2(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	if(T->left==NULL && T->right==NULL)
	{
		return 0;
	}
	if(T->left == NULL)
	{
		return count2(T->right);
	}
	if(T->right == NULL)
	{
		return count2(T->left);
	}
	return count2(T->left) + count2(T->right) + 1;
}

void BST::search()
{
	int x;
	cout<<"\n\nEnter data to be search : ";
	cin>>x;
	Node * p = this->search_nonrec(x);				//non-rec search
	if(p != NULL)
	{
		cout<<"Data Found";
	}
	else
	{
		cout<<"Data Not Found";
	}

	cout<<"\n\nEnter data to be search : ";
	cin>>x;
	p = this->search_rec(root, x);					//rec search
	if(p != NULL)
	{
		cout<<"Data Found";
	}
	else
	{
		cout<<"Data Not Found";
	}	
}

Node* BST::search_nonrec(int x)
{
	Node * T = root;
	while(T != NULL)
	{
		if(x < T->data)
		{
			T = T->left;
		}
		else if(x > T->data)
		{
			T = T->right;
		}
		else
		{
			//data found
			return T;
		}
	}
	//data not found
	return NULL;
}

Node* BST::search_rec(Node * T,int x)
{
	if(T == NULL)
	{
		//data not found
		return NULL;
	}
	if(x < T->data)
	{
		return search_rec(T->left, x);
	}
	else if(x > T->data)
	{
		return search_rec(T->right, x);
	}
	else
	{
		//data found
		return T;
	}
}

void BST::delete_node()
{
	int x;
	cout<<"\n\nEnter data to be deleted : ";
	cin>>x;
	root = delete_rec(root, x);			//recursive delete() function for BST
}

Node* BST::delete_rec(Node * T,int x)
{
	//search for node
	if(T == NULL)
	{
		cout<<"\nData not found";
		return NULL;
	}
	if(x < T->data)
	{ 
		T->left = delete_rec(T->left, x);
		return T;
	}
	else if(x > T->data)
	{
		T->right = delete_rec(T->right, x);
		return T;
	}
	//data to be deleted found, now deleting the node 
	//leaf node
	if(T->left==NULL && T->right==NULL)
	{
		delete T;
		return NULL;
	}
	//node with single right child
	if(T->left == NULL)
	{
		Node * P = T->right;
		delete T;
		return P;
	}
	//node with single left child
	if(T->right == NULL)
	{
		Node * P = T->left;
		delete T;
		return P;
	}
	//node with 2 children
	Node * P = findmin_rec(T->right);		//find smallest node in right subtree
	T->data = P->data;
	T->right = delete_rec(T->right, P->data);
	return T;
}

BST BST::copy_BST()
{
	BST T;			//object of class BST
	this->preorder_copy(root, T);		//T is passed by reference
	//returning copied BST
	return T;
}

void BST::preorder_copy(Node * P, BST & T)		//T (object of class BST) is passed by reference)
{
	if(P == NULL)
	{
		return;
	}
	T.insert(P->data);			//calling insert() fun for object T
	preorder_copy(P->left, T);
	preorder_copy(P->right, T);
}

int main()
{
	BST T;
	T.create();
	T.show();
	T.min_max();
	T.height();
	T.count();
	T.search();
	T.delete_node();
	T.show();
	T.delete_node();
	T.show();
	T.delete_node();
	T.show();
	
	BST T2;
	T2 = T.copy_BST();
	cout<<"\n\nCopied BST";
	T2.show();
	
	return 0;
}
