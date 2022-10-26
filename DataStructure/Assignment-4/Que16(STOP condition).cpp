// Q 16].

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
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
};

class SLL
{
		Node * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void addatend(int x)
		{
			if(head == NULL)
			{
				head = new Node(x);
			}
			else
			{
				Node * p = head;
				while(p->next != NULL)
				{
					p = p->next;
				}
				p->next = new Node(x);
			}
		}
		
		void show()
		{
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
		
		int search(int x)
		{
			if(head == NULL)
			{
				return 0;
			}
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
		
		void merge(SLL T1,SLL T2)
		{
			Node * p = T1.head;
			Node * q = T2.head;
			
			while(p != NULL && q != NULL)
			{
				if(p->data < q->data)
				{
					this->addatend(p->data);
					p = p->next;
				}
				else
				{
					this->addatend(q->data);
					q = q->next;
				}
			}
			
			while(p != NULL)
			{
				this->addatend(p->data);
				p = p->next;
			}
			
			while(q != NULL)
			{
				this->addatend(q->data);
				q = q->next;
			}
			
			cout<<"\n\nLists are merged successfully";
		}
};

int main()
{
	SLL L1,L2,L3;
	// even numbers will go in L1
	//odd numbers will go in L2
	//L1 & L2 will be merged in L3
	int n;
	char str[10];
	
	cout<<"\nKeep entering numbers or enter -1 to stop :\n";
	while(1)
	{
		cin>>str;
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		n = atoi(str);
		if(L1.search(n) || L2.search(n))		//i.e. if number is already present in any list, can't add it
		{
			cout<<n<<" already exits, enter another number\n";
		}
		else									//i.e. number is not present in any list
		{
			if((n%2) == 0)		//i.e. if number is even then add it to L1
			{
				L1.addatend(n);
			}
			else				//i.e. if number is odd then add it to L2
			{
				L2.addatend(n);
			}
		}
	}
	
	cout<<"\n\nList1 :\n";
	L1.show();
	
	cout<<"\n\nList2 :\n";
	L2.show();
	
	L3.merge(L1,L2);		//L1 & L2 will be merged in L3 in such a way that L3 will be sorted
	
	cout<<"\n\nList3 :\n";
	L3.show();
	
	return 0;
}
