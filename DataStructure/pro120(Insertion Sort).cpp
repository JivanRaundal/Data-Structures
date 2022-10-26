// Insertion Sort
// No any Swapping Process, there is only an insertion process in Insertion Sort
// Time Complexity => Best case  = O(n)
//					  Worst case = O(n^2)

// Note = i always starts from 1
//		  j always starts from i-1
//        temp = num[i]
//        As i goes on increamenting, array behind i will get sorted

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
	
	//Insertion sort
	cout<<"\n\nIterations :";
	for(i=1; i<n; i++)
	{
		temp = num[i];
		for(j=i-1; j>-1; j--)
		{
			if(num[j] > temp)
			{
				num[j+1] = num[j];
			}
			else
			{
				break;
			}
		}
		num[j+1] = temp;
		
		cout<<"\n\n";
		//printing array in each iteration for case study
		for(int k=0; k<n; k++)
		{
			cout<<"  "<<num[k];
			if(k==i)					//To show that array behind i is sorted		
			{						
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
