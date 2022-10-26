// Q 12]. Scan a string from user which may contain some extra spaces between words. Remove all the extra spaces 
//        user has given. (for logic bulding)
// eg- input  = "  Hello ,    this is   Data    Structure"
//     output = "Hello , this is Data Structure"

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[50];
	cout<<"\nEnter String : ";
	cin.getline(str,48,'\n');
	
	cout<<"\n\nString with extra spaces = "<<str;
	
	cout<<"\n\nString without extra spaces = ";
	int i=0, count=0;
	while(str[i] != '\0')
	{
		while(str[i] == ' ')
		{
			if(count == 0)
			{
				cout<<str[i];
			}
			count++;
			i++;
		}
		cout<<str[i];
		i++;
		count = 0;
	}
	
	return 0;
} 



// To remove the white spaces from original string

/*int main()
{
	char str[50];
	cout<<"\nEnter String : ";
	cin.getline(str,48,'\n');
	
	cout<<"\n\nString with extra spaces    = "<<str;
	
	
	char * p = new char[strlen(str)+1];
	
	int i=0, j=0, count=0;
	while(str[i] != '\0')
	{
		while(str[i] == ' ')
		{
			if(count == 0)
			{
				//cout<<str[i];
				*(p+j) = str[i];
				j++;
			}
			count++;
			i++;
		}
		//cout<<str[i];
		*(p+j) = str[i];
		j++;
		i++;
		count = 0;
	}
	*(p+j) = '\0';
	
	strcpy(str,p);
	delete[] p;
	cout<<"\n\nString Without extra spaces = "<<str;
	
	return 0;
} */
