// Q.3]

#include<iostream>
using namespace std;

int add(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else
	{
		return n + add(n-1);
	}
}

int main()
{
	int n;
	cout<<"\nEnter the number : ";
	cin>>n;
	int ans = add(n);
	cout<<"\nAddition = "<<ans;
	return 0;
}
