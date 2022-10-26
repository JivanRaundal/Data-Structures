// Binary Search (Sorted Array)

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {2,3,6,7,9,13,15,18,20,24};
	int n=10;
	int i,x,flag=0;
	int low = 0;
	int up = n-1;
	int mid;
	
	cout<<"\nEnter element to be searched : ";
	cin>>x;
	
	for(mid=(low+up)/2; low<=up; mid=(low+up)/2)
	{
		if(x == num[mid])
		{
			flag=1;
			cout<<"\nFound";
			break;
		}
		if(x < num[mid])
		{
			up = mid-1;
		}
		else if(x > num[mid])
		{
			low = mid+1;
		}
	}
	
	if(flag==0)
	{
		cout<<"\nNot Found";
	}
	return 0;
}
