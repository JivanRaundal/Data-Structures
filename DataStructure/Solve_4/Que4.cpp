// Q 4].

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char name[5][20];
	char temp[10];
	
	int i,j;
	cout<<"\nEnter Student's names :\n\n";
	for(i=0; i<5; i++)
	{
		cin.getline(&name[i][0],18,'\n');					//OR cin.getline(name[i],18); only
	}
	
	cout<<"\n\nPrinting Student's names before sorting :\n";
	for(i=0; i<5; i++)
	{
		cout<<"\n"<<name[i];			//OR cout<<&name[i][0];
	}
	
	//Selection Sort
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(strcmp(&name[i][0], &name[j][0]) == 1)			//i.e. first string > second string
			{
				//swapping strings
				strcpy(temp,name[i]);					//OR strcpy(&temp[0],&name[i][0]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	
	cout<<"\n\nPrinting Student's names after sorting :\n";
	for(i=0; i<5; i++)
	{
		cout<<"\n"<<name[i];			//OR cout<<&name[i][0];
	}	
	
	return 0;
}
