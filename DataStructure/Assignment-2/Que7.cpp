// Q 7].

#include<iostream>
using namespace std;

void scan(int *q,int n,int i)
{
	if(i == n)
	{
		return;
	}
	else
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>*(q+i);
		scan(q,n,i+1);
	}
}

void print(int * q,int n,int i)
{
	if(i == n)
	{
		return;
	}
	else
	{
		cout<<" "<<*(q+i);
		print(q,n,i+1);
	}
}

int main()
{
	int n;
	cout<<"\nHow many integers? ";
	cin>>n;
	
	int *p = new int[n];
	cout<<"\nScanning values :\n";
	scan(p,n,0);
	
	cout<<"\nPrinting array :\n";
	print(p,n,0);
	
	delete p;
	return 0;
}
