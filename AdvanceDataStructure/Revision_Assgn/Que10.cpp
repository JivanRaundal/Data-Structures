// Q.10] WAP to copy one array into another array recursively.

#include<iostream>
using namespace std;

void getdata(int * p,int i)
{
	if(i==-1)
	{
		return;
	}
	getdata(p, i-1);
	cin>>*(p+i);
}

void copy(int * p,int * q,int i)
{
	if(i==-1)
	{
		return;
	}
	*(p+i) = *(q+i);			//copy during recursion
	copy(p, q, i-1);
	//*(p+i) = *(q+i);			//copy during backtracking
}

void print(int * p,int i)
{
	if(i==-1)
	{
		return;
	}
	print(p,i-1);
	cout<<" "<<*(p+i);
}

int main()
{
	int arr[8];
	cout<<"\nEnter array elements :\n";
	getdata(arr, 7);
	//copy arr array into num array
	int num[8];
	copy(num, arr, 7);
	cout<<"\nCopied num array elements :\n";
	print(num, 7);
	return 0;
}
