// Shell Sort

#include<iostream>
using namespace std;

int main()
{
	int num[10];
	int n=10,i;
	
	//Initialize array in descending order
	for(i=0; i<n; i++)
	{
		num[i] = n-i;
	}
	
	cout<<"\n\nArray Before Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	//shell sort
	int j,step,temp;
	
	for(step=n/2; step>0; step=step/2)
	{
		for(i=step; i<n; i++)
		{
			temp = num[i];
			for(j=i-step; j>-1; j=j-step)
			{
				if(num[j] > temp)
				{
					num[j+step] = num[j];
				}
				else
				{
					break;
				}
			}
			num[j+step] = temp;
		}
	}
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	return 0;
}
