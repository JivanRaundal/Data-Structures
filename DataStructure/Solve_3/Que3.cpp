// Q 3].

#include<iostream>
#define MAX 5
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

int main()
{
	Stack S;
	int x;
	
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);
	S.push(50);
	S.push(60);
	
	cout<<"\n\nUnwinding Stack :\n";
	while(!S.empty())
	{
		x = S.pop();
		cout<<" "<<x;
	}
	return 0;
}
