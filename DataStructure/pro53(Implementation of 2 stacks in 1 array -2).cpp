// Implementing 2 stackes in 1 array :-

#include<iostream>
#define INF 2147483647
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
		
		int empty(int st_no)			//Both stacks will have different empty condition
		{
			if(st_no < 1 || st_no > 2)
			{
				cout<<"\nInvalid stack Number";
				return -1;
			}
			else if(st_no == 1 && top1 == -1)
			{
				return 1;
			}
			else if(st_no == 2 && top2 == MAX)
			{
				return 1;
			}
			return 0;		//if not empty, return 0
		}
		
		int full()						//Both stack will have same full condition
		{
			if(top2 == top1+1)			//OR if(top1 == top2-1)
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
				return INF;
			}
		}
};

int main()
{
	Stack S;
	int x;
	
	S.push(3,5);		//invalid stack no. 3
	S.push(1,10);
	S.push(1,20);
	S.push(2,-28);
	S.push(2,-13);
	S.push(1,30);
	S.push(2,-5);
	
	cout<<"\n\nUnwinding Stack 1 :\n";
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
