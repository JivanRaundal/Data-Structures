// Q. Push addresses of elements of int type array on stack & print them while unwinding.
// Note - Use the concept of array of pointers.

#include<iostream>
#define MAX 6
using namespace std;

class Stack
{
	private:
		int* data[MAX];		//array of pointers
		int top;
	
	public:
		Stack()
		{
			top = -1;
		}
		
		int full();
		int empty();
		void push(int* p);
		int* pop();
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

void Stack::push(int* p)
{
	if(full())
	{
		cout<<"\nCan't Push, stack full";
	}
	else
	{
		top++;
		data[top] = p;
	}
}

int* Stack::pop()
{
	int * p;
	if(empty())
	{
		cout<<"\nStack Full";
		return p;
	}
	else
	{
		p = data[top];
		top--;
		return p;
	}
}

int main()
{
	int num[6] = {6,18,45,23,37,8};
	Stack S;
	int i;
	int * q;
	
	//pushing addresses on stack
	for(i=0; i<6; i++)
	{
		S.push(&num[i]);
	}
	
	cout<<"\n\nUnwinding Stack :\n";
	while(!S.empty())
	{
		q = S.pop();
		cout<<" "<<*q;
	}
	return 0;
}
