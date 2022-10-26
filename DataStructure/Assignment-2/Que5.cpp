// Q 5].

#include<iostream>
using namespace std;

void convert(char *p)
{
	int i=0;
	while(*(p+i) != '\0')
	{
		if(*(p+i) >= 97 && *(p+i) <= 122 )
		{
			*(p+i) = *(p+i) - 32; 
		}
		i++;
	}
}

int main()
{
	char str[100];
	cout<<"\nEnter String : ";
	cin.getline(str,98,'\n');
	
	cout<<"\nBefore converting string = "<<str;
	
	convert(str);
	
	cout<<"\nAfter converting string = "<<str;
	return 0;
}
