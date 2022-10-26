// Q 7]. Convert infix to postfix & evaluate postfix expression including brackets.

#include<iostream>
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

//prototypes
int get_priority(char op);
void convert_to_postfix(char infix[],char postfix[]);
int evaluate_postfix(char postfix[]);

int main()
{
	char infix[30], postfix[30];
	int res;
	
	cout<<"\n\nEnter Infix Expression :\n";
	cin.getline(infix,28,'\n');
	
	convert_to_postfix(infix, postfix);
	
	cout<<"\n\nRequired Postfix Expression :\n";
	cout<<postfix;
	
	res = evaluate_postfix(postfix);
	cout<<"\n\nResult of Postfix Evaluation is = "<<res; 
	return 0;
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

void convert_to_postfix(char infix[],char postfix[])
{
	char expn,st;
	int i=0,j=0;
	Stack S;
	
	while(infix[i] != '\0')
	{
		expn = infix[i];
		
		if(expn=='(' || expn==')')
		{
			//code for brackets
			if(expn == '(')				//opening bracket '(' direcly go on stack
			{
				S.push(expn);
			}
			else if(expn == ')')		//pop all the operators in postfix until opening bracket ')'
			{
				do
				{
					st = S.pop();
					if(st != '(')
					{
						postfix[j] = st;
						j++;
					}
				}while(st != '(');
			}
		}
		else if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			//code for operators comparison
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
					if(get_priority(st) >= get_priority(expn))		//st op >= expn op (condirion)
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
		else		//expn is operand
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	//here, infix expression ends, now pop all operators from stack & add them in postfix expression.
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	postfix[j] = '\0';
}

int evaluate_postfix(char postfix[])
{
	int left, right;
	int i=0, ans=0;
	char expn;
	Stack S;
	
	while(postfix[i] != '\0')
	{
		expn = postfix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			right = S.pop();
			left  = S.pop();
			
			if(expn == '+')
			{
				ans = left + right;
				S.push(ans);
			}
			else if(expn == '-')
			{
				ans = left - right;
				S.push(ans);
			}
			else if(expn == '*')
			{
				ans = left * right;
				S.push(ans);
			}
			else if(expn == '/')
			{
				ans = left / right;
				S.push(ans);
			}
		}
		else
		{
			S.push(expn-48);
			// (expn-48), bcz operands are store as the char in string
			// hence their ASCII values are stored in stack, to convert them into 'int' do -48 from their ASCII value
		}
		i++;
	}
	
	ans = S.pop();
	if(!S.empty())
	{
		cout<<"\n\nWrong Evaluation";
		return -1;
	}
	return ans;
}




