// Infix to Prefix for single digit operand  -without including bracket's condition.

// Rules to convert infix into prefix :-
// 1. Reverse the given infix expression.
// 2. Reverse brackets also if any. (we will avoid this for now)
// 3. Convert resulting expression into postfix expression.
// 4. Reverse resulting posfix expression. (this will give prefix expn)



#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

class Stack
{
		int data[MAX];
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

void reverse_str(char str[])
{
	int i=0,j=0;
	char temp[30];
	i = strlen(str)-1;
	while(i>=0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	//now temp will contain reverse string 
	strcpy(str,temp);
}

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

void convert_to_postfix(char infix[], char postfix[])
{
	char st,expn;
	int i=0,j=0;
	Stack S;
	
	while(infix[i] != '\0')
	{
		expn = infix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
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
					if(get_priority(st) > get_priority(expn))	//Note condn => stack > expn (not stack >= expn)
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
		else			//expn is an operand & operands directly go in postfix expression 
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	// As infix expression ends here, pop all operators from stack & send them in postfix expression
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	postfix[j] = '\0';		//insert '\0' at end of string
	
	cout<<"\n\nConverted Postfix is :\n"<<postfix;
}

int main()
{
	char infix[30], postfix[30], prefix[30];
	
	cout<<"\nEnter infix expression :\n";
	cin.getline(infix,28,'\n');
	
	// Rule-1 - reverse the infix expression
	reverse_str(infix);						//this function will reverse the string
	cout<<"\n\nReverse of infix :\n"<<infix;
	
	// Rule-3 - convert resulting infix into postfix expression
	convert_to_postfix(infix,postfix);		//this function will convert the infix into postfix
	
	//Rule-4 - Reverse resulting postfix expression & result we get by reversing postfix expn will be Prefix expn.
	reverse_str(postfix);
	strcpy(prefix,postfix);
	
	cout<<"\n\nRequired Prefix Expression is :\n"<<prefix;
	
	
	return 0;
}

