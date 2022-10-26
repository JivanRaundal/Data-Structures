// Fibonacci Search

#include<iostream>
using namespace std;

int fib(int n)
{
	if(n <= 1)
	{
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int min(int x,int y)
{
	if(x < y)
		return x;
	else
		return y;
}

int fib_search(int num[10],int n,int s)
{
	//to find k such that fib(k) > n
	int i,k=0;
	for(i=0; fib(i)<=n; i++);				//this loop will find k
	//above bodyless for loop will stop when [fib(i) > n], hence i will be at reuired index 
	k = i;
	
	int offset = -1;
	
	while(k>1)
	{
		//find i, (here, i is working as an index of element in array)
		i = min(offset+fib(k-2), n-1);		//(n-1) is index of last element in array
		
		if(i<0)
		{
			return -1;			//not found
		}
		if(i==n-1 && num[i]<s)
		{
			return -1;			//not found
		}
		if(s==num[i])
		{
			return i;			//found
		}
		if(s<num[i])
		{
			k = k-2;
		}
		if(s>num[i])
		{
			k = k-1;
			offset = i;
		}
	}
	
	return -1;				//bcz if above loop is false, k will be less that 1 i.e. k < 1, hence return -1 
}

int main()
{
	int num[10] = {4,12,15,25,28,32,38,40,45,52};		//Sorted array
	int n=10;
	//int num[1] = {2};
	//int n=1;
	
	cout<<"\n\nArray\n";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	int s;					//s be the element to be search
	cout<<"\n\nEnter element to be searched : ";
	cin>>s;
	
	int x = fib_search(num,n,s);
	if(x == -1)
	{
		cout<<"\n\nNot found";
	}
	else
	{
		cout<<"\n\nFound at index "<<x;
	}
	
	return 0;
}
