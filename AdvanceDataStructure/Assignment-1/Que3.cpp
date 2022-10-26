// Q.3] WAP to copy one string into another recursively.

#include<iostream>
using namespace std;

void copyStr(char * t,char * s)
{
	if(*s == '\0')			//terminating condition for string
	{
		*t = '\0';
		return;
	}
	else
	{
		*t = *s;
		copyStr(t+1,s+1);
	}
}

int main()
{
	char source[20], target[20];
	cout<<"\nEnter source string : ";
	cin.getline(source, 18, '\n');
	copyStr(target, source);
	cout<<"\n\nTarget string = "<<target;
	return 0;
}
