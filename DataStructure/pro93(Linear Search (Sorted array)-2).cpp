// 	Linear Search :-
// # For Sorted Array 

#include<iostream>
using namespace std;

int main()
{
	int num[8] = {2,3,6,7,9,17,19};
	int i,x,flag = 0;
	
	cout<<"\nEnter element to be search : ";
	cin>>x;
	
	for(i=0; num[i]<=x && i<8; i++)
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
