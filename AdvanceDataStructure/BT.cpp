#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include"Queue.h"
#define MAX 20
using namespace std;
class Node
{
	private:
	int data;
	Node* left,*right;
	public:
	Node()
	{
		data = 0;
		left=right=NULL;
	}
	Node(int x)
	{
		data = x;
		left=right=NULL;
	}
	friend class BT;
};
class BT//binary tree
{
	Node* root;
	public:
	BT()
	{
		root=NULL;
	}
	void Create()
	{
		cout<<"For root Node";
		root = rec_create();
	}
	Node* rec_create()
	{
		char x[5];
		cout<<" enter data / -1 to terminate: ";
		cin>>x;
		if(strcmp(x,"-1")==0)
			return NULL;
		Node* p = new Node(atoi(x));
		cout<<"For Node at left of "<<x;
		p->left = this->rec_create();
		cout<<"For Node at right of "<<x;
		p->right = this->rec_create();
		return p; 
	}
	void Show()
	{
		preorder(root);
		cout<<endl;
		inorder(root);
		cout<<endl;
		postorder(root);
	}
	void preorder(Node* p)
	{
		if(p)
		{
			cout<<p->data<<" ";
			this->preorder(p->left);
			this->preorder(p->right);
		}
	}
	void inorder(Node* p)
	{
		if(p)
		{	
			this->inorder(p->left);
			cout<<p->data<<" ";
			this->inorder(p->right);
		}
	}
	void postorder(Node* p)
	{
		if(p)
		{	
			this->postorder(p->left);
			this->postorder(p->right);
			cout<<p->data<<" ";
		}
	}
	void nonrec_preorder()
	{
		stack <Node*> S;
		Node* T = root;
	
			while(T!=NULL)
			{
				cout<<T->data<<" ";
				S.push(T);
				T = T->left;
			}
			while(!S.empty())
			{
				T = S.top();
				S.pop();
				T = T->right;
				while(T!=NULL)
				{
					cout<<T->data<<" ";
					S.push(T);
					T=T->left;
				}
			}	
	}
	void nonrec_postorder();
	void BFT();
	int HofT();
	void HofEachNode(Node* p);
	void HofN(Node* p);
	Node* getRoot();
	int rec_HofT(Node*); 
	int rec_HofN(Node* T);
	void rec_HofeachN(Node* T);
	int countN(Node* T);
	int count0(Node* T);//will return total leaf Nodes
	int count1(Node* T);//will return total Nodes with degree 1
	int count2(Node* T);//will return total Nodes with degree 2
	int search(Node* T,int x);
	
