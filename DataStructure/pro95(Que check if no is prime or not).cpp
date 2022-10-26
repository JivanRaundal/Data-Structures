// Q. WAP to check if given number is prime or not.

#include<iostream>
using namespace std;

int main()
{
	int num;
	
	cout<<"\nEnter number : ";
	cin>>num;
	
	if(num>=0 && num<=1)
	{
		cout<<"\n 0 & 1 are neither prime nor composite";
	}
	else				//number is greater than 1
	{
		int i,flag=0;
		for(i=2; i<num; i++)
		{
			if(num%2 == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<"\n"<<num<<" is prime number";
		}
		else			//flag==1
		{
			cout<<"\n"<<num<<" is not prime number";
		}
	}
	return 0;
}
