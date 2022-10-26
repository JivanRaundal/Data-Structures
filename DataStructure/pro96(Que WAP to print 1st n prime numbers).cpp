// Q. WAP to print first 'n' prime numbers.

#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"\nEnter number : ";
	cin>>n;
	
	int i,j,flag;
	
	cout<<"\n\nFirst "<<n<<" prime numbers are :\n";
	for(i=2; i<n; i++)
	{
		flag = 0;
		for(j=2; j<i; j++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<" "<<i;
		}
	}

	return 0;
}
