// 	Linear Search :-
// # For Sorted Array 

#include<iostream>
using namespace std;

int main()
{
	int num[8] = {2,3,6,7,9,17,19};
	int i,x;
	int n = 8;		//size of array
	
	cout<<"\nEnter element to be search : ";
	cin>>x;
	
	for(i=0; num[i]<x && i<n; i++);			//body less for loop (Making sure that i is on correct position)
	
	if(x==num[i] && i<n)		//to reduce the no of comparisons we are writing if block outside the loop
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot Found";
	}
	return 0;
}
