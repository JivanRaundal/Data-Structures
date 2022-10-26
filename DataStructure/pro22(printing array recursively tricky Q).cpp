//

#include<iostream>
using namespace std;

int add(int num[],int i)
{
	if(i<0)
	{
		return 0;
	}
	else
	{
		int x;
		x = num[0] + add(num+1,i-1);
		return x;
	}
}

int main()
{
	int num[] = {5,7,8,2};
	int sum;
	sum = add(num,3);
	cout<<"\nsum = "<<sum;
	return 0;
}
