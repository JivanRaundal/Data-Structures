// Double Recursion 
// examples :-

#include<iostream>
using namespace std;

void fun(int x);

int main()
{
	fun(1);
	return 0;
}

void fun(int x)
{
	if(x >= 3)
	{
		return;
	}
	else
	{
		cout<<" "<<x;
		fun(x+1);			//----(1)
		cout<<" "<<x;
		fun(x+2);			//----(2)
		cout<<" "<<x;
	}
}
