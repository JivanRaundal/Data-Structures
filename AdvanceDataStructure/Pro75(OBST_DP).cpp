// OBST (Optimal Binary Search Tree) 

#include<iostream>
#include<climits>
#include<iomanip>
using namespace std;

int sumFreq(int * freq,int i,int j)			//will return sum of freq from i to j
{
	int sum = 0;
	for(int k=i; k<=j; k++)
	{
		sum = sum + freq[k];
	}
	return sum;
}

void optimalBST(int * keys,int * freq,int n)
{
	int ** cost = new int*[n+1];
	for(int i=0; i<=n; i++)
	{
		cost[i] = new int[n+1];
		for(int j=0; j<=n; j++)
		{
			cost[i][j] = 0;
		}
	}
	
	for(int gap=1; gap<=n; gap++)
	{
		int i=0;
		int j=gap;
		while(j <= n)
		{
			int min = INT_MAX;
			int w = sumFreq(freq, i+1, j);		//note:- weight is of roots only
			for(int r=i+1; r<=j; r++)			//assuming r as a root
			{
				int lcost = cost[i][r-1];
				int rcost = cost[r][j];
				
				if(min > lcost + rcost + w)
				{
					min = lcost + rcost + w;
				}
			}
			cost[i][j] = min;
			i++;
			j++;
		}
	}
	
	
	cout<<"\nCost Matrix\n";
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cout<<setw(4)<<cost[i][j];
		}
		cout<<"\n"; 
	}
	
	cout<<"\n\nCost of OBST = "<<cost[0][n];
}

int main()
{
	int n;
	cout<<"\nHow many keys ? ";
	cin>>n;
	
	int * keys = new int[n+1];
	int * freq = new int[n+1];
	
	cout<<"\nenter "<<n<<" keys array in ascending order (keys should be sorted)"<<"\n";
	freq[0] = keys[0] = 0;
	for(int i=1; i<=n; i++)
	{
		cin>>keys[i];
	}
	cout<<"\nenter "<<n<<" frequency array"<<"\n";
	for(int i=1; i<=n; i++)
	{
		cin>>freq[i];
	}
	
	cout<<"\nkeys & freq arrays\n";
	for(int i=0; i<=n; i++)
	{
		cout<<setw(4)<<keys[i]<<setw(4)<<freq[i]<<endl;
	}
	
	optimalBST(keys, freq, n);
	
	return 0;
}
