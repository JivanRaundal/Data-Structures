// Q.1]

#include<iostream>
using namespace std;

void copy(char * t,char * s)
{
	int i=0;
	while(*(s+i) != '\0')
	{
		*(t+i) = *(s+i);
		i++;
	}
	*(t+i) = '\0';
}

int main()
{
	char source[50];
	char target[50];
	cout<<"\nEnter source string : ";
	cin.getline(source,48,'\n');
	copy(target, source);
	cout<<"\nTarget String = "<<target;
	return 0;
}
