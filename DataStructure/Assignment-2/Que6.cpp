// Q 6].

#include<iostream>
using namespace std;

int main()
{
	char str[100];
	cout<<"\nEnter String : ";
	cin.getline(str,98,'\n');
	cout<<"\nString before replacing = "<<str;
	
	//replacing occurence of 'a' or 'A' by 'E'
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i] == 'a' || str[i] == 'A')
		{
			str[i] = 'E';
		}
		i++;
	}
	
	cout<<"\nAfter replacing string = "<<str;
	return 0;
}
