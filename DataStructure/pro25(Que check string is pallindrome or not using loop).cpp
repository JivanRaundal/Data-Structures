// Q. Scan a string from user & check if it is pallindrome or not.

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[100];
	cout<<"\nEnter String : ";
	cin.getline(str,98,'\n');
	
	int i,j;
	i = 0;
	j = strlen(str)-1;
	
	while(i <= j)
	{
		if(str[i] != str[j])
		{
			break;
		}
		i++;
		j--;
	}
	if(i > j)
	{
		cout<<"\nPallindrome";
	}
	else
	{
		cout<<"\nNot Pallindrome";
	}
	return 0;
}
