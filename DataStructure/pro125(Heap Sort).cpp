// Heap Sort

#include<iostream>
using namespace std;

//prototypes
void swap(int & a,int & b);
void insert(int * heap,int x);
void upadjust(int * heap,int i);
void delmax(int * heap);
void downadjust(int * heap,int i);

int main()
{
	int * heap;
	int n;
	cout<<"\nHow many int ? ";
	cin>>n;
	heap = new int[n+1];
	heap[0] = 0;			//counter
	
	int x,i=1;
	cout<<"\nEnter Array Elements\n";
	while(i <= n)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>x;
		insert(heap,x);
		i++;
	}
	
	cout<<"\n\nMAx Heap Array\n";
	for(i=1; i<=n; i++)
	{
		cout<<" "<<heap[i];
	}
	
	while(heap[0] > 0)
	{
		delmax(heap);
	}
	
	cout<<"\n\nSorted Array\n";
	for(i=1; i<=n; i++)
	{
		cout<<" "<<heap[i];
	}
	
	delete[] heap;
	return 0;
}

void swap(int & a,int & b)
{
	int t;
	t = a;
	a = b;
	b = t;  
}

void insert(int * heap,int x)
{
	int ind = heap[0]+1;
	heap[ind] = x;
	heap[0]++;
	upadjust(heap,ind);
}

void upadjust(int * heap,int i)
{
	while(i/2 > 0)
	{
		if(heap[i] > heap[i/2])
		{
			swap(heap[i],heap[i/2]);
			i = i/2;
		}
		else
		{
			break;
		}
	}
}

void delmax(int * heap)
{
	int lastind,x;
	lastind = heap[0];
	x = heap[1];
	heap[1] = heap[lastind];
	heap[0]--;
	downadjust(heap,1);
	heap[lastind] = x;
}

void downadjust(int * heap,int i)
{
	int j;
	while(2*i <= heap[0])				//if true valid left child
	{
		j = 2*i;
		if(j+1 <= heap[0])				//if true valid right child
		{
			if(heap[j] < heap[j+1])		//find max child of i
			{
				j = j+1;
			}
		}
		//j will refer to max child of i
		if(heap[i] < heap[j])			//i.e. if parent < child
		{
			swap(heap[i],heap[j]);
			i = j;
		}
		else
		{
			break;
		}
	}
}
