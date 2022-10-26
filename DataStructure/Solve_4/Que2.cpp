// Q 2].
// Note => We have to pass base address for scanning & printing Strings.

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char name[5][20];
	char ch;
	
	int i,flag=0;
	cout<<"\nEnter Student's names :\n\n";
	for(i=0; i<5; i++)
	{
		cin.getline(&name[i][0],18,'\n');					//OR cin.getline(name[i],18); only
	}
	
	cout<<"\n\nPrinting Student's names :\n";
	for(i=0; i<5; i++)
	{
		cout<<"\n"<<name[i];			//OR cout<<&name[i][0];
	}
	
	cout<<"\n\nEnter character : ";
	cin>>ch;
	
	for(i=0; i<5; i++)
	{
		if(ch == name[i][0])
		{
			cout<<"\n"<<name[i];
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo name starting with given charcter";
	}
	
	return 0;
}
