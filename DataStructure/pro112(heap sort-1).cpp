// Code for max heap :-
// Note = *(heap+i) => heap[i]
// heap is runtime array
// Note = if i is index of child then it's parent will be at index i/2

#include<iostream>
using namespace std;

//prototype
void insert(int*, int);
void upadjust(int*, int);

int main()
{
	int * heap;
	int n;
	cout<<"\nHow many elements you want? ";
	cin>>n;
	heap = new int[n+1];
	heap[0] = 0;			//heap[0] will tell current number of elements in array (counter)
	
	int i=1,x;
	while(i <= n)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>x;
		insert(heap,x);
		i++;
	}
	
	cout<<"\n\nPrining Max heap array :\n";
	cout<<"\nTotal number of elements in array = "<<heap[0]<<endl;
	for(i=1; i<=n; i++)
	{
		cout<<" "<<heap[i];
	}
	
	delete[] heap;
	return 0;
}

void insert(int * heap,int x)		//insert() function will insert one element at a time in array/tree
{
	int ind;
	ind = heap[0]+1;
	heap[ind] = x;
	heap[0]++;						//Increament counter
	upadjust(heap,ind);
}

void upadjust(int * heap,int i)		//this function will upadjust the element at ith index 
{
	while(i/2 > 0)		//Or while(i/2 != 0) OR while(heap[i] > heap[i/2] && i/2 != 0) (no need to break loop/else part)
	{
		if(heap[i] > heap[i/2])				//i.e. if(child > parent) then swap
		{
			//swap(heap[i],heap[i/2]);
			int temp  = heap[i];
			heap[i]   = heap[i/2];
			heap[i/2] = temp;
			//i will always stick to newly added element until it's position get's fixed so update i 
			i = i/2;
		}
		else
		{
			break;
		}
	}
}
