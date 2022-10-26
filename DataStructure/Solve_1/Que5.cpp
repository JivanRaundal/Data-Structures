// Q 5]. 

#include<iostream>
using namespace std;

int print(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else
	{
		return n%10 + print(n/10); 
	}
}

int main()
{
	int num;
	cout<<"\nEnter Number : ";
	cin>>num;
	
	cout<<"\n\nAddition of all digits in "<<num<<" is = "<<print(num);
	return 0;
}
