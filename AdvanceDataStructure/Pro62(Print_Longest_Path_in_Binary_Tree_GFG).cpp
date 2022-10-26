// Print longest path from root to leaf in binary tree :-
/* Algorithm :-
-If the root node is null then no path exists, return an empty vector.
-get the longest path from right subtree in a vector rightVect by recursively traversing root->right
-similarly, get the longest path from left subtree in a vector leftVect by recursively traversing root->left
-compare the length of rightVect and leftVect and append the current node to the longer of the two and return that vector.
*/

#include<iostream>
#include<vector>
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

class Tree
{
		Node * root;
	public:
		Tree()
		{
			root = NULL;
		}
		
		void create();
		Node* create_rec();
		void show();
		void preorder(Node* T);
		void longestPathTree();
		vector<int> longestPath(Node* T);
};

void Tree::create()
{
	root = create_rec();
}

Node* Tree::create_rec()
{
	int x;
	cout<<"\nEnter data or -1 to stop : ";
	cin>>x;
	if(x == -1)
	{
		return NULL;
	}
	Node * p;
	p = new Node(x);
	cout<<"Enter left of "<<x;
	p->left = create_rec();
	cout<<"Enter right of "<<x;
	p->right = create_rec();
	return p;
}

void Tree::show()
{
	cout<<"\n\nPreorder of Binary Tree\n";
	preorder(root);
}

void Tree::preorder(Node * T)
{
	if(T == NULL)
	{
		return;
	}
	cout<<"  "<<T->data;
	preorder(T->left);
	preorder(T->right);
}

void Tree::longestPathTree()
{
	cout<<"\n\nLongest Path in Tree\n";
	vector<int> vect = longestPath(root);
	//print the vector in reverse order
	int n = vect.size();
	cout<<vect[n-1];
	for(int i=n-2; i>=0; i--)
	{
		cout<<" -> "<<vect[i];
	}
}

//function to find longest path in binary tree
vector<int> Tree::longestPath(Node * T)
{
	if(T == NULL)
	{
		//return an empty vector
		vector<int> temp;
		return temp;
	}
	
	//recursively call on T->left
	vector<int> leftVect = longestPath(T->left);
	
	//recursively call on T->right
	vector<int> rightVect = longestPath(T->right);
	
	//compare size of two vectors & insert current node in vector with larger size
	if(leftVect.size() > rightVect.size())
	{
		leftVect.push_back(T->data);
	}
	else
	{
		rightVect.push_back(T->data);
	}
	
	//return vector with maximum size
	return (leftVect.size() > rightVect.size()) ? leftVect : rightVect;
}

int main()
{
	Tree T;
	T.create();
	T.show();
	T.longestPathTree();
	
	return 0;
}

