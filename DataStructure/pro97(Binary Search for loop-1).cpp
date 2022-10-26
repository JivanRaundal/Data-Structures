// Binary Search :- (Use for Sorted Array only)
//# using for loop 

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {3,6,7,8,9,12,14,15,18,22};
	int i,x,flag=0,n=10;
	cout<<"\nEnter number to search : ";
	cin>>x;
	
	int low,up,mid;
	low = 0;
	up  = n-1;	     //(10-1)
	
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
	}
	
	if(flag == 0)
	{
		cout<<"\nNot found";
	}
	return 0;
}
