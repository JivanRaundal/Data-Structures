// Merge Sort

#include<iostream>
using namespace std;

void merge(int num[15],int low,int mid,int up)
{
	int * res;
	res = new int[up-low+2];
	int i,j,k;
	i = low;
	j = mid+1;
	k = 0;					//index of res array
	
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
	
	//copying res array to original (num) array
	k=0;
	for(i=low; i<=up; i++)
	{
		num[i] = res[k];
		k++;
	}
	delete[] res;
}

void Mergesort(int num[15],int low,int up)
{
	int mid;
	if(low < up)
	{
		mid = (low+up)/2;
		Mergesort(num,low,mid);			//right array
		Mergesort(num,mid+1,up);		//left array
		merge(num,low,mid,up);			//merging during Backtracking
	}
}

int main()
{
	int num[15];
	int i,n=15;
	
	//initializing array in descending order
	for(i=0; i<n; i++)
	{
		num[i] = n-i;	
	}
	
	cout<<"\nArray Before Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	Mergesort(num,0,14);		
	
	cout<<"\n\nSorted";
	cout<<"\n\nArray After Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	return 0;
}
