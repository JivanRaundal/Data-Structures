// Q 4]. 

#include<iostream>
using namespace std;

void copy(char *t, char *s)
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
	char source[100];
	char target[100];
	
	cout<<"\nEnter source string : ";
	cin.getline(source,98,'\n');
	copy(target,source);
	cout<<"\ncopied string = "<<target;
	return 0;
}
