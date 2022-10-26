// Q 5].

#include<iostream>
#include<string.h>
using namespace std;

char* create()
{
	char str[100];
	cout<<"\nEnter string : ";
	cin.getline(str,98,'\n');
	int len;
	len = strlen(str);
	char * p;
	p = new char(len+1);
	strcpy(p,str);
	return p;
}

int main()
{
	char * ptr;
	ptr = create();
	cout<<"\nString = "<<ptr;
	
	delete[] ptr;
	return 0;
}
