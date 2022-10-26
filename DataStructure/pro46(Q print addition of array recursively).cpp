// Q. WAP to print addition of all elements in an array of 8 integers recursively.

#include<iostream>
using namespace std;

int add(int *p,int i);

int main()
{
	int num[8] = {44,7,8,12,54,89,20,42};
	int ans;
	ans = add(num,7);
	cout<<"\nAddition of all elements in an array = "<<ans;
	return 0;
}

int add(int *p,int i)
{
	if(i == -1)		//OR i<0
	{
		return 0;
	}
	return *(p+i) + add(p,i-1);
}
