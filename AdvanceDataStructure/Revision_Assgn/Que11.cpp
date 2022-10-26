// WAP to copy one array into another array recursively.

#include<iostream>
using namespace std;

void copy(int * p,int * q,int i)
{
	if(i==-1)
	{
		return;
	}
	copy(p, q, i-1);
	*(p+i) = *(q+i);
}

int main()
{
	int n;
	cout<<"\nHow many integers? ";
	cin>>n;
	int * arr = new int[n];
	cout<<"\nEnter array elements :\n";
	for(int i=0; i<n; i++)
	{
		cin>>*(arr+i);			//cin>>arr[i];
	}
	//coping one array into another
	int * num = new int[n];
	copy(num, arr, n-1);
	cout<<"\nCoied num array :\n";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<num[i];			//cout<<*(num+i);
	}
	return 0;
}
