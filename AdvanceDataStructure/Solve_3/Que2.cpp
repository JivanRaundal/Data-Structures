// Q.2] Student Database (BST)

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		int roll;
		char addr[20];
		char phone[10];
		
		Student()
		{
			strcpy(name, "");
			strcpy(addr, "");
			strcpy(phone, "");
			age = roll = 0;
		}
		void scandata()
		{
			cin.ignore(1);
			cout<<"\nEnter name : ";
			cin.getline(name,28,'\n');
			cout<<"Enter age : ";
			cin>>age;
			cout<<"Enter roll no : ";
			cin>>roll;
			cin.ignore(1);
			cout<<"Enter address : ";
			cin.getline(addr,18,'\n');
			cout<<"Enter phone no : ";
			cin>>phone;		//bcz, phone no. is not space seperated
		}
		
		void showdata()
		{
			cout<<"\n\nName    = "<<name;
			cout<<"\nAge     = "<<age;
			cout<<"\nRoll    = "<<roll;
			cout<<"\nAddress = "<<addr;
			cout<<"\nPhone   = "<<phone;
		}
};

class Node
{
	public:
		Student std;
		Node *left, *right;
		Node(Student temp)
		{
			std = temp;
			//std.scandata();
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
		Node* insert_rec(Node*,Student temp);
		void show();
		void Inorder(Node * T);
		Node* search(char * name);					//nonrec
		void delete_node();
		Node* findmin_nonrec(Node * root);		//nonrec
		Node* delete_rec(Node * T,char * name);	//recursive delete
		void addStudent();
};

void BST::create()
{
	Student temp;
	int n = 0;
	cout<<"\n\nHow many students ? ";
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		temp.scandata();
		root = insert_rec(root, temp);
	}
}

Node* BST::insert_rec(Node* T,Student temp)
{
	if(T == NULL)
	{
		T = new Node(temp);
		return T;
	}
	if(strcmp(temp.name, T->std.name) == -1)
	{
		T->left = insert_rec(T->left, temp);
		return T;
	}
	else if(strcmp(temp.name, T->std.name) == 1)
	{
		T->right = insert_rec(T->right, temp);
		return T;
	}
	else
	{
		//(strcmp(temp.name, T->std.name) == 0)
		cout<<"\nDuplicate entry";
		return T;
	}
}

void BST::show()
{
	cout<<"\n\nStudent Database";
	Inorder(root);
}

void BST::Inorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	Inorder(T->left);
	T->std.showdata();
	Inorder(T->right);
}

Node* BST::search(char * name)
{
	Node * T = root;
	while(T != NULL)
	{
		if(strcmp(name, T->std.name) == -1)
		{
			T = T->left;
		}
		else if(strcmp(name, T->std.name) == 1)
		{
			T = T->right;
		}
		else
		{
			//(strcmp(name, T->std.name) == 0)
			return T; 		//found
		}
	}
	return NULL;			//not found
}

void BST::delete_node()
{
	char name[30];
	cout<<"\n\nEnter name to delete : ";
	cin.getline(name,28,'\n');
	root = delete_rec(root, name);
}

Node* BST::findmin_nonrec(Node * T)
{
	if(T == NULL)
	{
		return NULL;
	}
	while(T->left != NULL)
	{
		T = T->left;
	}
	return T;
}
 
Node* BST::delete_rec(Node * T,char * name)
{
	//search the student with mentioned name first
	if(T == NULL)
	{
		cout<<"\nData Not Found";
		return NULL;
	}
	if(strcmp(name, T->std.name) == -1)
	{
		T->left = delete_rec(T->left, name);
		return T;
	}
	else if(strcmp(name, T->std.name) == 1)
	{
		T->right = delete_rec(T->right, name);
		return T;
	}

	//Student to be deleted found, now delete it
	//check if the node to be deleted is leaf node
	if(T->left==NULL && T->right==NULL)
	{
		delete T;
		return NULL;
	}
	//if node to be deleted has 1 child 
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
	//Node has both left & right child (i.e. degree of node is 2)
	Node * P;
	P = this->findmin_nonrec(T->right);					//find min node in right subtree of T
	T->std = P->std;									//replace data of T with that min node data
	T->right = delete_rec(T->right, P->std.name);		//delete that min node from right subtree of T
	return T;
}

void BST::addStudent()
{
	Student temp;
	cout<<"\n\nEnter details of new student\n";
	temp.scandata();
	root = insert_rec(root, temp);
}

int main()
{
	BST T;
	int roll;
	T.create();
	T.show();

	char name[30];
	cout<<"\n\nEnter name to search : ";
	cin.ignore(1);
	cin.getline(name,28,'\n');
	Node * P = T.search(name);
	if(P != NULL)
	{
		cout<<"\nStudent Found";
		P->std.showdata();
	}
	else
	{
		cout<<"\nStudent Not Found";
	}
	
	T.delete_node();
	T.show();
	
	T.addStudent();
	T.show();
	
	return 0;
}



