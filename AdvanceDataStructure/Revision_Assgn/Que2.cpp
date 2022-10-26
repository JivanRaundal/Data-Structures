// Q.2] Scan a range from user, print all numbers in the range in ascending order

#include<iostream>
using namespace std;

void print(int x,int y)
{
	if(x > y)
	{
		return;
	}
	cout<<"\n"<<x;
	print(x+1, y);
}

int main()
{
	int a,b;
	cout<<"\nEnter Range : ";
	cin>>a>>b;
	a < b ? print(a,b) : print(b,a);
	return 0;
}

