// Q. Ask user that how many nodes he/she want in list. Use function get_node() for new Node.

#include<iostream>
using namespace std;

class SLL;	//forward declaration
class Node
{
	private:
		int data;
		Node * next;
		
	public:
		Node()			//default constructor
		{
			data = 0;
			next = NULL;
		}
		Node(int x)		//parameterized constructor
		{
			data = x;
			next =NULL;
		}
		
		friend class SLL;
};

class SLL
{
	private:
		Node * head;
		
	public:
		SLL()		//default constructor
		{
			head = NULL;
		}
		
		void create();
		void show();
		int count();
		int search(int x);
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int pos,int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void SLL::create()
{
	Node * p = NULL;
	int n,i,x;
	cout<<"\nHow many nodes you want? ";
	cin>>n;
	
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
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
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
	if(head == NULL)	//i.e. if list is empty
	{
		head = new Node(x);
	}
	else				//i.e. if list is not empty
	{
		Node * p = head;
		while(p->next != NULL)		//here we are stopping at last node hence condition while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Node(x);
	}
}

void SLL::addbypos(int pos,int x)
{
	int n;
	n = count();	//count() will work for calling object of addbypos()
	
	//check if position is valid or not
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid position";
		return;
	}
	cout<<"\nValid Position";
	
	if(pos == 1)
	{
		addatbeg(x);	//will work for calling object of addbypos()
	}
	else	// postion is somewhere middle or end
	{
		Node * p = head;	
		Node * temp = NULL;
		
		//Note - If we have to add node at pos, then we have to update node at (pos-1)
		// we have to use loop to point p at (pos-1)
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;	
		}
		temp = new Node(x);
		temp->next = p->next;
		p->next = temp;
	} 
}

/*void SLL::addatpos(int x)			//my own function 
{
	int pos;
	cout<<"\nWhich position? : ";
	cin>>pos;
	
	int c = count();
	if(pos > c+1)
	{
		cout<<"\nInvalid Position!";
	}
	else
	{
		if(pos == 1)
		{
			addatbeg(x);
		}
		else if(pos == c+1)
		{
			addatend(x);
		}
		else
		{
			Node * p = head;
			Node * prev = NULL;
			int i=1;
			
			while(p->next != NULL)
			{
				if(pos == i)
				{
					Node * temp = new Node(x);
					temp->next = prev->next;
					prev->next = temp; 
				}
				i++;
				prev = p;
				p = p->next;
			}
		}
	}
}*/

void SLL::delatbeg()
{
	if(head == NULL)	//i.e. if list is empty 
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//OR if(count() == 1) i.e. if list has only one node
	{
		delete head;
		head = NULL;
	}
	else						// list contains more than one nodes
	{
		Node * p;
		p = head;
		head = head->next;
		delete p;
	}
}

void SLL::delatend()
{
	if(head == NULL)	//i.e. if list is empty
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//OR if(count() == 1) i.e. if list has only one node
	{
		delete head;
		head = NULL;
	}
	else						// List contains more than one node
	{
		Node * p = head;
		Node * q = NULL;	
		while(p->next != NULL)		//p will stop at last node i.e. (n)th node
		{
			q = p;					//q will stop at last second node i.e. (n-1)th node (previous of p)
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delbypos(int pos)
{
	int n;
	n = count();	// n = total number of nodes in list
	//check if position is valid or not
	if(pos < 1 || pos > n)	//valid position is between (1 to n)
	{
		cout<<"\nInvalid Position";
		return;
	}
	cout<<"\nValid Position";
	
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
			p = p->next;		//here p will point to previous node of node to be deleted i.e. (pos-1)th node
		}
		q = p->next;		//here q will point to node which is to be deleted. i.e. (pos)th node
		p->next = q->next;
		delete q;			//node is deleted
	}
}

int main()
{
	SLL obj;
	
	obj.create();
	
	int x, pos;
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	/*cout<<"\n\nEnter data to be searched : ";
	cin>>x;
	if(obj.search(x))
	{
		cout<<"\nData found";
	}
	else
	{
		cout<<"\nData Not found";
	}
	
	cout<<"\n\nEnter data to be add at beginning : ";
	cin>>x;
	obj.addatbeg(x);
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	cout<<"\n\nEnter data to be add at end : ";
	cin>>x;
	obj.addatend(x);
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	cout<<"\n\nEnter position and data : ";
	cin>>pos>>x;
	obj.addbypos(pos,x);
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	char ch;
	cout<<"\nDo you want to delete beginning node (yes = 'y',no = 'n') : ";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		obj.delatbeg();
	}
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	cout<<"\nDo you want to delete end node (yes = 'y',no = 'n') : ";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		obj.delatend();
	}
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();*/
	
	cout<<"\nEnter position of data you want to delete/remove : ";
	cin>>pos;
	obj.delbypos(pos);
	
	cout<<"\n\nList :\n";
	obj.show();
	
	cout<<"\n\nTotal Nodes = "<<obj.count();
	
	return 0;
}
