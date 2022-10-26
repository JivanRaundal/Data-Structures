//	SLL

#include<iostream>
using namespace std;

class SLL;	//forward declaration
class Node
{
	private:
		int data;
		Node * next;
		
	public:
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int x)
		{
			data = x;
			next = NULL;
		}
		
		friend class SLL;
};

class SLL
{
	private:
		Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		int count();
		int search(int);
		void addatbeg(int);
		void addatend(int);
		void addbypos(int,int);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void SLL::create()
{
	Node * p = NULL;
	int n,i,x;
	cout<<"\nHow many nodes ? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid number";
		return;
	}
	
	cout<<"\nEnter first node data : ";
	cin>>x;
	head = new Node(x);
	
	p = head;
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter next node data : ";
		cin>>x;
		
		p->next = new Node(x);
		p = p->next;
	}
}

void SLL::show()
{
	cout<<"\n";
	if(head == NULL)
	{
		cout<<"\nEmpty List";
		return;
	}
	
	Node * p = head;
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}

int SLL::count()
{
	Node * p = head;
	int c = 0;
	while(p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

int SLL::search(int x)
{
	Node * p = head;
	while(p != NULL)
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void SLL::addatbeg(int x)
{
	Node * p;
	p = new Node(x);
	p->next = head;
	head = p;
}

void SLL::addatend(int x)
{
	if(head == NULL)	//if list is empty
	{
		head = new Node(x);
	}
	else
	{
		Node * p = head;
		while(p->next != NULL)		//will stop at last node & not crossover it
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::addbypos(int pos,int x)
{
	int n;
	n = count();
	
	//check if position is valid or not
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid Position";
		return;	
	}
	cout<<"\nValid Position";
	
	if(pos == 1)
	{
		addatbeg(x);
	}
	else
	{
		Node * p = head;
		Node * temp = NULL;
		
		for(int i=1; i<(pos-1); i++)	//p will stop at position (pos-1)
		{
			p = p->next;	
		}
		
		temp = new Node(x);
		temp->next = p->next;
		p->next = temp;
	}
}

void SLL::delatbeg()
{
	if(head == NULL)	//if list is empty
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//if list contains single node
	{
		delete head;
		head = NULL;
	}
	else		//list contains more than 1 node
	{
		Node * p;
		p = head;
		head = head->next;
		delete p;
	}
	cout<<"\nNode deleted Successfully";
}

void SLL::delatend()
{
	if(head == NULL)		//i.e. if list is empty
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//if list contains single node
	{
		delete head;
		head = NULL;
	}
	else		//list contains more than 1 node
	{
		Node * p = head;
		Node * q = NULL;
		while(p->next != NULL)		//p will stop at last node i.e. at (n)th node
		{
			q = p;					// q will stop at last second node i.e. at (n-1)th node
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
	cout<<"\nNode deleted Successfully";
}

void SLL::delbypos(int pos)
{
	int n;
	n = count();	//total nodes
	//check position is valid or not
	if(pos < 1 || pos > n)
	{
		cout<<"\nInvalid Position";
		return;
	}
	cout<<"\nValid position";
	if(pos == 1)
	{
		delatbeg();
	}
	else
	{
		Node * p = head;
		Node * q = NULL;
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;	//here p will point to previous node of node to be deleted i.e. (pos-1)th node
		}
		q = p->next;		//here q will point to node which is to be deleted. i.e. (pos)th node
		p->next = q->next;
		delete q;
	}
	cout<<"\nNode deleted Successfully";
}

int main()
{
	SLL S;
	
	int x,pos,ch;
	do
	{
		cout<<"\n\n______________MENUE______________";
		cout<<"\n1.  create list";
		cout<<"\n2.  display list";
		cout<<"\n3.  count nodes";
		cout<<"\n4.  search data";
		cout<<"\n5.  add data at beginning";
		cout<<"\n6.  add data at the end";
		cout<<"\n7.  add data by position";
		cout<<"\n8.  delete beginning node";
		cout<<"\n9.  delete end node";
		cout<<"\n10. delete by position";
		cout<<"\n11. exit";
		cout<<"\n_________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				S.create();
				break;
				
			case 2:
				cout<<"\nLIST : ";
				S.show();
				break;
				
			case 3:
				cout<<"\nTotal Nodes = "<<S.count();
				break;
					
			case 4:
				cout<<"\nEnter data to be searched : ";
				cin>>x;
				if(S.search(x))
				{
					cout<<"\nData Found";
				}
				else
				{
					cout<<"\nData Not Found";
				}
				break;
				
			case 5:
				cout<<"\nEnter data to add at the beginning : ";
				cin>>x;
				S.addatbeg(x);
				break;
				
			case 6:
				cout<<"\nEnter data to add at the end : ";
				cin>>x;
				S.addatend(x);
				break;
				
			case 7:
				cout<<"\nEnter position and data : ";
				cin>>pos>>x;
				S.addbypos(pos,x);
				break;
				
			case 8:
				S.delatbeg();
				break;
				
			case 9:
				S.delatend();
				break;
				
			case 10:
				cout<<"\nEnter position of node to be deleted/remove : ";
				cin>>pos;
				S.delbypos(pos);
				break;
				
			case 11:
				exit(0);
				
			default:
				cout<<"\nInvalid Choice...plz try again!!!";
		}
	}while(ch != 11);
	
	return 0;
}
