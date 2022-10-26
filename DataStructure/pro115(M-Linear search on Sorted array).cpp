// Modified Linear search on Sorted array only

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {2,3,6,7,9,13,15,18,20,24};		//sorted array
	int n=10;
	int i,x;
	
	cout<<"\nEnter element to be searched : ";
	cin>>x;
	
	for(i=0; num[i]<x && i<n; i++);				//loop will move i to required element
	
	if(num[i]==x && i<n)
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot found";
	}
	
	return 0;
}
