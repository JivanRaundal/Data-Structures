// Count the possible BST's for given number of keys (i.e. n no of keys) :-

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"\nHow many keys ? ";
	cin>>n;
	
	long long * dp = new long long[n+1];		//OR  int * dp = new int(n+1);
	for(int i=0; i<=n; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i=2; i<=n; i++)		//start/count from 2
	{
		int left = 0;
		int right = (i-1);
		
		while(left <= i-1)
		{
			dp[i] = dp[i] + (dp[left] * dp[right]);
			
			left++;
			right--;
		}
	}
	
	cout<<"\n\nPossible BST's = "<<dp[n];
	
	return 0;
}
