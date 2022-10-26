// Stack as an array of pointers

#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
	private:
		int* data[MAX];				//array of pointers
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top==MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			return 0;
		}
		void push(int* x)
		{
			if(full())
			{
				cout<<"\nStackverflow";
			}
			else
			{
				top++;
				data[top] = x;
			}
		}
		int* pop()
		{
			int * x;
			if(empty())
			{
				cout<<"\nStackunderflow";
				return x; 
			}
			else
			{
				x = data[top];
				top--;
				return x;
			}
		}
		void displayStack()
		{
			if(empty())
			{
				cout<<"\nStack Empty";
			}
			for(int i=top; i>=0; i--)
			{
				cout<<"\n"<<(long long)data[i];	
			}	
		}
};

int main()
{
	Stack S;
	int num[5]={2,5,8,9,3};
	for(int i=0; i<5; i++)
	{
		S.push(&num[i]);
		S.displayStack();
		cout<<"\n-------";
	}
	cout<<"\nUnwinding Stack\n";
	while(!S.empty())
	{
		cout<<*(S.pop())<<"\n";
	}
	S.displayStack();
	return 0;
}
