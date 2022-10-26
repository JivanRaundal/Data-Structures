// Sliding Windows : Maximum of all subarrays of size k.

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution ( T ime Complexity = O(N) )
vector<int> find_max_of_subarray(int arr[],int n,int k)
{
	int i=0,j=0;
	list<int> lst;			//OR can use double_ended queue (dequeue)
	vector<int> vect;
	
	while(j < n)
	{
		while(lst.size() > 0 && arr[j] > lst.back())
		{
			lst.pop_back();
		}
		lst.push_back(arr[j]);
		
		if(j-i+1 < k)
		{
			j++;
		}
		else if(j-i+1 == k)				//maintain frame size
		{
			vect.push_back(lst.front());
			if(arr[i] == lst.front())
			{
				lst.pop_front();
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
	cout<<"\nHow many elements : ";
	cin>>n;
	cout<<"\nEnter value of k  : ";
	cin>>k;
	int * arr = new int[n];
	cout<<"\nEnter array elements\n";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	vector<int> v = find_max_of_subarray(arr, n, k);
	cout<<"\n\nMaximum of all subarrays\n[";
	for(int i=0; i<v.size(); i++) 
	{
		cout<<" "<<v[i];
	}
	cout<<" ]";
	
	return 0;
}
