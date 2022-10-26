// Fibonacci Series

#include<iostream>
using namespace std;

int fibo(int n)
{
	if(n <= 1)
	{
		return n;
	}
	return fibo(n-1) + fibo(n-2);
}

int main()
{
	int n;
	cout<<"\nEnter Value = ";
	cin>>n;
	
	cout<<"\n\nSeries\n";
	int i,t3=0,t2=1,t1=0;
	for(i=0; i<=n; i++)
	{
		if(i==0)
		{
			cout<<" "<<t1;
		}
		else if(i==1)
		{
			cout<<" "<<t2;
		}
		else
		{
			t3 = t2+t1;
			t1 = t2;
			t2 = t3;
			cout<<" "<<t3;	
		}
	}
	
	int k;
	cout<<"\n\nEnter k : ";
	cin>>k;
	cout<<"\nKth fibo term is = "<<fibo(k);
	
	return 0;
}
