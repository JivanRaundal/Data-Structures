// Q 3].

#include<iostream>
using namespace std;

int add(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return n + add(n-1);
	}
}

int main()
{
	int ans,num;
	cout<<"\nEnter number : ";
	cin>>num;
	
	ans = add(num);
	cout<<"\nAddition of first "<<num<<" natural numbers = "<<ans;
	return 0;
}
