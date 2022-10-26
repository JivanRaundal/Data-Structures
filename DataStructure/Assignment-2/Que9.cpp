// Q 9].

#include<iostream>
using namespace std;

void scan(int *p,int n,int i)
{
	if(i == n)
	{
		return;
	}
	else
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>*(p+i);
		scan(p,n,i+1);
	}
}

void print(int *p,int n,int i)
{
	if(i == n)
	{
		return;
	}
	else
	{
		if(*(p+i)%2 == 0)
		{
			cout<<" "<<*(p+i);
		}
		print(p,n,i+1);
	}
}

int main()
{
	int n;
	cout<<"\nHow many integers? ";
	cin>>n;
	
	int *q = new int[n];
	
	cout<<"\nScanning array\n";
	scan(q,n,0);
	
	cout<<"\nPrinting even numbers in array\n";
	print(q,n,0);
	
	delete q;
	return 0;
}
