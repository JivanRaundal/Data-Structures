// Q 3].

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string city[5];		//array of string type objects
	string str;
	
	int i,flag=0;
	cout<<"\n\nEnter city names :\n\n";
	for(i=0; i<5; i++)
	{
		getline(cin,city[i]);		//OR cin>>city[i]; only	
	}
	
	cout<<"\n\nPrinting City names :\n";
	for(i=0; i<5; i++)
	{
		cout<<"\n"<<city[i];
	}
	
	cout<<"\n\nEnter city name you want to search : ";
	getline(cin,str);			//OR cin>>str;
	
	//linear search
	for(i=0; i<5; i++)
	{
		if(str == city[i])			// overloaded == operator for string datatype
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
