/* Q.10] Pattern Printing using recursion.

1
12
123
1234
12345

*/

#include<iostream>
using namespace std;

void print(int x,int y)
{
	if(x > y)
	{
		return;
	}
	cout<<"\n";
	for(int i=1; i<=x; i++)
	{
		cout<<" "<<i;
	}
	print(x+1, y);
}

int main()
{
	print(1, 5);
	return 0;
}
