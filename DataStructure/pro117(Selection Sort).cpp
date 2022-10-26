// Selection Sort
// Time Complexity => Best case = Average case = Worst case = O(n^2)

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
	
	//selection sort
	cout<<"\n\nIterations :";
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(num[i] > num[j])
			{
				temp   = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		
		cout<<"\n\n";
		//printing array in each iterations for case study
		for(int k=0; k<n; k++)
		{
			cout<<"  "<<num[k];
			if(i==k)				//to show array gets divided into 2 parts (sorted & unsorted) during each iteration.
			{						// array get's sorted from front side
				cout<<" |";
			}
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
