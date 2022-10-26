// Quick Sort :-
// Note => we have choosen element at position low as a pivot element.

#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int num[10],int low,int up)			//partion algorithm (it will fix the pivot element at correct pos)
{
	int pivot,p,q,temp;
	pivot = num[low];
	p = low+1;
	q = up;
	
	while(1)					//OR while(p<=q)   (no need of else part to break loop)
	{
		while(num[p] <= pivot && p <= up)
		{
			p++;
		}
		while(num[q] > pivot)
		{
			q--;
		}
		if(p < q)
		{
			//swap(num[p],num[q]);
			temp   = num[p];
			num[p] = num[q];
			num[q] = temp;
		}
		else
		{
			break;
		}
	}
	
	//swap(num[low],num[q]);			//Note => swap(pivot,num[q]) is Invalid, use num[low] for pivot to swap
	temp     = num[low];
	num[low] = num[q];
	num[q]   = temp;
	
	return q;					//pivot element will be fixed at q hence, return q
}

void Quicksort(int num[10],int low,int up)
{
	int k;
	if(low < up)				//for single element (low=up) then break loop as single element is sorted
	{
		k = partition(num,low,up);			//partition algorithm will sort/fix only 1 element at a time(pivot element)
		Quicksort(num,low,k-1);				//left array
		Quicksort(num,k+1,up);				//right array 
	}
}

int main()
{
	int num[10] = {35,7,4,9,12,67,43,59,88,50};
	
	int i,n=10;
	cout<<"\nArray Before Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	Quicksort(num,0,n-1);
	
	cout<<"\n\nArray After Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	return 0;
}
