// Heap Sort using Max Heap (with better approach) :-

#include<iostream>
using namespace std;

void swap(int& x,int& y)
{
	int t = x;
	x = y;
	y = t;
}

void downadjust(int * heap,int i)
{
	int j;
	int n = heap[0];
	while(2*i <= n)			//valid left child
	{
		j = 2*i;
		if(2*i+1 <= n)		//valid right child
		{
			if(heap[j+1] > heap[j])		//if right child > left child
			{
				j = j+1;
			}
		}
		//j is on max child
		if(heap[i] < heap[j])		//if parent < child, swap
		{
			swap(heap[i], heap[j]);
			i = j;
		}
		else
		{
			break;
		}
	}
}

void heapSort(int * heap)
{
	int n = heap[0];
	//start downadjustment from n/2 index
	for(int i=n/2; i>=1; i--)
	{
		downadjust(heap, i);
	}
	
	cout<<"\n\nPrintind Max Heap Array\n";
	for(int i=0; i<=n; i++)			//or can start from i=1
	{
		cout<<"  "<<heap[i];
	}
	
	//now sort heap array using max heap
	while(heap[0] > 1)		//OR while(heap[0] > 0)
	{
		int lastind = heap[0];
		swap(heap[1], heap[lastind]);		//swap first & last elements
		heap[0]--;
		downadjust(heap, 1);
	}
}

int main()
{
	int n;
	cout<<"\nEnter total number of elements : ";
	cin>>n;
	
	int * heap = new int[n+1];		//bcz 0th element stores total elements in heap array
	heap[0] = n;
	
	cout<<"\nEnter array elements\n";
	for(int i=1; i<=n; i++)
	{
		cin>>heap[i];
	}
	
	//function to sort array using max heap
	heapSort(heap);
	
	cout<<"\n\nArray after sorting\n";
	for(int i=1; i<=n; i++)
	{
		cout<<"  "<<heap[i];
	}
	
	return 0;
}
