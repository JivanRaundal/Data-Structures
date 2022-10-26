// Q.4] print array using recursion.

#include<iostream>
using namespace std;

void print(int * p,int i)
{
	if(i == -1)
	{
		return;
	}
	else
	{
		print(p, i-1);
		cout<<" "<<*(p+i);
	}
}

int main()
{
	int arr[6] = {10,20,30,40,50,60};
	cout<<"\nArray\n";
	print(arr,5);
	return 0;
}
