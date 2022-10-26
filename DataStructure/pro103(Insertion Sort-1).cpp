// Sorting

// Insertion Sort :-
// No swapping in Insertion Sort
// temp = num[i]
// i always starts from 1
// j always starts from i-1
// as i moves forward, the array behind i becomes sorted

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {34,23,20,19,17,15,16,8,6,4};
	int i,j,n=10;
	int temp;
	
	cout<<"\nArray Before Sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	//Insertion Sort
	for(i=1; i<n; i++)
	{
		temp = num[i];
		for(j=i-1; j>-1; j--)
		{
			if(num[j] > temp)
			{
				num[j+1] = num[j];			//shifting
			}
			else
			{
				break;
			}
		}
		num[j+1] = temp;
	}
	
	cout<<"\n\nAfter Sorting Array :\n";
	for(i=0; i<n; i++)
	{
		cout<<" "<<num[i];
	}
	
	return 0;
}
