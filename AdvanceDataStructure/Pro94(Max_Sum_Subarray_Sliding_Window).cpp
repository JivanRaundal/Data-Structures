// Sliding Windows Problem - Maximum sum of subarray of size k

#include<bits/stdc++.h>
using namespace std;

/* 
1] Brute Force Solution ( Time Complexity = O(N*K) )
int max_sum_subarray(int * arr, int n, int k)
{
	int max_sum = 0;
	int sum = 0;
	for(int i=0; i<(n-k+1); i++)
	{
		sum = 0;
		for(int j=i; j<(i+k); j++)
		{
			sum = sum + arr[j];
		}
		max_sum = max(max_sum, sum);
	}
	return max_sum;
}
*/

// 2] Optimal Solution ( Time Complexity = O(N) using sliding window technique)
/*int max_sum_subarray(int arr[],int n,int k)
{
	int max_sum = 0;
	int sum = 0;
	int i=0,j=0;
	
	while(j < n)
	{
		sum = sum + arr[j];
		if(j-i+1 < k)
		{
			j++;
		}
		else if(j-i+1 == k)			//maintain the frame size
		{
			max_sum = max(max_sum, sum);
			sum = sum - arr[i];
			i++;
			j++;
		}
	}
	return max_sum;
}
*/

// OR (Optimal) GFG
int max_sum_subarray(int arr[],int n,int k)
{
	if(n < k)
	{
		cout<<"\nInvalid";
		return -1;
	}
	
	//calculate the sum of first subarray
	int i,max_sum=0;
	for(i=0; i<k; i++)
	{
		max_sum = max_sum + arr[i];
	}
	int sum = max_sum;
	for(i=k; i<n; i++)
	{
		sum = sum + arr[i] - arr[i-k];
		max_sum = max(max_sum, sum);
	}
	return max_sum;
}

int main()
{
	int n,k;
	cout<<"\nEnter size of array : ";
	cin>>n;
	cout<<"\nEnter value of k    : ";
	cin>>k;
	
	int * arr = new int[n];
	cout<<"\nEnter array elements\n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	int max = max_sum_subarray(arr, n, k);
	
	cout<<"\nMaximum sum of subarray of size "<<k<<" = "<<max;

	return 0;
}
