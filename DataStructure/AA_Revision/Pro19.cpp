// Scan a number from user. Print it's binary using stack.

#include<iostream>
#define MAX 10
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
				cout<<"\nStackundeflow";
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

int main()
{
	Stack S;
	int n;
	cout<<"\nEnter Number : ";
	cin>>n;
	while(!S.full())
	{
		S.push(n%2);
		n = n/2;
	}
	cout<<"\n\nBinary of number = ";
	while(!S.empty())
	{
		cout<<S.pop()<<" ";
	}
	return 0;
}

