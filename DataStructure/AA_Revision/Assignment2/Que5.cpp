// Q.5]

#include<iostream>
using namespace std;

int main()
{
	char str[50];
	cout<<"\nEnter String : ";
	cin.getline(str,48,'\n');
	int i=0;
	while(str[i] != '\0')
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	cout<<"\nString = "<<str;
	return 0;
}
