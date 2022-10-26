// Double Recursion 
// examples :-

#include<iostream>
using namespace std;

void fun(int x);

int main()
{
	fun(3);
	return 0;
}

void fun(int x)
{
	if(x > 0)
	{
		cout<<" "<<x;
		fun(x-1);
		x--;
		fun(x-1);
		cout<<" "<<x;
	}
}
