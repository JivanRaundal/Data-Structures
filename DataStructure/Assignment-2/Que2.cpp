// Q 2].

#include<iostream>
using namespace std;

int fact(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n-1);
	}
}

int main()
{
	int num,ans;
	cout<<"\nEnter number : ";
	cin>>num;
	
	ans = fact(num);
	cout<<"\n"<<num<<" factorial = "<<ans;
	return 0;
}
