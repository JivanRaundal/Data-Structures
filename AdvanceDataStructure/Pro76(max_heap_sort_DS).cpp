// HEAP SORT (upadjustment() & downadjustment()) :-
// Here, we insert one by one element so that our max heap remains maintain -

#include<iostream>
using namespace std;

void swap(int& x,int& y)
{
	int t = x;
	x = y;
	y = t;
}

void upadjust(int * heap,int i)
{
	while(i/2 > 0)
	{
		if(heap[i] > heap[i/2])		//i.e. if child > parent
		{
			swap(heap[i], heap[i/2]);
			i = i/2;
		}
		else
		{
			break;
		}
	}
}

void insert(int * heap,int x)
{
	int ind = heap[0]+1;
	heap[ind] = x;
	heap[0]++;				//increase element by 1
	upadjust(heap, ind);	//do upadjustment for newly added element
}

void downadjust(int * heap,int i)
{
	int j;
	int n = heap[0];		//total elements in heap
	while(2*i <= n)			//valid left child
	{
		j = 2*i;
		if(2*i+1 <= n)		//valid right child
		{
			if(heap[j+1] > heap[j])
			{
				j = j + 1;
			}
		}
		//j is on max child
		if(heap[i] < heap[j])			//if child > parent, swap
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

void delmax(int * heap)
{
	int lastind = heap[0];
	swap(heap[1], heap[lastind]);
	heap[0]--;			//decrease heap size by one, bcz last element is fixed/sorted
	downadjust(heap, 1);
}

int main()
{
	int n;
	cout<<"\nEnter number of elements : ";
	cin>>n;
	
	int * heap = new int[n+1];
	heap[0] = 0;
	cout<<"\nEnter array elements\n";
	int x;
	for(int i=0; i<=n; i++)
	{
		cin>>x;
		insert(heap, x);
	}
	
	cout<<"\n\nPrinting Max Heap Array\n";
	for(int i=0; i<=n; i++)
	{
		cout<<"  "<<heap[i];
	}
	
	//for sorting array
	while(heap[0] > 0)
	{
		delmax(heap);
	}
	
	cout<<"\n\nSorted Array\n";
	for(int i=1; i<n; i++)		//array is stored from index 1
	{
		cout<<"  "<<heap[i];
	}
	
	return 0;
}
