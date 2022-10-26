// Merge Sort (Double Recursion)

#include<iostream>
#define MAX 10
using namespace std;

void merge(int num[MAX],int low,int mid,int up)
{
	int * res;
	res = new int[up-low+2];		//temp array to store merged elements 
	int i,j,k;
	i = low;
	j = mid+1;
	k = 0;
	
	while(i <= mid && j <= up)
	{
		if(num[i] < num[j])
		{
			res[k] = num[i];
			i++;
			k++;
		}
		else
		{
			res[k] = num[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		res[k] = num[i];
		i++;
		k++;
	}
	while(j <= up)
	{
		res[k] = num[j];
		j++;
		k++;
	}
	
	//merging is done now copy res array to original array
	k=0;				//index of res array
	for(i=low; i<=up; i++)
	{
		num[i] = res[k];
		k++;
	}
	
	delete[] res;
}

void Mergesort(int num[MAX],int low,int up)
{
	int mid;
	if(low < up)
	{
		mid = (up+low)/2;
		Mergesort(num,low,mid);
		Mergesort(num,mid+1,up);
		merge(num,low,mid,up);					//merging will be done during backtracking
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
	
	Mergesort(num,low,up);
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<MAX; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	return 0;
}
