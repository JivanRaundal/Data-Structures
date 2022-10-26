// Double Recursion 
// examples :-

#include<iostream>
using namespace std;

void fun(int x);

int main()
{
	fun(5);
	return 0;
}

void fun(int x)
{
	if(x >= 1)
	{
		fun(x-2);			//----(1)
		x--;
		cout<<" "<<x;
		fun(x-2);			//----(2)
	}
}
