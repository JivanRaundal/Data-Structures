// basic hash table & hash fun

#include<iostream>
using namespace std;

int main()
{
	int arr[10] = {0};
	int x,y;
	
	for(int i=0; i<10; i++)
	{
		cout<<"\nEnter element : ";
		cin>>y;
		x = y%10;	//Hash fun
		arr[x] = y;
	}
	
	cout<<"\n\nArray 2 :\n";
	for(int i=0; i<10; i++)
	{
		cout<<" "<<arr[i];
	}
	
	cout<<"\nEnter element to be searhed : ";
	cin>>y;
	x = y%10;
	if(arr[x] == y)
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot Found";
	}
	
	return 0;	
}
