// Modified Bubble Sort
// It reduces number of iterations in case if array is already sorted or partially sorted.
// Time Complexity => Best case O(n) if array is already sorted
//                    Average Case = Worst case = O(n^2)

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {2,9,12,13,16,20,28,73,65,70};
	int n=10;
	int i,j,flag,temp;
	
	cout<<"\nArray Before Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	//Modified Bubble sort
	cout<<"\n\nIterations :";
	for(i=1; i<n; i++)
	{
		flag=0;
		for(j=0; j<n-i; j++)
		{
			if(num[j] > num[j+1])
			{
				temp     = num[j];
				num[j]   = num[j+1];
				num[j+1] = temp;
				
				flag=1;
			}
		}
		
		cout<<"\n\n";
		//printing array in each iteration for case study
		for(int k=0; k<n; k++)
		{
			if(k==n-i)				//to show array gets divided into 2 parts (sorted & unsorted) during each iteration.
			{						// array get's sorted from backside.
				cout<<" |";
			}
			cout<<"  "<<num[k];
		}
		
		if(flag==0)
		{
			//No swapping 
			break;
		}
	}
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	return 0;
}
