// Q 1]. 2)

#include<iostream>
using namespace std;

void print(int x)
{
	if(x==0)
	{
		return;
	}
	else
	{
		print(x-1);
		cout<<"\n"<<x;
	}
}

int main()
{
	print(10);
	return 0;
}
