// Q. Scan an infix expression from user. Expression will contain only 4 operations (+,-,*,/).
//	  Each operand will be of single digit. WAP to convert given infix expression into postfix.

//	INFIX TO POSTFIX USING STACK

#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
		int data[MAX];		//int => can work with both char & int types. (char for conversion & int for evaluation)
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
		void push(int x)
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
		int pop()
		{
			if(!empty())
			{
				int x;
				x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return -1;
			}
		}
};

int get_priority(char op)
{
	if(op=='*' || op=='/')
	{
		return 2;
	}
	else if(op=='+' || op=='-')
	{
		return 1;
	}
}

int main()
{
	char infix[30], postfix[30];
	char st,expn;
	int i=0, j=0;
	Stack S;
	
	cout<<"\nEnter Infix expression :\n";
	cin.getline(infix,28,'\n');
	
	while(infix[i] != '\0')
	{
		expn = infix[i];
		
		if(expn=='(' || expn==')')
		{
			if(expn == '(')			//opening bracket '(' direcly go on stack
			{
				S.push(expn);
			}
			else if(expn == ')')	//pop all the operators in postfix until opening bracket ')'
			{
				do
				{
					st = S.pop();
					if(st != '(')
					{
						postfix[j] = st;
						j++;
					}
				}
				while(st != '(');
			}
		}
		
		else if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			if(S.empty())
			{
				S.push(expn);
			}
			else
			{
				while(!S.empty())
				{
					st = S.pop();
					if(st == '(')
					{
						S.push(st);
						break;
					}
					if(get_priority(st) >= get_priority(expn))
					{
						postfix[j] = st;
						j++;
					}
					else
					{
						S.push(st);
						break;
					}
				}
				S.push(expn);
			}
		}
		else		//expn is operand, & operand will go in postfix expression
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	//As infix expression ends here, pop all operators from stack & send them in postfix expression
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	
	postfix[j] = '\0';		//add '\0' at end of postfix string
	
	cout<<"\n\nRequired Postfix expression is :\n"<<postfix;
	return 0;
}


