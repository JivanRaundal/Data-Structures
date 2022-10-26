// general tree

#include<iostream>
#include<vector>
#include "Pro2_Queue.h"
using namespace std;

class Node
{
	public:
		int data;
		vector<Node*> child;
	
		Node()
		{
			data = 0;
		}
		Node(int data)
		{
			this->data = data;
		}
};

/*
Node* takeTree()
{
	int rootdata;
	cout<<"\nEnter data : ";
	cin>>rootdata;
	Node * root = new Node(rootdata);
	
	int n;
	cout<<"\nEnter num of childrens of "<<rootdata<<" : ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		Node * child = takeTree();
		root->child.push_back(child);
	}
	return root;
}
*/


Node* takeInputLevelWise()
{
	int rootdata;
	cout<<"\nEnter root data : ";
	cin>>rootdata;
	Node * root = new Node(rootdata);
	
	Queue Q;
	Q.enqueue(root);
	
	int i,n;
	while(!Q.empty())
	{
		Node * p = Q.dequeue();
		cout<<"\nEnter num of children of "<<p->data<<" : ";
		cin>>n;
		for(i=0; i<n; i++)
		{
			int childData;
			cout<<"\nEnter "<<i<<"th child data : ";
			cin>>childData;
			Node * childNode = new Node(childData);
			p->child.push_back(childNode);		//connect linkes with parent node vector
			Q.enqueue(childNode);				//add in Queue
		}
	}
	return root;
}

/*
void PrintTree(Node * root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<" "<<root->data<<" : ";
	int i;
	for(i=0; i<root->child.size(); i++)
	{
		cout<<root->child[i]->data<<", ";
	}
	
	cout<<endl;
	for(i=0; i<root->child.size(); i++)
	{
		PrintTree(root->child[i]);
	}
}
*/

void PrintTreeLevelWise(Node * root)			//will print tree level wise
{
	if(root == NULL)
	{
		return;
	}
	
	Queue Q;
	Q.enqueue(root);
	cout<<endl;
	
	while(!Q.empty())
	{
		Node * p = Q.dequeue();
		cout<<" "<<p->data<<"  : ";
		for(int i=0; i<p->child.size(); i++)
		{
			cout<<p->child[i]->data<<", ";
			Q.enqueue(p->child[i]);
		}
		cout<<endl;
	}
}

int countNodes(Node * root)
{ 
	int ans = 1;
	for(int i=0; i<root->child.size(); i++)
	{
		ans = ans + countNodes(root->child[i]);
	}
	return ans;
}

/*
int maxHeight(Node * root)
{
	int max = 0;
	int ans = 1;
	
	for(int i=0; i<root->child.size(); i++)
	{
		ans = ans + maxHeight(root->child[i]);
		if(max < ans)
		{
			max = ans;
		}
	}
	return max;
}
*/

int main()
{
	Node * root = NULL;
	
	//root = takeTree();		//take input recursion wise i.e. depth wise
	
	cout<<"\n\nEnter data in tree\n\n";
	root = takeInputLevelWise();		//take input level wise
	
	cout<<"\n\nPrinting\n";
	//PrintTree(root);
	PrintTreeLevelWise(root);
	
	cout<<"\n\nTotal Nodes in Tree = "<<countNodes(root);
	
	cout<<"\n\nMaximum Height of Tree = "<<maxHeight(root);
	
	return 0;
}


