// Q 2] Scan 5 integers from user and store them on stack. Now perform addition of all elements while unwinding stack.

#include<iostream>
# define MAX 10
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
		int full();
		int empty();
		void push(int x);
		int pop();
};

int Stack::full()
{
	if(top == MAX-1)
	{
		return 1;
	}
	return 0;
}

int Stack::empty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

void Stack::push(int x)
{
	if(full())
	{
		cout<<"\nStack Full";
	}
	else
	{
		top++;
		data[top] = x;
	}
}

int Stack::pop()
{
	if(empty())
	{
		cout<<"\nStack Empty";
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

int main()
{
	Stack S;
	int i,x;
	
	for(i=1; i<=5; i++)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>x;
		S.push(x);
	}
	
	int sum=0;
	while(!S.empty())
	{
		sum = sum + S.pop();
	}
	cout<<"\n\nAddition = "<<sum;
	return 0;
}
