// Selection Sort Comparison

#include<iostream>
#define MAX 1000
using namespace std;

int main()
{
	int num[MAX];
	int i,j,temp;
	
	for(i=0; i<MAX; i++)
	{
		num[i] = MAX-i;				//Initializing array in descending order
	}
	
	//selection sort
	for(i=0; i<MAX; i++)
	{
		for(j=i+1; j<MAX; j++)
		{
			if(num[i] > num[j])
			{
				temp   = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	
	cout<<"\nSorted";
	return 0;
}


