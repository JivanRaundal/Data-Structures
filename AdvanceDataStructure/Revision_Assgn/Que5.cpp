// Q.5] scan a range from user, print addition of only even numbers in the given range.

#include<iostream>
using namespace std;

int add(int x,int y)
{
	if(x > y)
	{
		return 0;
	}
	else
	{
		if(x%2 == 0)
		{
			return x + add(x+1, y);
		}
		return add(x+1, y);
	}
}

int main()
{
	int a,b;
	int ans;
	cout<<"\nEnter range : ";
	cin>>a>>b;
	a < b ? ans = add(a,b) : ans = add(b,a);
	cout<<"\nAddition = "<<ans;
	return 0;
}
