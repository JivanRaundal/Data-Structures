// Q 6]. WAP to scan infix expression from user. Convert it into postfix expression. Evaluate postfix expression.
//		 (Without Brackets)

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

// Prototypes
int get_priority(char op);
void convert_to_postfix(char infix[], char postfix[]);
int evaluate_postfix(char postfix[]);

int main()
{
	char infix[30], postfix[30];
	int res;
	
	cout<<"\n\nEnter Infix Expression :\n";
	cin.getline(infix,28,'\n');
	
	convert_to_postfix(infix,postfix);
	
	cout<<"\n\nRequired Postfix Expression is :\n";
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
	char expn, st;
	int i=0, j=0;
	Stack S;
	
	while(infix[i] != '\0')
	{
		expn = infix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
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
					if(get_priority(st) >= get_priority(expn))		//stack op >= expn op (condition)
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
		else						//means expn is operand & operands directly go in postfix expression
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	//infix expression ends here, now pop all operators from stack & add them in postfix expression.
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	postfix[j] = '\0';		//insert '\0' at end of postfix string
}

int evaluate_postfix(char postfix[])
{
	int left,right;
	char expn;
	int i=0, ans=0;
	Stack S;
	
	while(postfix[i] != '\0')
	{
		expn = postfix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			//pop 2 operands from stack & perform operation on them & then push result back to stack.
			right = S.pop();	//1st poped operand
			left  = S.pop();	//2nd poped operand
			
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
		else		//expn is operand & operands go on stack for evaluation
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
		cout<<"\nWrong Evaluation";
		return -1;
	}
	return ans;
}


