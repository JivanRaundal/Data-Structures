// Bubble Sort
// Time Complexity => Best case = Average Case = Worst case = O(n^2)

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {9,12,2,87,13,67,44,28,73,65};
	int n=10;
	int i,j,temp;
	
	cout<<"\nArray Before Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	//Bubble sort
	cout<<"\n\nIterations :";
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
	}
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	return 0;
}
