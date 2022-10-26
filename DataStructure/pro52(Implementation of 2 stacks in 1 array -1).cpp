// Implemntation of 2 stacks in 1 Array.

#include<iostream>
#define MAX 5
using namespace std;

class Stack
{
		int data[MAX];
		int top1,top2;
		
	public:
		Stack()
		{
			top1 = -1;
			top2 = MAX;
		}
		
		//Note - both stack's will have different conditions for empty.
		int empty(int st_no)		//st_no => stack number
		{
			if(st_no == 1 && top1 == -1)				//check for stack1
			{
				return 1;
			}
			else if(st_no == 2 && top2 == MAX)			//check for stack2
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		//Note - both stack's will have same condition for full. (hence, no st_no needed)
		int full()
		{
			if(top2 == top1+1)		//OR if(top1 == top2-1)
			{
				return 1;
			}
			return 0;
		}
		
		void push(int st_no, int x)
		{
			if(st_no == 1 && !full())
			{
				top1++;
				data[top1] = x;
			}
			else if(st_no == 2 && !full())
			{
				top2--;
				data[top2] = x;
			}
			else
			{
				cout<<"\nStack Full";
			}
		}
		
		int pop(int st_no)
		{
			if(st_no == 1 && !empty(1))
			{
				int x;
				x = data[top1];
				top1--;
				return x;
			}
			else if(st_no == 2 && !empty(2))
			{
				int x;
				x = data[top2];
				top2++;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return -1;
			}
		}
};

int main()
{
	Stack S;
	int x;
	
	S.push(1,10);
	S.push(1,20);
	S.push(2,-10);
	S.push(1,30);
	S.push(2,-20);
	S.push(2,-30);
	
	cout<<"\n\nUnwinding Stack 1 :\n";
	while(!S.empty(1))
	{
		x = S.pop(1);
		cout<<" "<<x;
	}
	
	cout<<"\n\nUnwinding stack 2 :\n";
	while(!S.empty(2))
	{
		x = S.pop(2);
		cout<<" "<<x;
	}
	
	return 0;
}
