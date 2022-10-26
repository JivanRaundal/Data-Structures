// Q 2].

#include<iostream>
using namespace std;

void print(int x,int y)
{
	if(x == y+1)	//Or if(x>y)
	{
		return;
	}
	else
	{
		cout<<"\n"<<x;
		print(x+1,y);
	}
}

int main()
{
	int a,b;
	cout<<"\nEnter Range : ";
	cin>>a>>b;
	
	if(a<b)
	{
		print(a,b);
	}
	else
	{
		print(b,a);
	}
	return 0;
}
