// AVL Tree (BST) (Height Balanced Tree):-

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

class AVL
{
	private:
		Node * root;
	public:
		AVL()
		{
			root = NULL;
		}
		
		void create();
		Node* insert(Node * T,int x);
		Node* rotateleft(Node * T);
		Node* rotateright(Node * T);
		Node* leftright(Node * T);
		Node* rightleft(Node * T);
		int height(Node * T);
		int balanceFactor(Node * T);
		
		void deleteNode();
		Node* delete_rec(Node * T,int x);
		Node* findmin_rec(Node * T);
		
		void show();
		void Inorder(Node * T);
};

void AVL::create()
{
	int x;
	cout<<"\nKeep entering data or enter -1 to stop\n";
	while(1)
	{
		cin>>x;
		if(x == -1)
		{
			break;
		}
		root = insert(root, x);				//insert() will insert only one node at a time
	}
}

//right chya right madhe node add zalyane BF bighadla, then use rotateleft()
Node* AVL::rotateleft(Node * T)
{
	Node * P;
	P = T->right;
	T->right = P->left;
	P->left = T;
	return P;
}

//left chya left madhe node add zalyane BF bighadla, then use rotateright()
Node* AVL::rotateright(Node * T)
{
	Node * P;
	P = T->left;
	T->left = P->right;
	P->right = T;
	return P;
}

//left chya right madhe node add zalyane BF bighadla, then use leftright()
Node* AVL::leftright(Node * T)
{
	T->left = rotateleft(T->left);		//jyacha BF bighadlay tyachya left child la aadhi left la rotate kara
	T = rotateright(T);					//nantar jyacha BF bighadlay tyala right la rotate kara
	return T;
}

//right chya left madhe node add zalyane BF bighadla, then use rightleft()
Node* AVL::rightleft(Node * T)
{
	T->right = rotateright(T->right);	//jyacha BF bighadlay tyachya right child la aadhi right la rotate kara
	T = rotateleft(T);					//nantar jyacha BF bighadlay tyala left la rotate kara
	return T;
}

Node* AVL::insert(Node * T,int x)
{
	if(T == NULL)
	{
		T = new Node(x);
		return T;
	}
	if(x < T->data)
	{
		T->left = insert(T->left, x);
		//check balance factor during backtracking & perform rotations if necessary
		if(balanceFactor(T) == 2)
		{
			if(x < T->left->data)			//left chya left madhe node add zalyane BF bighadla, use rotateright()
			{
				T = rotateright(T);
			}
			else							//left chya right madhe node add zalyane BF bighadla, use leftright()
			{
				T = leftright(T);
			}
		}
		return T;
	}
	if(x > T->data)
	{
		T->right = insert(T->right, x);
		//check balance factor during backtracking & perform rotations if necessary
		if(balanceFactor(T) == -2)
		{
			if(x > T->right->data)			//right chya right madhe node add zalyane BF bighadla, use rotateleft()
			{
				T = rotateleft(T);
			}
			else							//right chya left madhe node add zalyane BF bighadla, use rightleft()
			{
				T = rightleft(T);
			}
		}
		return T;
	}
	else
	{
		cout<<"Duplicate Data\n";
		return T;			//return T as it is without adding it, if duplicate record found
	}
}

int AVL::height(Node * T)
{
	if(T==NULL || (T->left==NULL && T->right==NULL))
	{
		return 0;
	}
	int lh=0, rh=0;
	if(T->left != NULL)
	{
		lh = 1 + height(T->left);
	}
	if(T->right != NULL)
	{
		rh = 1 + height(T->right);
	}
	//return max(lh, rh)
	return (lh > rh) ? lh : rh;
}

int AVL::balanceFactor(Node * T)
{
	if(T == NULL)
	{
		return 0;
	}
	int lh=0, rh=0;
	if(T->left != NULL)
	{
		lh = 1 + height(T->left);
	}
	if(T->right != NULL)
	{
		rh = 1 + height(T->right);
	}
	//return (left_height - right_height)
	return (lh - rh);
}

void AVL::show()
{
	cout<<"\n\nInorder Traversal of AVL Tree\n";
	Inorder(root);
	
	cout<<"\n\nHeight of root node = "<<height(root);
	cout<<"\n\nBalance Factor of root node [ should be(-1,0,+1) ] = "<<balanceFactor(root);
}

void AVL::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	cout<<"  "<<T->data;
	Inorder(T->right);
}

void AVL::deleteNode()
{
	int x;
	cout<<"\n\nEnter data to be deleted : ";
	cin>>x;
	root = delete_rec(root, x);
}

Node* AVL::delete_rec(Node * T,int x)
{
	if(T == NULL)
	{
		cout<<"\ncannot delete";
		return NULL;
	}
	if(x < T->data)
	{
		T->left = delete_rec(T->left, x);
		//check balance factor of T during backtracking and perform rotations if necessary
		if(balanceFactor(T) == -2)
		{
			if(balanceFactor(T->right) <= 0)
			{
				T = rotateleft(T);
			}
			else
			{
				T = rightleft(T);
			}
		}
		return T;
	}
	if(x > T->data)
	{
		T->right = delete_rec(T->right, x);
		//check balance factor of T during backtracking and perform rotations if necessary
		if(balanceFactor(T) == 2)
		{
			if(balanceFactor(T->left) >= 0)
			{
				T = rotateright(T);
			}
			else
			{
				T = leftright(T);
			}
		}
		return T;
	}
	//data to be delete is found, now delete the node containing data
	//if node to be deleted is leaf node
	if(T->left==NULL && T->right==NULL)
	{
		delete T;
		return NULL;
	}
	//if node to be deleted has single right child
	if(T->left == NULL)
	{
		Node * P;
		P = T->right;
		delete T;
		return P;
	}
	//if node to be deleted gas single left child
	if(T->right == NULL)
	{
		Node * P;
		P = T->left;
		delete T;
		return P;
	}
	//if node to be deleted has both left & right child
	Node * P;
	P = findmin_rec(T->right);					//find smallest node in right subtree
	T->data = P->data;							//replace data of T with P
	T->right = delete_rec(T->right, P->data);	//recursively delete that smallest node from right subtree of T
	//check balance factor of T during backtracking and perform necessary rotations
	if(balanceFactor(T) == 2)		//NOTE:- as P will always be on right of T, hence check for right possibility only
	{
		if(balanceFactor(T->left) >= 0)
		{
			T = rotateright(T);
		}
		else
		{
			T = leftright(T);
		}
	}
	return T;
}

Node* AVL::findmin_rec(Node * T)
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

int main()
{
	AVL T;
	T.create();
	T.show();
	
	T.deleteNode();
	T.show();
	T.deleteNode();
	T.show();
	T.deleteNode();
	T.show();
	
	return 0;
}




