// Q. create array of n integers. scan array from user & print array.

#include<iostream>
using namespace std;

/*void print(int *q, int n)	//----(1)
{
	if(n == 0)
	{
		return;
	}
	cout<<" "<<*q;
	print(q+1, n-1);
}*/

void print(int *q, int i)	//----(2)
{
	if(i == -1)
	{
		return;
	}
	print(q, i-1);
	cout<<" "<<*(q+i);
}

int main()
{
	int n;
	cout<<"\nHow many integers? ";
	cin>>n;
	int * p = new int[n];
	cout<<"\nEnter values : ";
	for(int i=0; i<n; i++)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>*(p+i); 
	}
	
	cout<<"\nArray :\n";
	//print(p,n);		//----(1)
	print(p, n-1);	//----(2)
	return 0;
}
