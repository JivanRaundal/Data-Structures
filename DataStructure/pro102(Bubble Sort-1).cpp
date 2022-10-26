// Sorting 

// Bubble Sort :-

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {3,7,6,15,76,22,13,19,25,8};
	
	int i,j,n;
	n = 10;
	
	cout<<"\nBefore Sorting Array :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	//bubble sort
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(num[j] > num[j+1])
			{
				//swap(num[j], num[j+1])
				int temp;
				temp     = num[j];
				num[j]   = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	cout<<"\n\nAfter Sorting Array :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	return 0;
}
