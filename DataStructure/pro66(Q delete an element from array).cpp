// Q. Scan a number from user, delete that number from array & shift remaining elements to left side.

#include<iostream>
using namespace std;

int main()
{
	int i,j,x;
	int num[8] = {7,13,9,9,8,21,9,16};
	
	cout<<"\n\nBefore deletion :\n";
	for(i=0; i<8; i++)
	{
		cout<<" "<<num[i];
	}
	
	cout<<"\n\nEnter number you want to delete fromt array : ";
	cin>>x;
	
	for(i=0; i<=7; i++)
	{
		if(num[i] == x)
		{
			for(j=i; j<7; j++)
			{
				num[j] = num[j+1];			//shifting of elements
			}
			num[j] = 0;						//make last elements 0 after deletion
			//break;						//if you only want to delete 1st occurence of that number
			i--;							//i--, Bcz if same element occurs continuosly
		}
	}
	
	cout<<"\n\nAfter deletion :\n";
	for(i=0; i<8; i++)
	{
		cout<<" "<<num[i];
	}
	return 0;
}
