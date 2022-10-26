// Count the possible BST's for given number of keys (i.e. n no of keys) :-

#include<iostream>
using namespace std;

int fact(int n)
{
	if(n == 0)
	{
		return 1;
	}
	return n * fact(n-1);
}

int ncr(int n,int r)		//function to calculate & returb value of nCr
{
	//NOTE:- nCr = n! / r! * (n-r)!
	long long res = fact(n) / (fact(r) * fact(n-r));
	return res;
}

int main()
{
	int n;
	cout<<"\nHow many keys ? ";
	cin>>n;
	
	int T = ncr(2*n, n) / (n + 1);			//Formula [ T = 2*nCn/n+1 ]
	cout<<"\n\nPossible BST'S = "<<T;
	
	return 0;
}
