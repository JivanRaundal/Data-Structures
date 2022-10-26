// 2 - pointer approach 
// Q. Three sum problem : 
// given a sorted array, having N integers, find if their exists any pair of element (A[i],A[j],A[k]) such that their
// sum is equal to x.

#include<bits/stdc++.h>
using namespace std;

/*
1] Brute Force Solution TC = O(N^3)
bool isPairSum(int arr[],int n, int x)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				if(arr[i]+arr[j]+arr[k] == x)	//pair found
					return true;
			}
		}
	}
	return false;								//No pair found
}
*/

// 2] OPtimal Solution TC = O(N) 		//using 2 pointer approach
void printTriplet(int arr[],int n,int x)
{	
	for(int i=0; i<n; i++)
	{
		int lo = i+1;
		int hi = n-1;
		while(lo < hi)
		{
			int current = arr[i] + arr[lo] + arr[hi];
			if(current == x)
			{
				cout<<"[ "<<arr[i]<<", "<<arr[lo]<<", "<<arr[hi]<<" ]"<<endl;
				lo++;
				hi--;
				//return True;
			}
			else if(current < x)
			{
				lo++;
			}
			else
			{
				hi--;
			}
		}
	}
//	return false;
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
	
	//bool isFound = isPairSum(arr, n, x);
	
	cout<<"\nPrinting Triplet Pairs\n";
	printTriplet(arr, n, x);
	
		
	return 0;
}
