// Q 1] Scan a string from user, print it in reverse order using stack.

#include<iostream>
# define MAX 50
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
		int full();
		int empty();
		void push(char x);
		char pop();
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

void Stack::push(char x)
{
	if(full())		//full() fun will work for calling object of push() function
	{
		cout<<"\nStack Full";
	}
	else
	{
		top++;
		data[top] = x;
	}
}

char Stack::pop()
{
	if(empty())
	{
		cout<<"\nStack Empty";
		return '\n';		//return anything to just satisy the returntype ..as this condn will never get true  
	}
	else
	{
		char x = data[top];
		top--;
		return x;	
	}
}

int main()
{
	Stack S;
	char str[50];
	int i=0;
	char ch;
	
	cout<<"\nEnter String : ";
	cin.getline(str,48,'\n');
	cout<<"\n\nOriginal String = "<<str;
	
	while(str[i] != '\0')
	{
		S.push(str[i]);
		i++;
	}
	
	cout<<"\n\nReverse String = ";
	while(!S.empty())
	{
		ch = S.pop();
		cout<<ch;
	}
	return 0;
}
