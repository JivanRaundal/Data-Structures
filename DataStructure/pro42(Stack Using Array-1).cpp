//	STACK USING ARRAY
// STACK follows LIFO (last in first out) principle OR FILO(first in last out)

// NOTE :- -size of array/stack = MAX
//         -index of last element = MAX-1
//         -top will always represent index of lastly inserted element in stack

#include<iostream>
#define MAX 10		//MACRO
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
		
		int  full();			//will return 1 if stack is full, else return 0
		int  empty();			//will return 1 if stack is empty, else return 0
		void push(int x);		//will push/insert element on top of stack
		int  pop();				//will pop/remove element from stcak
		void displayStack();	//will print all the elements present inside the stack
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
	if(full())			//full() fun will work for calling object of push() fun
	{
		cout<<"\nCan't push...Stack Overflow";
	}
	else
	{
		top++;
		data[top] = x;		//OR data[++top] = x;
	}
}

int Stack::pop()
{
	if(empty())		  //empty() fun will work for calling object of pop() fun
	{
		cout<<"\nCan't pop...Stack Underflow";
		return -1;
	}
	else
	{
		int x;
		x = data[top];
		top--;
		return x;		//return pop element
	}
}

// OR
/*int Stack::pop()
{
	if(!empty())
	{
		int x;
		x = data[top];
		top--;
		return x;
	}
} */

void Stack::displayStack()
{
	cout<<"\n\nStack :\n";
	int i;
	for(i=0; i<=top; i++)		//OR for(i=top; i>=0; i--)
	{
		cout<<" "<<data[i];
	}
}

int main()
{
	Stack S;
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);
	
	S.displayStack();
	
	int x;
	cout<<"\n\nPoped elements are :\n";
	x = S.pop();
	cout<<" "<<x;
	x = S.pop();
	cout<<" "<<x;
	x = S.pop();
	cout<<" "<<x;
	x = S.pop();
	cout<<" "<<x;
	
	S.displayStack();
	
	return 0;
}
