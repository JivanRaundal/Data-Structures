// Q 4].

#include<iostream>
using namespace std;

void rec_scan(int *p,int i)
{
	if(i == -1)
	{
		return;
	}
	rec_scan(p,i-1);
	cout<<"\nelement "<<i<<" : ";
	cin>>*(p+i);
}

int rec_add(int *p,int i)
{
	if(i == -1)
	{
		return 0;
	}
	else
	{
		int x = 0;
		if(*(p+i)%2 == 0)	//i.e. if element is even
		{
			x = *(p+i);
		}
		return x + rec_add(p,i-1);
	}
}

int main()
{
	int num[8];
	cout<<"\nScanning Array Recursively :\n";
	rec_scan(num,7);	// 7 is the last index of array
	
	cout<<"\n\nArray :\n";
	for(int i=0; i<8; i++)
	{
		cout<<" "<<num[i];
	}
	
	cout<<"\n\nAddition of even numbers recursively = "<<rec_add(num,7);
	return 0;
};
