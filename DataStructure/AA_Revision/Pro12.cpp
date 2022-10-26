// pallindrome

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[50];
	cout<<"\nEnter String : ";
	cin.getline(str,48,'\n');
	int i,j;
	i = 0;
	j = strlen(str)-1;
	
	while(i <= j)
	{
		if(str[i] != str[j])
		{
			break;
		}
		i++;
		j--;
	}
	if(i > j)
	{
		cout<<"\nPllindrome";
	}
	else
	{
		cout<<"\nNot Pallindrome";
	}
	return 0;
}
