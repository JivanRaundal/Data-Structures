// Bucket Sort

#include<iostream>
using namespace std;

int find_max(int * num,int n)
{
	int i;
	int max = *(num+0);
	for(i=0; i<n; i++)
	{
		if(*(num+i) > max)
		{
			max = *(num+i);
		}
	}
	return max;
}

int main()
{
	int num[10] = {4,3,2,6,3,4,1,0,4,3};
	int i;
	cout<<"\n\nArray Before Sorting\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	int max,ind;
	max = find_max(num,10);
	cout<<"\n\nMax element = "<<max;
	
	int * freq;
	freq = new int[max+1];
	//initilze freq array to zero
	for(i=0; i<=max; i++)
	{
		freq[i] = 0;
	}
	
	for(i=0; i<10; i++)
	{
		ind = num[i];
		freq[ind]++;					//OR only freq[num[i]]++;
	}
	
	cout<<"\n\nFreq Array\n";
	for(i=0; i<=max; i++)
	{
		cout<<" "<<freq[i];
	}
	
	int j,k=0;
	for(i=0; i<=max; i++)
	{
		for(j=0; j<freq[i]; j++)
		{
			num[k] = i;
			k++;
		}
	}
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	delete[] freq;
	return 0;
}
