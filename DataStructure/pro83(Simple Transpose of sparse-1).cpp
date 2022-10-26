// Convert the given matrix into sparse matrix & find it's Simple Transpose.

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

void simple_transpose(int sparse[10][3],int strans[10][3])
{
	int i,j,k;
	//initialize Info row of strans (which is same as sparse)
	strans[0][0] = sparse[0][1];		//sparse column will be strans row.
	strans[0][1] = sparse[0][0];		//sparse row will be strans column.
	strans[0][2] = sparse[0][2];
	
	k = 1;									//k will keep track of row's of strans
	for(i=0; i<sparse[0][1]; i++)			//rows of strans
	{
		for(j=1; j<=sparse[0][2]; j++)		//no of non-zero elements in sparse OR rows in sparse
		{
			if(sparse[j][1] == i)			//if jth row's column in sparse is equal to ith row element of strans
			{
				strans[k][0] = sparse[j][1];
				strans[k][1] = sparse[j][0];
				strans[k][2] = sparse[j][2];
				k++;
			}
		}
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
	
	int strans[10][3];			//simple transpose
	simple_transpose(sparse,strans);
	cout<<"\n\nSimple Transpose of Sparse Matrix :\n";
	print_sparse(strans);
	
	return 0;
}
