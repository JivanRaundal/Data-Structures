// Q.3] Keep scanning a number from user until user enters -1 using recursion. print addition of all given integers.

#include<iostream>
using namespace std;

int add()
{
	int x;
	cin>>x;
	if(x == -1)
	{
		return 0;
	}
	return x + add();
}

int main()
{
	int ans;
	cout<<"\nKeep entering number & enter -1 to stop :\n";
	ans = add();
	cout<<"\nAddition = "<<ans;
	return 0;
}
