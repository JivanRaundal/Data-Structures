// Q 1].
// Note => We have to pass base address for scanning & printing Strings.

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char city[6][10];
	char str[10];
	
	int i,flag=0;
	cout<<"\nEnter 6 city names :\n\n";
	for(i=0; i<6; i++)
	{
		cin>>&city[i][0];					//OR cin>>city[i]; only OR use getline()
	}
	
	cout<<"\n\nPrinting cities :\n";
	for(i=0; i<6; i++)
	{
		cout<<"\n"<<city[i];			//OR cout<<&city[i][0];
	}
	
	cout<<"\n\nEnter city name you want to search : ";
	cin>>str;
	
	//linear search
	for(i=0; i<6; i++)
	{
		if(strcmp(str,&city[i][0]) == 0)
		{
			cout<<"\nFound";
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nNot Found";
	}
	
	return 0;
}
