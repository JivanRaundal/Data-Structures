// Q 8].

#include<iostream>
using namespace std;

int base_power(int b,int p,int i)
{
	if(i == p)
	{
		return b;
	}
	else
	{
		return b * base_power(b,p,i+1);
	}
}

int main()
{
	int b,p,ans;
	cout<<"\nEnter base term : ";
	cin>>b;
	cout<<"\nEnter power term : ";
	cin>>p;
	
	ans = base_power(b,p,1);
	cout<<"\nAns = "<<ans;
	return 0;
}
