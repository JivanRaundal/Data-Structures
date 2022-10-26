// Q 3].

#include<iostream>
using namespace std;

int Length(char *p)
{
	int i=0;
	while(*(p+i) != '\0')
	{
		i++;
	}
	return i;
}

int main()
{
	char str[100];
	cout<<"\nEnter String : ";
	cin.getline(str,98,'\n');
	int len;
	len = Length(str);
	cout<<"\nLength = "<<len;
	return 0;
}
