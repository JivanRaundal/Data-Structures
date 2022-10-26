#include<iostream>
using namespace std;

int add(int * p,int n)
{
	if(n == -1)
	{
		return 0;
	}
	else
	{
		return *(p+n) + add(p,n-1);
	}
}

int main()
{
	int num[] = {5,7,8,2};
	int sum;
	sum = add(num,3);
	cout<<"\nAddition = "<<sum;
	return 0;
}
