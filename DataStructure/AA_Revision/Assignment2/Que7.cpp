// Q.7]

#include<iostream>
using namespace std;

void scan(int * p,int n)
{
	if(n == -1)
	{
		return;
	}
	else
	{
		scan(p, n-1);
		cin>>*(p+n);
	}
}

void print(int * p,int n)
{
	if(n == -1)
	{
		return;
	}
	else
	{
		print(p, n-1);
		cout<<" "<<*(p+n);
	}
}

int main()
{
	int n;
	cout<<"\nEnter value of n : ";
	cin>>n;
	int * p = new int[n];
	cout<<"\nScanning Array :\n";
	scan(p, n-1);
	cout<<"\nPrinting Array :\n";
	print(p, n-1);
	return 0;
}
