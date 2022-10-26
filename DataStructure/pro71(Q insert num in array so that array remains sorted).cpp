//

#include<iostream>
using namespace std;

int main()
{
	int num[10] = {3,6,9,12,17,20,25};
	int front, rear, x, i;
	front = 0;
	rear  = 6;
	
	cout<<"\nEnter nnumber : ";
	cin>>x;
	for(i=rear; i>=front; i--)
	{
		if(x < num[i])
		{
			num[i+1] = num[i];
		}
		else
		{
			break;
		}
	}
	num[i+1] = x;
	rear++; 
	
	cout<<"\n\nAfter Inserting element in array :\n";
	for(i=front; i<=rear; i++)
	{
		cout<<" "<<num[i];
	}
	return 0;	
}
