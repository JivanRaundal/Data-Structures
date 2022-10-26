// Convert the given matrix into sparse matrix.

#include<iostream>
using namespace std;

void scanmatrix(int num[10][10],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"\nenter element num["<<i<<"]["<<j<<"] : ";
			cin>>num[i][j];
		}
	}
}

void printmatrix(int mat[10][10],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<mat[i][j];
		}
		cout<<"\n";
	}
}

void transpose(int num[10][10],int trans[10][10],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			trans[j][i] = num[i][j];			//rows & columns are interchanged
		}
	}
}

void create_sparse(int num[10][10],int sparse[10][3],int row,int col)
{
	int i,j,k;
	//initialize info row of sparse matrix first
	sparse[0][0] = row;
	sparse[0][1] = col;
	k = 1;				//k will start from 1st row of sparse bcz 0th row is Information row
	
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(num[i][j] != 0)		//if the element is non-zero, it will go in sparse matrix
			{
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = num[i][j];
				k++;
			}
		}
	}
	//after making entry of all non-zero k = (no of non-zero element) + 1;
	sparse[0][2] = k-1;				//Info row
}

void print_sparse(int sparse[10][3])
{
	int i,j;
	for(i=0; i<=sparse[0][2]; i++)		//bcz, sparse[0][2] gives no of non-zero element i.e. no of rows
	{
		cout<<"  "<<sparse[i][0]<<"  "<<sparse[i][1]<<"  "<<sparse[i][2];
		/*for(j=0; j<3; j++)				//no of columns are always fixed in sparse matrix
		{
			cout<<"  "<<sparse[i][j];
		} */
		cout<<"\n";
	}
}

int main()
{
	int num[10][10];
	int row, col;
	
	cout<<"\nEnter rows & columns : ";
	cin>>row>>col;
	
	cout<<"\n\nScanning Matrix\n";
	scanmatrix(num,row,col);
	cout<<"\n\nOriginal Matrix :\n";
	printmatrix(num,row,col);
	
	int trans[10][10];
	cout<<"\n\nCreating Transpose Matrix......";
	transpose(num,trans,row,col);
	cout<<"\n\nTranspose of Matrix :\n";
	printmatrix(trans,col,row);				//rows & columns are interchanged in transpose (check parameters)
	
	int sparse[10][3];
	create_sparse(num,sparse,row,col);
	cout<<"\n\nSparse Matrix :\n";
	print_sparse(sparse);
	
	return 0;
}
