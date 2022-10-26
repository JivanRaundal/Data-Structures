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

int get_priority(char op)		//op => operator whose priority is to be cheked
{
	if(op=='*' || op=='/')		// * & / have same priority
	{
		return 2;				//higher priority
	}
	else if(op=='+' || op=='-')
	{
		return 1;				//lower priority
	}
}

int main()
{
	char infix[30], postfix[30];		//strings
	char st, expn;						//st => operator from stack & expn => operator from expression
	int i=0, j=0;
	Stack S;							//object of stack
	
	cout<<"\nEnter Infix expression :\n";
	cin.getline(infix,28,'\n');
	
	while(infix[i] != '\0')				
	{
		expn = infix[i];		//will need infix[i] everywhere hence copied it in expn
		
		if(expn=='+' || expn=='-' || expn=='*' || expn=='/')
		{
			// Possibilities if expn==operator :-
			//	1. if stack is empty, push operator/expn on stack
			//	2. if stack is not empty, perform st>=expn while stack is not empty
			//  3. if condn 2 fails, push st & expn on stack
			
			if(S.empty())
			{
				S.push(expn);
			}
			else
			{
				while(!S.empty())
				{
					st = S.pop();
					if(get_priority(st) >= get_priority(expn))		//stack operator >= expn operator (comparison)
					{
						//send stack operator in postfix 
						postfix[j] = st;
						j++;
					}
					else		// if st >= expn is false
					{
						//pust st back in stack
						S.push(st);
						break;			//break loop & push expn on stack outside while loop
					}
				}
				S.push(expn);
			}
		}
		else					//means expn is operand, & operands will directly go in postfix
		{
			postfix[j] = expn;
			j++;
		}
		i++;
	}
	
	//As while loop ends here, means infix expression ends, then pop all operators from stack & send them to postfix
	while(!S.empty())
	{
		st = S.pop();
		postfix[j] = st;
		j++;
	}
	//insert '\0' at end of postfix (bcz it is char type string)
	postfix[j] = '\0';
	
	cout<<"\n\nRequired Postfix expression is :\n"<<postfix;
	return 0;
}


