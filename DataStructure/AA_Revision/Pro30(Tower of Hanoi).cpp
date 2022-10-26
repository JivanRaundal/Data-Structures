// Tower of Hanoi  (Double Recursion)

#include<iostream>
using namespace std;

int counter = 0;

void TOH(int n,char src,char dest,char inter)
{
	if(n>0)
	{
		counter++;
		TOH(n-1,src,inter,dest);
		cout<<"\n"<<src<<" -> "<<dest;
		TOH(n-1,inter,dest,src);
	}
}

int main()
{
	int n;
	cout<<"\nEnter number of disks : ";
	cin>>n;
	TOH(n,'S','D','I');
	cout<<"\n\nTotal Transactions = "<<counter;
	return 0;
}
