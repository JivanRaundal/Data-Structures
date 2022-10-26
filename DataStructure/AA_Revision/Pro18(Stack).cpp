// STACK - LIFO (Last In First Out) Data Structure

#include<iostream>
#define MAX 5
using namespace std;

class Stack
{
	private:
		int data[MAX];
		int top;
	
	public:
		Stack()				//intitalize
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
 		cout<<"\n\"Can't Push...StackOverflow\"";	
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
 		cout<<"\n\"Can't pop...StackUnderflow\"";
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
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);
	S.push(50);
	S.push(60);
	
	cout<<"\nUnwinding Stack\n";
	while(!S.empty())
	{
		cout<<S.pop()<<"\n";
	}
	S.pop();
	
	return 0;	
 }
