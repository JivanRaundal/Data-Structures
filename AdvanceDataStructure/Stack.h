// Templatized Stack

#include<iostream>
#define MAX 50
using namespace std;

template<class myType>
class Stack
{
	private:
		myType data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top == -1)
				return 1;
			return 0;
		}
		void push(myType x)
		{
			if(!full())
			{
				top++;
				data[top] = x;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		myType pop()
		{
			myType x;
			if(!empty())
			{
				x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStack is empty";
				return x;
			}
		}
};

