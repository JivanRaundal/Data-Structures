// Q.6_2] WAP to check whether number is pallindrome or not

#include<iostream>
using namespace std;

int main()
{
	int num,n,digit,rev=0;
	cout<<"\nenter number : ";
	cin>>num;
	n = num;
	while(num > 0)
	{
		digit = num%10;
		rev = rev*10 + digit;
		num = num/10;
	}
	cout<<"\nReverse number = "<<rev;
	if(n == rev)
	{
		cout<<"\nNumber is pallindrome";
	}
	else
	{
		cout<<"\nNumber is not pallindrome";
	}
	return 0;
}
