// Infix to Prefix for single digit operand  -without including bracket's condition.
// Evaluation of Prefix expression

// Rules to convert infix into prefix :-
// 1. Reverse the given infix expression.
// 2. Reverse brackets also if any. (we will avoid this for now)
// 3. Convert resulting expression into postfix expression.
// 4. Reverse resulting posfix expression. (this will give prefix expn)

// Rules for evaluation of prefix expression :-
// 0. Evaluate from Right to Left OR Reverse the prefix expression & evaluate from left to right.
// 1. Operand goes in stack, not operator.
// 2. When you see operator in prefix expn, pop 2 operands from stack.
//	  left operand  = 1st poped element
//	  right operand = 2nd poped element
//    perform the operation => eg- res = left + right
// 3. After Operation Push result back in stack.
// 4. After end of prefix expn, stack contains only 1 value. That is your result.


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

int evaluate_prefix(char prefix[])
{
	// Method-1 => Reverse prefix & then go from left to right.	
	// Method-2 => Evaluate from right to left. (we will go with this)
	int left, right;
	int i = strlen(prefix)-1;		//to evaluate from right to left
	int ans = 0;
	char expn;
	Stack S;
	
	while(i>=0)
	{
		expn = prefix[i];
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			left  = S.pop();		//1st poped will go in left
			right = S.pop();		//2nd poped will go in right

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
		else			//expn is operand & operands go on stack for evaluation
		{
			S.push(expn-48);
			// (expn-48), bcz operands are store as the char in string
			// hence their ASCII values are stored in stack, to convert them into 'int' do -48 from their ASCII value
		}
		i--;					//going from right to left
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

int main()
{
	char infix[30], postfix[30], prefix[30];
	int ans;
	
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
	
	//Evaluation of prefix expression
	ans = evaluate_prefix(prefix);
	cout<<"\n\nResult of prefix evaluation is = "<<ans;
	
	return 0;
}
