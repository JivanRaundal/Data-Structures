// atoi() function

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
	char str1[10];
	char str2[10];
	cout<<"\nEnter string 1 : ";
	cin.getline(str1,8,'\n');
	cout<<"\nEnter string 2 : ";
	cin.getline(str2,8,'\n');
	
	int x,y;
	x = atoi(str1);
	cout<<"\nx = "<<x;
	y = atoi(str2);
	cout<<"\ny = "<<y;
	
	cout<<"\nAddition = "<<x+y;
	return 0;
}
