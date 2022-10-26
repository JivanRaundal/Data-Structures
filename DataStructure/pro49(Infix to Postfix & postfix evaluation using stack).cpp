// Q. Infix to Postfix Conversion & evaluation of postfix expression Using Stack.

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
int evaluate_postfix(char postfix[]);

int main()
{
	char infix[30], postfix[30];
	char st, expn;
	int i=0,j=0;
	Stack S;
	
	cout<<"\nEnter Infix Expression :\n";
	cin.getline(infix,28,'\n');
	
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
		else	//expn is operand
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	//as infix expression ends here, pop all operators from stack in postfix expression.
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	
	postfix[j] = '\0';
	
	cout<<"\n\nRequired Postfix expression is :\n"<<postfix;
	
	//evaluating Postfix expression
	int ans = evaluate_postfix(postfix);
	cout<<"\n\nResult of postfix evaluation is = "<<ans;
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

//Note => for evaluation, operands go in stack, not operators
int evaluate_postfix(char postfix[])
{
	int left, right;		// left=> operand1 (2nd popped element), right=> operand2 (1st poped element)
	char expn;
	int ans=0, i=0;
	Stack S;
	
	while(postfix[i] != '\0')
	{
		expn = postfix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			//code here to evaluate
			right = S.pop();		//1st popped will go in right
			left  = S.pop();		//2nd popped will go in left
			
			if(expn == '+')
			{
				ans = left + right;		//OR S.push(left + right);
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
		else		//expn is operand, then operands will go on stack for evaluation
		{
			S.push(expn-48);
			// (expn-48), bcz operands are store as the char in string
			// hence their ASCII values are stored in stack, to convert them into 'int' do -48 from their ASCII value
		}
		i++;
	}
	
	ans = S.pop();
	//at last only one element will be remain in stack & that will be result/answer.
	//If less than 1 or more than 1 values are present in stack after evaluation, then code is wrong. 
	if(!S.empty())
	{
		cout<<"\n\nWrong Evaluation";
		return -1;
	}
	return ans;
}


