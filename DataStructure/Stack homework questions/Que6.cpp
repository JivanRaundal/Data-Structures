// Q 6]. Find n! (n factorial) using recursion. (Do not use Stack)

#include<iostream>
using namespace std;

int factorial(int x);

int main()
{
	int n,fact;
	cout<<"\nEnter Number : ";
	cin>>n;
	fact = factorial(n);
	cout<<"\nFactorial of "<<n<<" is = "<<fact;
	return 0;
}

int factorial(int x)
{
	if(x == 0)
	{
		return 1;
	}
	else
	{
		return x * factorial(x-1);
	}
}
