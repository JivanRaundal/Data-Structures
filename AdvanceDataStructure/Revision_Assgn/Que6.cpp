// Q.6] Scan a number from user, print addition of all digits in number.

#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"\nenter number : ";
	cin>>num;
	int add=0;
	while(num > 0)
	{
		add = add + num%10;
		num = num / 10;
	}
	cout<<"\nAddition of all digits in  number = "<<add;
	
	return 0;
}
