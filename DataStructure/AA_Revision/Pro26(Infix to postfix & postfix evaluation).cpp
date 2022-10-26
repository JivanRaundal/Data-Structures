// Infix to Postfix & Postfix Evaluation

#include<iostream>
#define MAX 50
using namespace std;

class Stack
{
	private:
		int data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top==MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			return 0;
		}
		void push(int x)
		{
			if(full())
			{
				cout<<"\nStackoverflow";
			}
			else
			{
				top++;
				data[top] = x;
			}
		}
		int pop()
		{
			if(empty())
			{
				cout<<"\nStackunderflow";
				return -1;
			}
			else
			{
				int x;
				x = data[top];
				top--;
				return x;
			}
		}
};

int getPriority(char op)
{
	if(op=='*' || op=='/')
	{
		return 2;
	}
	else if(op=='+' || op=='-')
	{
		return 1;
	}
	else				//for brackets priority will be low due to this they will be pushed back in stack (but not logically correct)
	{
		return 0;
	}
}

void convertToPostfix(char * infix,char * postfix)
{
	Stack S;
	char expn, st;
	int i=0,j=0;
	while(infix[i] != '\0')
	{
		expn = infix[i];
		if(expn=='(' || expn==')')
		{
			if(expn=='(')
			{
				S.push(expn);
			}
			else if(expn == ')')
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
		else if(expn=='+'||expn=='-'||expn=='*'||expn=='/')
		{
			//if stack empty push operator directly on stack
			//if not empty, pop an operator from stack
			//if  [st>=expn], then send st to postfix string & repeate step 2 while stack not empty
			//if  [st<expn], then send stack operator back to stack and also send expn operator on stack
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
					if(getPriority(st) >= getPriority(expn))
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
		else
		{
			//means expn is an operand
			postfix[j] = expn;		
			j++;		
		}
		i++;
	}
	//if infix expression ends, then pop all operators from stack & insert in postfix expression
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	postfix[j] = '\0';
}

int postfixEvaluation(char postfix[])
{
	Stack S;
	int ans=0,i=0;
	int left=0,right=0;
	char expn;
	while(postfix[i] != '\0')
	{
		expn = postfix[i];
		if(expn=='+'||expn=='-'||expn=='*'||expn=='/')
		{
			//pop 2 operands from stack & perform their operator
			// ans = 2nd poped operator 1st poped, & then push the result back in stack.
			//when postfix expn ends, stack will contain only 1 value, & that is the required answer.
			right = S.pop();			//1st poped
			left  = S.pop();			//2nd poped
			switch(expn)
			{
				case '+':
					ans = left + right;
					break;
				case '-':
					ans = left - right;
					break;
				case '*':
					ans = left * right;
					break;
				case '/':
					ans = left / right;
					break;
			}
			S.push(ans);				//push ans back in stack
		}
		else		//expn is an operand, push it to stack in int form (In postfix string we have stored it in char form)
		{
			S.push(expn-48);
		}
		i++;
	}
	//at last stack will contain only 1 value and i.e. the result
	ans = S.pop();
	if(!S.empty())
	{
		cout<<"\nWrong Evaluation";
		return -1;
	}
	return ans;
}

int main()
{
	char infix[50];
	char postfix[50];
	cout<<"\nEnter infix expression : ";
	cin.getline(infix,48,'\n');
	convertToPostfix(infix,postfix);
	cout<<"\n\nInfix Expression = "<<infix<<"\nPostfix Expression = "<<postfix;
	int ans = postfixEvaluation(postfix);
	cout<<"\n\nPostfix Evaluation = "<<ans;
	return 0;
}
