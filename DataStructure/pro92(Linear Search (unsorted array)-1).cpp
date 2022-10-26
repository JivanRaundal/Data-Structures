// 	Linear Search :-
// # For Unsorted Array 

#include<iostream>
using namespace std;

int main()
{
	int num[8] = {3,9,15,7,2,6,19,17};
	int i,x,flag = 0;
	
	cout<<"\nEnter element to be search : ";
	cin>>x;
	
	for(i=0; i<8; i++)
	{
		if(x == num[i])
		{
			flag = 1;
			cout<<"\nFound";
			break;
		}
	}
	
	if(flag == 0)
	{
		cout<<"\nNot Found";
	}
	return 0;
}
