//  Pointer to compile time 2D array

#include<iostream>
using namespace std;

void printMatrix(int (*p)[3],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<(*p)[j];
		}
		p = p+1;
		cout<<"\n";
	}
}

int main()
{
	int num[4][3];
	
	int i,j;
	cout<<"\nEnter Matrix :\n";
	for(i=0; i<4; i++)
	{
		for(j=0; j<3; j++)
		{
			cin>>num[i][j];
		}
	}
	
	cout<<"\n\nPrinting Matrix :\n";
	printMatrix(num,4,3);
	
	return 0;
}
