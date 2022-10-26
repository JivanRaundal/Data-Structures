// Q 4].

#include<iostream>
using namespace std;

void print(char * p)
{
	if(*p == '\0')
	{
		return;
	}
	else
	{
		cout<<*p;
		print(p+1);
	}
}

int main()
{
	char str[100];
	cout<<"\nEnter String : ";
	cin.getline(str,98,'\n');
	
	cout<<"\nPrinting string recursively :\n";
	print(str);
	
	return 0;
}
