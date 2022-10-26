// Q 10]. 

#include<iostream>
using namespace std;

int add(int num)
{
	if(num == 0)
	{
		return 0;
	}
	else
	{
		return num%10 + add(num/10);
	}
}

int main()
{
	int num,ans;
	cout<<"\nEnter number : ";
	cin>>num;
	
	ans = add(num);
	cout<<"\nAddition of all digits in number = "<<ans;
	return 0;
}
