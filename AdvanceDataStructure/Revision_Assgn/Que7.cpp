// Q.7] Scan array of 6 integers using recursive function.

#include<iostream>
using namespace std;

void scan(int * p,int i)
{
	if(i == -1)
	{
		return;
	}
	scan(p, i-1);
	cin>>*(p+i);
}

void print(int * p,int i)
{
	if(i == -1)
	{
		return;
	}
	print(p, i-1);
	cout<<" "<<*(p+i);
}

int main()
{
	int arr[6];
	cout<<"\nEnter array elements :\n";
	scan(arr,5);
	cout<<"\nPrinting array elements :\n";
	print(arr,5);
	return 0;
}
