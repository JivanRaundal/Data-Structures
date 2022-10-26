// Scan & print array recursively

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
		cout<<"\nEnter arr["<<i<<"] : ";
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
		cout<<" "<<*(p+i);
		print(p,n,i+1);
	}
}

int main()
{
	int n;
	cout<<"\nHow many int ? ";
	cin>>n;
	int * p = new int[n];
	scan(p,n,0);
	
	cout<<"\n\nPrinting Array :\n";
	print(p,n,0);
	return 0;
}
