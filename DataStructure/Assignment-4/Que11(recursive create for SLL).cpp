// Q 11]. WAP to create SLL & implement following functions
//	-recursive create()
//	-recursive show()
//	-recursive show_reverse()
//	-nonrecursive show_reverse()		//for this we are using stack using Linked List

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

class Stack				//Stack using SLL
{
		Node * top;
	
	public:
		Stack()
		{
			top = NULL;
		}
		
		// No full condition
		
		int empty()
		{
			if(top == NULL)
			{
				return 1;
			}
			return 0;
		}
		
		void push(int x)			//addatbeg() in SLL
		{
			Node * p;
			p = new Node(x);
			p->next = top;
			top = p;
		}
		
		int pop()					//delatbeg() in SLL
		{
			if(!empty())
			{
				int x;
				x = top->data;
				Node * p = top;
				top = top->next;
				delete p;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return -1;
			}
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
		
		Node* rec_create()			//using recursion
		{
			char str[10];
			cout<<"\nEnter data or 'STOP' to stop : ";
			cin>>str;
			if(strcmp(str,"STOP") == 0)
			{
				return NULL;
			}
			Node * p;
			p = new Node(atoi(str));
			p->next = rec_create();
			return p;
		}
		
		void create()			//to call create() function -helper
		{
			head = rec_create();
		}
		
		void rec_show(Node * p)
		{
			if(p == NULL)
			{
				return;
			}
			else
			{
				cout<<" "<<p->data;
				rec_show(p->next);
			}
		}
		
		void rec_show_rev(Node * p)
		{
			if(p == NULL)
			{
				return;
			}
			else
			{
				rec_show_rev(p->next);
				cout<<" "<<p->data;
			}
		}
		
		void show()				//helper
		{
			cout<<"\n\nRecursive show in forward order :\n";
			rec_show(head);
			
			cout<<"\n\nRecursive show in reverse order :\n";
			rec_show_rev(head);
		}
		
		void non_rec_show_rev()			//using stack
		{
			Stack S;
			Node * p = head;
			while(p != NULL)
			{
				S.push(p->data);
				p = p->next;
			}
			
			cout<<"\n\nNon-recursive show in reverse order :\n";
			int x;
			while(!S.empty())
			{
				x = S.pop();
				cout<<" "<<x;
			}
		}
};

int main()
{
	SLL L;
	L.create();
	L.show();
	L.non_rec_show_rev();
	return 0;
}
