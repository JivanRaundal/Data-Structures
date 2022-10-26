// Q 5].

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string city[5];		//array of string type objects
	string temp;
	int n=5;
	
	int i,j;
	cout<<"\n\nEnter city names :\n\n";
	for(i=0; i<n; i++)
	{
		getline(cin,city[i]);		//OR cin>>city[i]; only	
	}
	
	cout<<"\n\nPrinting City names before sorting :\n";
	for(i=0; i<n; i++)
	{
		cout<<"\n"<<city[i];
	}
	
	//Bubble Sort
	for(i=1; i<n; i++)
	{
		for(j=0; j<n-i; j++)
		{
			if(city[j] < city[j+1])				//sorting in descending order
			{
				temp      = city[j];
				city[j]   = city[j+1];
				city[j+1] = temp;
			}
		}
		
	}

	cout<<"\n\nPrinting City names after sorting in descending order :\n";
	for(i=0; i<n; i++)
	{
		cout<<"\n"<<city[i];
	}
	
	return 0;
}
