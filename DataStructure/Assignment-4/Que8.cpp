// Q 8].

#include<iostream>
#include<string.h>
#define MAX 5
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		
		Student()
		{
			strcpy(name,"None");
			age = 0;
		}
		
		void getdata()
		{
			cin.ignore(1);
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age  : ";
			cin>>age;
		}
		void showdata()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<age;
		}
};

class Node
{
	public:
		Student data;		//composition
		Node * next;
		
		Node()
		{
			data.getdata();
			next = NULL;
		}
};

class Stack
{
		Node * data[MAX];			//stack will store addresses of Node
		int top;
	
	public:
		Stack()
		{
			top = -1;
		}
		
		int full()
		{
			if(top == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		
		int empty()
		{
			if(top == -1)
			{
				return 1;
			}
			return 0;
		}
		
		void push(Node * x)
		{
			if(!full())
			{
				top++;
				data[top] = x;
			}
			else
			{
				cout<<"\nStack Full";
			}
		}
		
		Node* pop()
		{
			Node* x;
			if(!empty())
			{
				x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return x;
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
		
		void create()
		{
			if(head != NULL)
			{
				cout<<"\nList Already created...";
				return;
			}
			
			int n;
			cout<<"\nHow many student's ? ";
			cin>>n;
			if(n < 1)
			{
				cout<<"\nInvalid Number";
				return;
			}
			head = new Node();
			Node * p = head;
			
			for(int i=1; i<=n-1; i++)
			{
				p->next = new Node();
				p = p->next;
			}
		}
		
		void show()
		{
			cout<<"\n\nStudent's List : ";
			if(head == NULL)
			{
				cout<<"\nEmpty List";
				return;
			}
			Node * p = head;
			while(p != NULL)
			{
				p->data.showdata();
				p = p->next;
			}
		}
		
		void rev_show()
		{
			Stack S;
			Node * p = head;
			while(p != NULL)
			{
				S.push(p);
				p = p->next;
			}
			
			cout<<"\n\n***** Unwinding Stack *****";
			cout<<"\n\nStudent's List in reverse order : ";
			while(!S.empty())
			{
				p = S.pop();
				p->data.showdata();
			}
		}
};

int main()
{
	SLL L;
	
	cout<<"\n\nCreating List\n";
	L.create();
	
	L.show();
	
	L.rev_show();
	
	return 0;
}
