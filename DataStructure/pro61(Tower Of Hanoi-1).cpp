// Double Recursion - Tower Of Hanoi (TOH)
// Note => Formula to find no. of minimum transactions is, T = (2^n-1)
// Note => Notations :- source tower = source, Destination tower = dest, Intermediate tower = inter

#include<iostream>
using namespace std;

int count = 0;			//global variable used to count no. of transactions

void TOH(int n,char source,char dest,char inter)
{
	if(n > 0)
	{
		count++;
		TOH(n-1,source,inter,dest);
		cout<<"\n-from  "<<source<<" -> "<<dest;
		TOH(n-1,inter,dest,source);
	}
}

int main()
{
	int n;
	cout<<"\nEnter Number of Disks : ";
	cin>>n;
	
	TOH(n,'S','D','I');				//function call
	
	cout<<"\n\nTotal Transactions = "<<count;
	return 0;
}
