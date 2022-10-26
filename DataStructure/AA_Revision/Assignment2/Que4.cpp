// Q.4]

#include<iostream>
using namespace std;

void print(char * s)
{
	if(*s == '\0')
	{
		return;
	}
	else
	{
		cout<<*s;
		print(s+1);
	}
}

int main()
{
	char str[50];
	cout<<"\nEnter String : ";
	cin.getline(str, 48, '\n');
	cout<<"\nPrinting String Recursively :\n";
	print(str);
	return 0;
}
