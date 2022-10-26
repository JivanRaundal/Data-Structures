// Q.2]

#include<iostream>
using namespace std;

int fact(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n-1);
	}
}

int main()
{
	int n;
	cout<<"\nEnter the number : ";
	cin>>n;
	
	cout<<"\n"<<n<<"! factorial = "<<fact(n);
	return 0;
}
