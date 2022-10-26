// Check if well parenthesize or not

#include<iostream>
#define MAX 20
using namespace std;

class Stack
{
	private:
		char data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int empty()
		{
			if(top == -1)
				return 1;
			return 0;
		}
		int full()
		{
			if(top == MAX)
				return 1;
			return 0;
		}
		void push(int x)
		{
			if(!full())
			{
				top++;
				data[top] = x;
			}
			else
			{
				cout<<"\nStackOverflow";
			}
		}
		int pop()
		{
			if(!empty())
			{
				int x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStackUnderflow";
				return -1;
			}
		}
};

int main()
{
	Stack S;
	
	char expression[30];
	cout<<"\nEnter expression : ";
	cin.getline(expression,28,'\n');
	
	int i=0,flag=0;
	char ch,expn;
	while(expression[i] != '\0')
	{
		expn = expression[i];
		if(expn=='{'||expn=='['||expn=='(')
		{
			S.push(expn);
		}
		if(expn=='}'||expn==']'||expn==')')
		{
			if(!S.empty())
			{
				ch = S.pop();
				if(expn=='{' && ch!='}')
				{
					flag=1;
					break;
				}
				else if(expn=='[' && ch!=']')
				{
					flag=1;
					break;
				}
				else if(expn=='(' && ch!=')')
				{
					flag=1;
					break;
				}
			}
			else	//for expression => (2+3)-3]		//here stack will become empty & flag will remain 0 if not handled
			{
				flag=1;
				break;
			}
		}
		i++;
	}
	if(flag==0 && S.empty())
	{
		cout<<"\n\nExpression is well parenthesized";
	}
	else
	{
		cout<<"\n\nExpression is not well parenthesized";
	}
	
	return 0;
}
