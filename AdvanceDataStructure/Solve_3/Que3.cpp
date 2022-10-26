// Q.3] Remove extra spaces from string. 

#include<iostream>
using namespace std;

int main()
{
	char oldString[50];
	char newString[50];
	int i,j,count=0;;
	cout<<"\nEnter old string : ";
	cin.getline(oldString,48,'\n');
	cout<<"\nOld String = "<<oldString;
	
	i=0;
	j=0;
	while(oldString[i] != '\0')
	{
		if(oldString[i] != ' ')
		{
			newString[j] = oldString[i];
			j++;
			i++;
		}
		else if(oldString[i] == ' ')
		{
			newString[j] = oldString[i];		//adding single space
			j++;
			while(oldString[i] == ' ')
			{
				i++;
			}
			/*
			if(oldString[i]!='.' || oldString[i]!=',')
			{
				newString[j] = ' ';		//adding single space
				j++;
			}
			*/
		}
	}
	newString[j] = '\0';		//terminating condition for string
	
	cout<<"\n\nNew String = "<<newString;
	
	return 0;
}
