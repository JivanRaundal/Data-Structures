// Q 5]. 

#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

class Stack
{
		char data[MAX];
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
		void push(char x)
		{
			if(full())
			{
				cout<<"\nStack Full";
			}
			else
			{
				top++;
				data[top] = x;
			}
		}
		char pop()
		{
			if(empty())
			{
				cout<<"\nStack Empty";
				return 'n';
			}
			else
			{
				char x;
				x = data[top];
				top--;
				return x;
			}
		}
};

class Expression
{
		char expn[50];
		Stack S;		//composition
	public:
		Expression()
		{
			strcmp(expn,"None");
		}
		
		void get_expn()
		{
			cout<<"\nEnter expression : ";
			cin.getline(expn,48,'\n');
		}
		
		void check_expn()		//fun to check well parenthesis or not
		{
			int i;
			char ch;
			int flag = 0;
			
			for(i=0; expn[i]!='\0'; i++)
			{
				if(expn[i] == '{' || expn[i] == '[' || expn[i] == '(')
				{
					S.push(expn[i]);
				}
				if(expn[i] == '}' || expn[i] == ']' || expn[i] == ')')
				{
					if(!S.empty())
					{
						ch = S.pop();
					
						if(expn[i]=='}' && ch != '{')
						{
							flag = 1;
							break;
						}
						if(expn[i]==']' && ch != '[')
						{
							flag = 1;
							break;
						}
						if(expn[i]==')' && ch != '(')
						{
							flag = 1;
							break;
						}
					}
					else	//for expression => (2+3)-3]	//here stack will become empty & flag will remain 0 if not handled
					{
						flag=1;
						break;
					}
				}
			}
			
			if(flag==0 && S.empty())
			{
				cout<<"\nExpression is in well parenthesis";
			}
			else
			{
				cout<<"\nExpression is not well parenthesis";
			}
		}
};

int main()
{
	Expression obj;
	char ch;
	do
	{
		obj.get_expn();
		obj.check_expn();
		
		cout<<"\n\nDo you want to continue? y/n : ";
		cin>>ch;
		cin.ignore(1);
	}while(ch != 'n');
	return 0;
}
