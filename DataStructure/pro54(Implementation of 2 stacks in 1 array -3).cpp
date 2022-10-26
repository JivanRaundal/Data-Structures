// Implementation of 2 stacks in 1 array :-

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
		
		int empty(int st_no)
		{
			if(st_no == 1 && top1 == -1)
			{
				return 1;
			}
			else if(st_no == 2 && top2 == MAX)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		int full()
		{
			if(top2 == top1+1)
			{
				return 1;
			}
			return 0;
		}
		
		void push(int st_no,int x)
		{
			if(!full())
			{
				if(st_no == 1)
				{
					top1++;
					data[top1] = x;
				}
				else if(st_no == 2)
				{
					top2--;
					data[top2] = x;
				}
				else
				{
					cout<<"\nInvalid Stack Number "<<st_no;
				}
			}
			else 
			{
				cout<<"\nStack Full";
			}
		}
		
		int pop(int st_no)
		{
			if(!empty(st_no))
			{
				int x;
				if(st_no == 1)
				{
					x = data[top1];
					top1--;
				}
				else if(st_no == 2)
				{
					x = data[top2];
					top2++;
				}
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
	S.push(2,-20);
	S.push(1,30);
	S.push(2,-30);
	
	cout<<"\nUnwniding Stack 1 :\n";
	while(!S.empty(1))
	{
		x = S.pop(1);
		cout<<" "<<x;
	}
	
	cout<<"\n\nUnwinding Stack 2 :\n";
	while(!S.empty(2))
	{
		x = S.pop(2);
		cout<<" "<<x;
	}
	return 0;
}