	//UID operations:
	void update_data(Node* T,int x,int k)
	{
		if(T)
		{
			if(T->data == x)
			{
				T->data = k;
			}
			update_data(T->left,x,k);
			update_data(T->right,x,k);	
		}
	}
	void update(int x, int k)
	{
		if(this->search(root,x)==1)
		{
			this->update_data(root,x,k);
		}
		else
		{
			cout<<"\nthe value to be updated is not present ";
		}
	}
	void Delete(int x)
	{
		if(this->search(root,x)==1)
		{
			if(root->left== NULL and root->right==NULL)
			{
				delete root;
				root=NULL;
				return;
			}
			Delete_Node(root,x);
		}
		else
		{
			cout<<"\nthe value to be deleted is not present ";
		}
	}
	int Delete_Node(Node* T, int x)
	{
		if(T)
		{
			if(T->data == x)
			{
				Node* P = this->rec_deepNode(root,NULL);
				//cout<<endl<<P->data<<endl;
				if(P->right == NULL)
				{
					T->data = P->left->data;
					delete P->left;
					P->left = NULL;
				}	
				else
				{
					T->data = P->right->data;
					delete P->right;
					P->right = NULL;
				}
				return 1;	
			}
			if(Delete_Node(T->left,x))
				return 1;
			return Delete_Node(T->right,x);
		}
	}
	Node* deepNodeBFT()
	{
		SQ<Node*> q1;
		SQ<Node*> q2;
		q1.enqueue(root);
		Node* T=root;
		while(1)
		{
			while(!q1.empty())
			{
				T = q1.dequeue();
				if(T->left)
					q2.enqueue(T->left);
				if(T->right)
					q2.enqueue(T->right);
			}
			if(q2.empty())
			{
				return T;
			}
			else
			{
				q1 = q2;
				q2.init();	 
			}
		}	
	}
	Node* rec_deepNode(Node* T,Node* P=NULL)
	{
		if(T==NULL)
			return P;
		if(T->left == NULL && T->right == NULL)
		{
			cout<<"\ndeepest and rightmost: "<<T->data<<endl;
			return P;
		}
		if(rec_HofT(T->left) > rec_HofT(T->right))
		{
			return rec_deepNode(T->left,T);
		}
		else
		{
			return rec_deepNode(T->right,T);
		}	
	}
	Node* itr_deepNode()
	{
		Node* T = root;
		Node* P = NULL;
		while(1)
		{
			if(T->left==NULL && T->right==NULL)
				break;
			P = T;
			if(rec_HofT(T->left) > rec_HofT(T->right))
			{
				
				T = T->left;
			}
			else
			{
				T = T->right;
			}
		}
		return P;
	}	
	void insert(int x)//Insertion at leaf Nodes
	{
		stack<Node*> t = leaf_Nodes();
		stack<Node*> t1;
		Node* P ;
		cout<<"\nleaf Nodes are : "<<endl;
		while(!t.empty())
		{
			P = t.top();
			t.pop();
			cout<<P->data<<" ";
			t1.push(P);
		}
		cout<<"\nWhere do you want attach your data: ";
		cin>>x;
		while(!t1.empty())
		{
			P = t1.top();
			t1.pop();
			if(P->data == x)
				break;
		}
		cout<<"\nwhat data you want to attach: ";cin>>x;
		P->left = new Node(x);
		
	}
	stack<Node*> leaf_Nodes()
	{
		stack<Node*> s;
		stack<Node*> t;
		Node* T = root;
		while(T)
		{
			s.push(T);
			T=T->left;
		}
		while(!s.empty())
		{
			T = s.top();
			s.pop();
			if(T->left==NULL && T->right==NULL)
				t.push(T);
			T = T->right;
			while(T)
			{
				s.push(T);
				T=T->left;
			}	
		}
		return t;
	}
	void Insert(int x)//x is attached to min height branch
	{
		Node* T = root;
		Node* P = NULL;
		while(T)
		{
			P = T;
			if(this->rec_HofT(T->left)>this->rec_HofT(T->right))
				T = T->right;
			else
				T = T->left;
		}
		if(P->right==NULL && P->left!=NULL)
			P->right = new Node(x);
		else
			P->left = new Node(x);
	}
};

