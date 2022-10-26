// Sparse Matrix

#include<iostream>
using namespace std;

void scanMatrix(int mat[10][10],int row,int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"\nelement mat["<<i<<"]["<<j<<"] : ";
			cin>>mat[i][j];
		}
	}
}

void printMatrix(int mat[10][10],int row,int col)
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

void createSparse(int mat[10][10],int sparse[10][3],int row,int col)
{
	int i,j,k;
	//initialize Info row
	sparse[0][0] = row;
	sparse[0][1] = col;
	
	k = 1;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(mat[i][j] != 0)
			{
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = mat[i][j];
				k++;
			}
		}
	}
	sparse[0][2] = k-1;		//Info row
}

void printSparse(int sparse[10][3])
{
	int i;
	cout<<"  "<<sparse[0][0]<<"  "<<sparse[0][1]<<"  "<<sparse[0][2];		//Info row
	cout<<"\n-----------\n";
	
	for(i=1; i<=sparse[0][2]; i++)
	{
		cout<<"  "<<sparse[i][0]<<"  "<<sparse[i][1]<<"  "<<sparse[i][2];
		cout<<"\n";
	}
}

void simpleTranspose(int sparse[10][3],int strans[10][3])
{
	int i,j,k;
	//initialize Info row
	strans[0][0] = sparse[0][1];
	strans[0][1] = sparse[0][0];
	strans[0][2] = sparse[0][2];
	
	k = 1;
	for(i=0; i<strans[0][0]; i++)
	{
		for(j=1; j<=sparse[0][2]; j++)
		{
			if(sparse[j][1] == i)
			{
				strans[k][0] = sparse[j][1];
				strans[k][1] = sparse[j][0];
				strans[k][2] = sparse[j][2];
				k++;
			}
		}
	}
}

void sparse_to_matrix(int sparse[10][3],int mat[10][10])
{
	int row,col,value,i;
	for(i=1; i<=sparse[0][2]; i++)
	{
		row   = sparse[i][0];
		col   = sparse[i][1];
		value = sparse[i][2];
		
		mat[row][col] = value;
		// OR only mat[sparse[i][0]][sparse[i][1]] = sparse[i][2];
	}
}

int main()
{
	int num[10][10];
	int trans[10][10] = {0};		//initializing all element of matrix to zero
	int row, col;
	
	cout<<"\nEnter rows & columns : ";
	cin>>row>>col;
	
	scanMatrix(num,row,col);
	cout<<"\n\nOriginal Matrix :\n";
	printMatrix(num,row,col);
	
	int sparse[10][3];
	createSparse(num,sparse,row,col);
	cout<<"\n\nSparse Matrix :\n";
	printSparse(sparse);
	
	int strans[10][3];
	simpleTranspose(sparse,strans);
	cout<<"\n\nSimple Transpose Sparse MAtrix :\n";
	printSparse(strans);
	
	cout<<"\n\nConverting Sparse Matrix to 2-D MAtrix.....";
	sparse_to_matrix(strans,trans); 
	
	cout<<"\n\nTranspose of MAtrix :\n";
	printMatrix(trans,col,row);			//rows & columns are interchanged
	return 0;
}
