// Q.10]

#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"\nEnter Number : ";
	cin>>num;
	int sum = 0;
	while(num != 0)
	{
		sum = sum + num%10;
		num = num / 10;
	}
	cout<<"\nAddition of digits = "<<sum;
	return 0;
}