typedef struct stackNode
{
	public:
		Node* add;
		int flag;
		stackNode()
		{
			add = NULL;
			flag = 0;
		}
}SN;
void BT::nonrec_postorder()
{
	stack <SN> s;
	Node* T=root;
	SN obj;
	while(T)
	{
		obj.add = T;
		s.push(obj);
		T = T->left;
	}
	while(!s.empty())
	{
		obj = s.top();
		s.pop();
		T = obj.add;
		if(obj.flag==0)
		{
			obj.flag = 1;
			s.push(obj);
			T = T->right;
			while(T)
			{
				obj.add = T;
				obj.flag= 0;
				s.push(obj);
				T = T->left;
			}
		}
		else if(obj.flag==1)
		{
			cout<<T->data<<" ";
		}
	}
	
}
void BT::BFT()
{
	SQ<Node*> q1;
	SQ<Node*> q2;
	cout<<root->data<<endl;
	Node* T = root;
	q1.enqueue(T);
	while(1)
	{
		while(!q1.empty())
		{
			T = q1.dequeue();
			if(T->left)
			{
				cout<<T->left->data<<" ";
				q2.enqueue(T->left);
			}
			if(T->right)
			{
				cout<<T->right->data<<" ";
				q2.enqueue(T->right);
			}
		}
		cout<<endl;
		q1 = q2;
		q2.init();
		if(q1.empty())
			break;
	}	
}
int BT::HofT()
{
	SQ <Node*> q1;
	SQ <Node*> q2;
	int count = 0;
	Node* T = root;
	q1.enqueue(T);
	while(1)
	{
		while(!q1.empty())
		{
			T = q1.dequeue();
			if(T->left)
			{
				q2.enqueue(T->left);
			}
			if(T->right)
			{
				q2.enqueue(T->right);
			}
		}
		q1 = q2;
		q2.init();
		if(q1.empty())
			break;
		count++;
	}	
	return count;
}
void BT::HofN(Node* p)
{
	SQ <Node*> q1;
	SQ <Node*> q2;
	int count = 0;
	Node* T = p;
	q1.enqueue(T);
	while(1)
	{
		while(!q1.empty())
		{
			T = q1.dequeue();
			if(T->left)
			{
				q2.enqueue(T->left);
			}
			if(T->right)
			{
				q2.enqueue(T->right);
			}
		}
		q1 = q2;
		q2.init();
		if(q1.empty())
			break;
		count++;
	}	
	cout<<"\nheight of "<<p->data<<" is "<<count;
}
void BT::HofEachNode(Node* p)
{
	if(p)
	{
		HofN(p);
		HofEachNode(p->left);
		HofEachNode(p->right);
	}
}
Node* BT::getRoot()
{
	return this->root;
}
int BT::rec_HofT(Node* T)
{
	if(T==NULL)
		return -1;
	if(T)
	{
		int l = this->rec_HofT(T->left);
		int r = this->rec_HofT(T->right);
		return 	(l>r ? l : r)+1;
	}
}
int BT::rec_HofN(Node* T)
{
	

	if(T==NULL)
		return -1;
	if(T)
	{
		int l = this->rec_HofN(T->left);
		int r = this->rec_HofN(T->right);
		int h =	(l>r ? l : r)+1;
		cout<<"\nheight of "<<T->data<<" is "<<h;
		return h;
	}
}
int BT::countN(Node* T)
{
	if(T == NULL)
		return 0;
	return this->countN(T->left) + this->countN(T->right) + 1;
}
int BT::count0(Node* T)
{
	if(T==NULL)
		return 0;
	if(T->left == NULL && T->right==NULL)
		return 1;
	return count0(T->left) + count0(T->right);//traversal
}
int BT::count1(Node* T)
{
	if(T==NULL)
		return 0;
	if(T->left == NULL && T->right==NULL)
		return 0;
	else if(T->left==NULL)
		return 1 + count1(T->right);
	else if(T->right==NULL)
		return 1 + count1(T->left);
	return count1(T->left) + count1(T->right);
}
int BT::count2(Node* T)
{
	if(T==NULL)
		return 0;
	if(T->left==NULL && T->right == NULL)
		return 0;
	else if(T->left==NULL)
		return count1(T->left);
	else if(T->right==NULL)
		return count1(T->right);
	return 1+count1(T->left) + count1(T->right);
}
int BT::search(Node* T,int x)
{
	if(T == NULL)
		return 0;
	if(T->data == x)
		return 1;
	if(search(T->left,x)==1)
		return 1;
	return search(T->right,x);
}
int main()
{
	BT T;
	T.Create();
	//T.Show();
	//T.nonrec_preorder();
	//T.nonrec_postorder();
	//T.BFT();
	//cout<<T.HofT();
	//T.HofEachNode(T.getRoot());
	//cout<<endl<<T.rec_HofT(T.getRoot());
	//T.rec_HofN(T.getRoot());
	//cout<<endl<<T.count0(T.getRoot());
	//cout<<endl<<T.search(T.getRoot(),27);
	//cout<<"\nenter new key value: ";cin>>k;
	//T.update(21,k);
	//T.Delete(21);
	//T.inorder(T.getRoot());
	//T.showdeepest(T.itr_deepNode());
	//T.Delete(T.getRoot(),8);
	//T.inorder(T.getRoot());
	//T.Insert(10);
	T.Delete(3);
	T.Show();
	
	return 0;
}

