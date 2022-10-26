//	# Sorting :-

// Selection Sort

#include<iostream>
using namespace std;

void print(int * p,int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		cout<<" "<<*(p+i);	//OR cout<<p[i];
	}
}

void swap(int & x,int & y)
{
	int t;
	t = x;
	x = y;
	y = t;
}

int main()
{
	int n,i,j;
	
	cout<<"\nhow many integers? ";
	cin>>n;
	
	int * p;
	p = new int[n];
	
	//initializing array
	for(i=0; i<n; i++)
	{
		*(p+i) = i+1;
	}
	
	//printing array
	cout<<"\n\nArray Before Sorting :\n";
	print(p,n);
	
	//sorting array if n integers using selection sort
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(*(p+i) < *(p+j))  	//descending order
			{
				swap(*(p+i),*(p+j));
			}
		}
	}
	
	cout<<"\n\nArray After Sorting :\n";
	print(p,n);
	
	delete[] p;
	return 0;
}
