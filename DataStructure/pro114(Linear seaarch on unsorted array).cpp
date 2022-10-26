// Linear Search (for unsorted array)

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {2,5,6,87,13,67,44,28,73,65};
	int n=10;
	int i,x,flag=0;
	
	cout<<"\nEnter element to be searched : ";
	cin>>x;
	
	for(i=0; i<n; i++)
	{
		if(num[i] == x)
		{
			flag=1;
			cout<<"\nFound";
			break;
		}
	}
	
	if(flag==0)
	{
		cout<<"\nNot found";
	}
	return 0;
}
