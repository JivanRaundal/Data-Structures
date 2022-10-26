// STACK

// Q. Scan a number from user, print it's binary using stack.

#include<iostream>
#define MAX 16		//MACRO
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
		//void displayStack();
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
	int num,x;
	
	cout<<"\nEnter number to convert into binary : ";
	cin>>num;
	
	//push binary digits of number on stack
	while(num > 0)
	{
		S.push(num%2);
		num = num/2;
	}
	
	//pop binary digits of number from stack
	cout<<"\nBinary of number = ";
	while(!S.empty())
	{
		x = S.pop();
		cout<<x;
	}
	return 0;
}

