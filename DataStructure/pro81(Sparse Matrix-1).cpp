// Sparse Matrix

#include<iostream>
using namespace std;

//prototypes
void printmatrix(int num[10][10],int row,int col);
void create_sparse(int num[10][10],int sparse[10][3],int row,int col);
void print_sparse(int sparse[10][3]);

int main()
{
	int num[10][10];
	int row, col;
	
	cout<<"\nEnter row and columns : ";
	cin>>row>>col;
	cout<<"\n\nCreating Matrix\n";
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"\nElement num["<<i<<"]["<<j<<"] : ";
			cin>>num[i][j];
		}
	}
	
	cout<<"\n\nOriginal Matrix :\n";
	printmatrix(num,row,col);
	
	int trans[10][10];			//rows and columns are interchanged
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			trans[j][i] = num[i][j];
		}
	}
	cout<<"\n\nTranspose Matrix :\n";
	printmatrix(trans,col,row);
	
	int sparse[10][3];				//sparse matrix
	
	create_sparse(num,sparse,row,col);
	
	cout<<"\n\nSparse Matrix :\n";
	print_sparse(sparse);		
	
	return 0;
}

void printmatrix(int num[10][10],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<num[i][j];
		}
		cout<<"\n";
	}
}

void create_sparse(int num[10][10],int sparse[10][3],int row,int col)
{
	int i,j,k;
	
	//information row details
	sparse[0][0] = row;
	sparse[0][1] = col;
	k = 1;
	
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(num[i][j] != 0)
			{
				//num[i][j] entry will be made in kth row of sparse matrix
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = num[i][j];
				k++;
			}
		}
	}
	
	sparse[0][2] = k-1;			//no of non-zero elements  (information row)
}

void print_sparse(int sparse[10][3])
{
	int i,j;
	for(i=0; i<=sparse[0][2]; i++)			//sparse[0][2] = no. of non-zero elements (sparse[0][2] + 1 => rows)
	{
		for(j=0; j<3; j++)					//no of columns are always 3 in sparse matrix
		{
			cout<<"  "<<sparse[i][j];
		}
		cout<<"\n";
	}
}

