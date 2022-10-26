// Q 1].

#include<iostream>
using namespace std;

void print(int * p)
{
	for(int i=0; i<9; i++)
	{
		cout<<" "<<*(p+i);
	}
}

void sort_ascending(int * p)
{
	int i,j;
	for(i=0; i<9; i++)
	{
		for(j=i+1; j<9; j++)
		{
			if(*(p+i) > *(p+j))
			{
				int temp;
				temp   = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

void sort_descending(int * p)
{
	int i,j;
	for(i=0; i<9; i++)
	{
		for(j=i+1; j<9; j++)
		{
			if(*(p+i) < *(p+j))
			{
				int temp;
				temp   = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

int main()
{
	int num[] = {3,65,41,27,63,22,49,8,77};
	
	cout<<"\n\nBefore Sorting :\n";
	print(num);
	
	sort_ascending(num);
	cout<<"\n\nAscending sort :\n";
	print(num);
	
	sort_descending(num);
	cout<<"\n\nDescending sort :\n";
	print(num);
	
	return 0;
}
