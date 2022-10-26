// Q.1] Scan a string from user, check if it is pallindrome or not recursively.

#include<iostream>
#include<string.h>
using namespace std;

bool isPallindrome(char * str,int i,int j)
{
	if(str[i] != str[j])
	{
		return false;
	}
	if(i > j)
	{
		return true;
	}
	return isPallindrome(str, i+1, j-1);
}

int main()
{
	char str[30];
	cout<<"\nEnter the string : ";
	cin.getline(str,28,'\n');
	int n = strlen(str);
	
	if(isPallindrome(str,0,n-1))
	{
		cout<<"\nPallindrome";
	}
	else
	{
		cout<<"\nNot Pallindrome";
	}
	
	return 0;
}
