//Bubble Sort Comparison

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {1,2,3,4,6,5,7,8,9,10};
	int i,j,temp,n=10;
	int iterations=0;
	
	cout<<"\nArray Before Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];				
	}
	
	// Bubble sort
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(num[j] > num[j+1])
			{
				temp     = num[j];
				num[j]   = num[j+1];
				num[j+1] = temp;
			}
			iterations++;
		}
	}
	
	cout<<"\n\nArray After Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	cout<<"\n\nTotal Iterarions = "<<iterations;
	return 0;
}


