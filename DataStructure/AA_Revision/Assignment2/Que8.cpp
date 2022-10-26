// Q.8]

#include<iostream>
using namespace std;

int calculate(int base,int pow)
{
	if(pow == 0)
	{
		return 1;
	}
	else
	{
		return base * calculate(base, pow-1);
	}
}

int main()
{
	int base,pow;
	cout<<"\nEnter base & power : ";
	cin>>base>>pow;
	cout<<"\n"<<base<<" raised to "<<pow<<" = "<<calculate(base, pow);
	return 0;
}
