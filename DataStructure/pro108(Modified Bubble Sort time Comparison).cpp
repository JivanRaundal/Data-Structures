// Modified Bubble Sort Comparison

#include<iostream>
#define MAX 100000
using namespace std;

int main()
{
	int num[MAX];
	int i,j,temp,flag;
	
	for(i=0; i<MAX; i++)
	{
		num[i] = MAX-i;				
	}
	
	//Modified Bubble sort
	for(i=1; i<MAX; i++)
	{
		flag = 0;
		for(j=0; j<MAX-i; j++)
		{
			if(num[j] > num[j+1])
			{
				temp     = num[j];
				num[j]   = num[j+1];
				num[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
		{
			//Array Sorted
			break;
		}
	}
	
	cout<<"\nSorted";
	return 0;
}


