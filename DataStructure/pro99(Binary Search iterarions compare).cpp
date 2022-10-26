// Binary Search :- (Use for Sorted Array only)
//# Comparison 

#include<iostream>
#define MAX 10000
using namespace std;

int main()
{
	int num[MAX];
	int i,x,flag=0;
	int iterations=0;
	
	//initialize array
	for(i=0; i<MAX; i++)
	{
		num[i] = i+1;
	}
	
	x = -9;
	
	int low,up,mid;
	low = 0;
	up  = MAX-1;	     //(10-1)
	
	for(mid=(low+up)/2; low<=up; mid=(low+up)/2)
	{
		if(x == num[mid])
		{
			cout<<"\nFound";
			flag = 1;
			break;
		}
		if(x < num[mid])			//search in left part (update upper)
		{
			up = mid-1;
		}
		else if(x > num[mid])
		{
			low = mid+1;
		}
		iterations++;
		cout<<"\ncomplete";
	}
	
	if(flag == 0)
	{
		cout<<"\nNot found";
	}
	
	cout<<"\n\nTotal iterations = "<<iterations;
	return 0;
}
