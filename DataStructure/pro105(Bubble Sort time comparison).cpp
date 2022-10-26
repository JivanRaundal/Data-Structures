// Bubble Sort Comparison

#include<iostream>
#define MAX 10
using namespace std;

int main()
{
	int num[MAX];
	int i,j,temp;
	
	for(i=0; i<MAX; i++)
	{
		num[i] = MAX-i;				//Initializing array in descending order
	}
	
	//Bubble sort
	for(i=1; i<MAX; i++)
	{
		for(j=0; j<MAX-i; j++)
		{
			if(num[j] > num[j+1])
			{
				temp     = num[j];
				num[j]   = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	cout<<"\nSorted";
	return 0;
}


