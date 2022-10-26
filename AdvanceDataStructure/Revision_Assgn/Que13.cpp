// Q.13] Create database of 7 cities. Check if pune is present in it or not.

#include<iostream>
#include<string.h>
using namespace std;

char* getCity()
{
	char city[50];
	cin.getline(city, 48, '\n');
	int len = strlen(city);
	char * p = new char[len+1];
	strcpy(p, city);
	return p;
}

int main()
{
	//array of char typr pointers
	char* city[7];
	cout<<"\nEnter City Names :\n";
	for(int i=0; i<7; i++)
	{
		city[i] = getCity();
	}
	cout<<"\n\nCity Names :\n";
	for(int i=0; i<7; i++)
	{
		cout<<city[i]<<endl;
	}
	
	//check if pune is present in it or not
	int i;
	for(i=0; i<7; i++)
	{
		if(strcmp(city[i], "pune") == 0 || strcmp(city[i], "Pune") == 0)
		{
			cout<<"\npune is present";
			break;
		}
	}
	if(i == 7)
	{
		cout<<"\npune is not present";
	}
	
	return 0;
}
