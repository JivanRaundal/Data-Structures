// Q 5]. Scan a number from user. print it's 16 bit binary presentation using Stack.

#include<iostream>
# define MAX 20
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
	int num,x,i;
	
	cout<<"\nEnter Number : ";
	cin>>num;
	
	i=0;
	while(i<16)
	{
		S.push(num%2);
		num = num/2;
		i++;
	}
	cout<<"\n\nBinary of number = ";
	while(!S.empty())
	{
		x = S.pop();
		cout<<x;
	}
	return 0;
}
