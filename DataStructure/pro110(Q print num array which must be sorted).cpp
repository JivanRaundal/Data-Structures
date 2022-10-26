// Q. Practice Question.

#include<iostream>
using namespace std;

void merge(int num[10],int low,int mid,int up)
{
	int res[10];
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;
	
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
	
	//now, copying res array to num array so that num array will be sorted
	for(i=0; i<10; i++)
	{
		num[i] = res[i];
	}
	cout<<"\n\nSoted";
}

int main()
{
	int num[10] = {3,7,11,16,25,2,8,11,19,24};
	
	int i;
	cout<<"\nArray Before Sorting :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	int low,mid,up;
	low = 0;
	up  = 9;
	mid = 4;             //mid = (low+up)/2;
	
	merge(num,low,mid,up);
	
	cout<<"\n\nArray After Sorting :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	return 0;
}
