// Linear Search
// # Comparisons based on iterations :-

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
	
	for(i=0; i<MAX; i++)
	{
		if(x == num[i])
		{
			cout<<"\nFound";
			flag=1;
			break;
		}
		iterations++;
		cout<<"\ncomplete";
	}
	if(flag == 0)
	{
		cout<<"\nNot Found";
	}
	
	cout<<"\n\nTotal iterartions = "<<iterations;
	return 0;
}
