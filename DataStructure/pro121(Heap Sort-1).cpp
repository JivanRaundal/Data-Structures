// Heap Sort :-

#include<iostream>
using namespace std;

//prototype
void insert(int * heap,int x);
void upadjust(int * heap,int i);
void delmax(int * heap);
void downadjust(int * heap,int i);

int main()
{
	int * heap;
	int n;
	cout<<"\nHow many integers ? ";
	cin>>n;
	heap = new int[n+1];
	heap[0] = 0;
	
	int i=1,x;
	while(i<=n)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>x;
		insert(heap,x);
		i++;
	}
	
	cout<<"\n\nMax Heap Array\n";
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
	
	return 0;
}

void insert(int * heap,int x)
{
	int ind;
	ind = heap[0]+1;
	heap[ind] = x;
	heap[0]++;
	upadjust(heap,ind);
}

void upadjust(int * heap,int i)
{
	while(i/2 > 0)
	{
		if(heap[i] > heap[i/2])		//i.e. if child > parent 
		{
			int temp  = heap[i];
			heap[i]   = heap[i/2];
			heap[i/2] = temp;
			
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
	while(2*i <= heap[0])			//if true left child is valid
	{
		j = 2*i;
		if(j+1 <= heap[0])			//if true right child is valid
		{
			if(heap[j] < heap[j+1])		//find Max child of i
			{
				j = j+1;
			}
		}
		//j will refer to max child of i
		if(heap[i] < heap[j])			//i.e. if parent < child
		{
			int temp = heap[i];
			heap[i]  = heap[j];
			heap[j]  = temp;
			
			i = j;
		}
		else
		{
			break;
		}
	}
}


