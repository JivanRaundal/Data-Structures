// Q.1] WAP to print 1st n natural numbers

#include<iostream>
using namespace std;

void print(int);

int main()
{
	int n;
	cout<<"\nEnter value of n : ";
	cin>>n;
	print(n);
	return 0;
}

void print(int x)
{
	if(x == 0)
	{
		return;
	}
	else
	{
		print(x-1);
		cout<<"\n"<<x;
	}
}
