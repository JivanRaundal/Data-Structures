// Q.9] BST of city names. create, insert, inorder, search & delete operations. 

#include<iostream>
#include<string.h>
using namespace std;

class Node
{
	public:
		char city[20];
		Node *left, *right;
		Node()
		{
			strcpy(city, "");
			left = right = NULL;
		}
		Node(char * s)
		{
			strcpy(city, s);
			left = right = NULL;
		}
};

class BST
{
	private:
		Node * root;
	public:
		BST()
		{
			root = NULL;
		}
		
		void create();
		Node* insert_rec(Node*, char*);
		void show();
		void Inorder(Node*);
		Node* search_nonrec(char*);
		void delete_city();
		Node* delete_rec(Node*, char*);
		Node* findmin_rec(Node*);
};

void BST::create()
{
	char str[20];
	cout<<"\n\nKeep entering city names and STOP to stop\n";
	while(1)
	{
		cin.getline(str,18,'\n');
		if(strcmp(str, "STOP") == 0)
		{
			return;
		}
		root = insert_rec(root, str);
	}
}

Node* BST::insert_rec(Node * T,char * city)
{
	if(T == NULL)
	{
		T = new Node(city);
		return T;
	}
	if(strcmp(city, T->city) == -1)		//i.e. city < T.city
	{
		T->left = insert_rec(T->left, city);
		return T;
	}
	else if(strcmp(city, T->city) == 1)		//i.e. city > T.city
	{
		T->right = insert_rec(T->right, city);
	}
	else
	{
		cout<<"\nDuplicate entry";
		return T;
	}
}

void BST::show()
{
	cout<<"\n\nPrinting cities in sorted order\n";
	Inorder(root);
}

void BST::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	cout<<T->city<<endl;
	Inorder(T->right);
}

Node* BST::search_nonrec(char * city)
{
	Node * T = root;
	while(T != NULL)
	{
		if(strcmp(city, T->city) == -1)
		{
			T = T->left;
		}
		else if(strcmp(city, T->city) == 1)
		{
			T = T->right;
		}
		else 		// strcmp(city, T->city) == 1 (found)
		{
			//found
			return T;
		}
	}
	//not found
	return NULL;
}

 void BST::delete_city()
 {
 	char city[20];
 	cout<<"\n\nEnter city name to be delete : ";
 	cin.getline(city,18);
 	root = delete_rec(root, city);
 }
 
 Node* BST::delete_rec(Node * T,char * city)
 {
 	//search city to be deleted
 	if(T == NULL)
 	{
 		cout<<"\nCity not found";
 		return T;
	}
	if(strcmp(city, T->city) == -1)
	{
		T->left = delete_rec(T->left, city);
		return T;
	}
	else if(strcmp(city, T->city) == 1)
	{
		T->right = delete_rec(T->right, city);
		return T;
	}
	//city node to be delete is found
	//deleting if leaf node
	if(T->left==NULL && T->right==NULL)
	{
		delete T;
		return NULL;
	}
	//deleting node with 1 child
	if(T->left == NULL)
	{
		Node * P = T->right;
		delete T;
		return P;
	}
	if(T->right == NULL)
	{
		Node * P = T->left;
		delete T;
		return P;
	}
	//deleting node with 2 child
	Node * P = findmin_rec(T->right);		//find minimum data in right subtree of T
	strcpy(T->city, P->city);
	T->right = delete_rec(T->right, P->city);
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

int main()
{
	BST T;
	T.create();
	T.show();
	char str[20];
	cout<<"\n\nEnter city name to be search : ";
	cin.getline(str,18);
	Node * P = T.search_nonrec(str);
	if(P != NULL)
	{
		cout<<"FOUND";
	}
	else
	{
		cout<<"NOT FOUND";
	}
	T.delete_city();
	T.show();
	T.delete_city();
	T.show();
	T.delete_city();
	T.show();
	
	return 0;
}
