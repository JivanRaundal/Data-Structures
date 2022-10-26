// Q.8] scan char type string. print length of sting using recursion.

#include<iostream>
using namespace std;

int Length(char * s)
{
	if(*s == '\0')
	{
		return 0;
	}
	return 1 + Length(s+1);
}

int main()
{
	char str[30];
	cout<<"\nEnter String : ";
	cin.getline(str,28,'\n');
	int len;
	len = Length(str);
	cout<<"\nLength of string = "<<len;
	return 0;
}
