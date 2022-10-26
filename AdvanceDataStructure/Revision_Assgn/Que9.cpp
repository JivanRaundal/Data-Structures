// Q.9] scan a string without wasting memory.

#include<iostream>
#include<string.h>
using namespace std;

char* getString()
{
	char str[100];
	cout<<"\nEnter string : ";
	cin.getline(str,98,'\n');
	int len = strlen(str);
	char * p = new char[len+1];
	strcpy(p, str);
	return p;
}

int main()
{
	char * str;
	str = getString();
	cout<<"\nString = "<<str;
	delete str;
	return 0;
}
