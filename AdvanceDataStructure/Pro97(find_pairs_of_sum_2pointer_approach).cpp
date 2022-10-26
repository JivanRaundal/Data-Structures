// 2 - pointer approach 
// Q. Two sum problem : 
// given a sorted array, having N integers, find if their exists any pair of element (A[i],A[j]) such that their sum
// is equal to x.

#include<bits/stdc++.h>
using namespace std;

/*
1] Brute Force Solution TC = O(N*N)
bool isPairSum(int arr[],int n, int x)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]+arr[j] == x)	//pair found
				return true;
			
			if(arr[i]+arr[j] > x)
				break;				//as array is sorted
		}
	}
	return false;					//No pair found
}
*/

// 2] OPtimal Solution TC = O(N) 		//using 2 pointer approach
bool isPairSum(int arr[],int n,int x)
{
	int i = 0, j = n-1;
	while(i < j)
	{
		if(arr[i]+arr[j] == x)
			return true;			//pair found
		else if(arr[i]+arr[j] < x)
			i++;
		else if(arr[i]+arr[j] > x)
			j--;
	}
	return false;					//pair not found
}

int main()
{
	int n;
	cout<<"\nEnter size of array : ";
	cin>>n;
	int * arr = new int[n];
	cout<<"\nEnter array elements\n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int x;
	cout<<"\nEnter target : ";
	cin>>x;
	//sorting array
	sort(arr, arr+n);
	
	bool isFound = isPairSum(arr, n, x);
	if(isFound)
		cout<<"\nTrue";
	else
		cout<<"\nFalse";
		
	return 0;
}
