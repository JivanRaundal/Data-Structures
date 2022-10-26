// Runtime 2-D Array :- passing runtimely created 2D array to functions

#include<iostream>
using namespace std;

void scanMatrix(int** ptr,int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"\nelement num["<<i<<"]["<<j<<"] : ";
			cin>>ptr[i][j];								//OR cin>>*(*(ptr+i)+j);
		}
	}
}

void printMatrix(int** ptr,int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<ptr[i][j];		//OR cout<<*(*(ptr+i)+j);
		}
		cout<<"\n";
	}
}

int main()
{
	int row,col;
	int ** num;
	
	cout<<"\nEnter rows & columns : ";
	cin>>row>>col;
	
	num = new int*[row];		//rutime array of pointers on heap;
	
	int i;
	for(i=0; i<row; i++)
	{
		num[i] = new int[col];			
	}
	
	//scanning
	cout<<"\n\nEnter Matrix :\n";
	scanMatrix(num,row,col);
	
	//printing matrix
	cout<<"\n\nPrinting Matrix :\n\n";
	printMatrix(num,row,col);
	
	delete[] num;
	return 0;
}
