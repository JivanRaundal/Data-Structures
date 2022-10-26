#include<iostream>
#define MAX 30
using namespace std;

class Stack
{
	private:
		char data[MAX];
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
		void push(char x)
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
		char pop()
		{
			if(empty())
			{
				cout<<"\nStackundeflow";
				return -1;
			}
			else
			{
				char x;
				x = data[top];
				top--;
				return x;
			}
		}
};

int main()
{
	Stack S;
	char str[30];
	cout<<"\nEnter String : ";
	cin.getline(str,28,'\n');
	cout<<"\nString = "<<str;
	int i=0;
	while(str[i] != '\0')
	{
		S.push(str[i]);
		i++;
	}
	cout<<"\n\nReverse String = ";
	while(!S.empty())
	{
		cout<<S.pop();
	}
	return 0;
}

