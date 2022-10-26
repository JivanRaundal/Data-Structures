// Quick Sort :- (Double Recursion)

#include<iostream>
#define MAX 10
using namespace std;

int partition(int num[MAX],int low,int up)
{
	int pivot,p,q,temp;
	pivot = num[low];
	p = low+1;
	q = up;
	
	while(1)
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
	
	//swap(num[low],num[q]);
	temp 	 = num[low];
	num[low] = num[q];
	num[q]   = temp;
	
	//cout<<"\n"<<num[low]<<" is fixed";
	return q;
}

void Quicksort(int num[MAX],int low,int up)
{
	int k;
	if(low < up)
	{
		k = partition(num,low,up);
		Quicksort(num,low,k-1);
		Quicksort(num,k+1,up);
	}
}


int main()
{
	int num[MAX];
	int i;
	//initialize array in descending order
	for(i=0; i<MAX; i++)
	{
		num[i] = MAX-i;
	}
	
	cout<<"\n\nArray Before Sorting\n";
	for(i=0; i<MAX; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	cout<<"\n";
	int low,up;
	low = 0;
	up 	= MAX-1;
	
	Quicksort(num,low,up);
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<MAX; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	return 0;
}
