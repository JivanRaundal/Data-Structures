// Q 6]. print the following pattern recursively.
//		1
//		12
//		123
//		1234
//		12345


#include<iostream>
using namespace std;

void print(int num)
{
	if(num == 0)
	{
		return;
	}
	//cout<<num;
	print(num-1);
	cout<<num;
}

void pattern(int n,int i)
{
	if(n == 0)
	{
		return;
	}
	print(i);
	cout<<"\n";
	pattern(n-1, i+1);
}

int main()
{
	int n = 5;
	pattern(n,1);
	/*int i,j;
	for(i=1; i<=5; i++)
	{
		for(j=1; j<=i; j++)
		{
			cout<<j;
		}
		cout<<"\n";
	}*/
	return 0;
}
