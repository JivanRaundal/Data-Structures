// Q.2] WAP to find nth fibonacci term recursively.

#include<iostream>
using namespace std;

int fibo(int n)
{
	if(n==1)			//first fibonacci number is 0
	{
		return 0;
	}
	if(n==2)		//second fibonacci number  is 1
	{
		return 1;
	}
	return fibo(n-1) + fibo(n-2);
}

int main()
{
	int n;
	cout<<"\nEnter number : ";
	cin>>n;
	cout<<"\n\n"<<n<<"th fibonacci term = "<<fibo(n);
	return 0;
}
