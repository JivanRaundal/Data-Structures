// Slidding Window - First -ve number in every window of size k.

#include<bits/stdc++.h>
#include "Queue"
using namespace std;

/* 1] Brute Forec Solution ( TC = O(N*K) )
vector<int> firstNegative(int arr[],int n,int k)
{
	vector<int> vect;
	int i,j;
	for(i=0; i<(n-k+1); i++)
	{
		for(j=i; j<(i+k); j++)
		{
			if(arr[j] < 0)
			{
				vect.push_back(arr[j]);
				//cout<<" "<<arr[j];
				break;
			}
		}
		if(j == (i+k))		//if no any -ve number then print 0
		{
			vect.push_back(0);
			//cout<<" "<<0;
		}
	}
}
*/

// 2] Optimal ( TC = O(N) )
vector<int> firstNegative(int arr[],int n,int k)
{
	int i,j;
	queue<int> Q;
	for(i=0; i<n; i++)
	{
		if(arr[i] < 0)
		{
			Q.push(arr[i]);
		}
	}
	vector<int> vect;
	i = 0;
	j = 0;
	while(j < n)
	{
		if(j-i+1 < k)
		{
			j++;
		}
		else if(j-i+1 == k)
		{
			if(Q.empty())
			{
				//cout<<" "<<0;
				vect.push_back(0);
			}
			else
			{
				vect.push_back(Q.front());
				//cout<<" "<<Q.front();
				
				//Now, before moving on next window
				if(arr[i] == Q.front())
				{
					Q.pop();
				}
			}
			i++;
			j++;
		}
	}
	return vect;	
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
		
	cout<<"\n\nPrinting First -ve number in every window of size "<<k<<"\n";
	vector<int> v = firstNegative(arr, n, k);

	for(int i=0; i<v.size(); i++)
	{
		cout<<" "<<v[i];
	}
	
	return 0;
}
