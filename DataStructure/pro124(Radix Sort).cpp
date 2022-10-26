// Radix Sort :-

#include<iostream>
using namespace std;

int find_max(int * p,int n)
{
	int max = *(p+0);
	for(int i=0; i<n; i++)
	{
		if(*(p+i) > max)
		{
			max = *(p+i);
		}
	}
	return max;
}

int main()
{
	int num[10];
	int i,n=10;
	
	cout<<"\nScan Array\n";
	for(i=0; i<n; i++)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>num[i];
	}
	
	cout<<"\n\nArray Before Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	int bucket[10][20];				//2-D bucket array
	int count[10];					//count array will store no of elements in each bucket
	int bucketno,col,j,k;
	int max,passes=0,div=1;
	
	//find max element from array
	max = find_max(num,n);
	cout<<"\n\nMax element = "<<max;
	
	//find total passes, [ passess = no. of digits in max element]
	while(max > 0)
	{
		max = max/10;
		passes++;
	}
	cout<<"\n\nTotal Passes / Iterations = "<<passes;
	
	while(passes > 0)
	{
		//initialize count array (virtual deleteion of bucket array)
		for(i=0; i<10; i++)
		{
			count[i] = 0;	
		}
		
		//classify elements into bucket array based on unit,tens,hundreds,... digit
		for(i=0; i<n; i++)
		{
			bucketno = (num[i]/div)%10;		//row no
			col = count[bucketno];			//col no
			
			bucket[bucketno][col] = num[i];
			count[bucketno]++;
		}
		
		//write all elements back into original array from bucket array 
		k = 0;
		for(i=0; i<=9; i++)			//i is bucket number
		{
			for(j=0; j<count[i]; j++)
			{
				num[k] = bucket[i][j];
				k++;
			}
		}
		
		// 1sr iteration is complete, for next iteration
		div = div * 10;
		passes--;
	}
	
	cout<<"\n\nArray After Sorting\n";
	for(i=0; i<n; i++)
	{
		cout<<" | "<<num[i];
	}
	cout<<" | ";
	
	return 0;
	
}
