// Fast Transpose

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

void fastTranspose(int sparse[10][3],int ftrans[10][3])
{
	int i,pos;
	int row,col,val,rno;	//rno = row number
	
	//initialize ftrans Info row
	ftrans[0][0] = sparse[0][1];
	ftrans[0][1] = sparse[0][0];
	ftrans[0][2] = sparse[0][2];
	
	//creating 2 runtime array named 'total' & 'index'. total array will store total no of elements in each row 
	// of 2D trans and index array will store the starting index of each row element to placed in ftrans.
	// no of elements in target & index array = no of rows in 2D transpose array (i.e. ftrans[0][0])
	row = sparse[0][1];		//OR row = ftrans[0][0]
	int *total, *index;
	total = new int[row];
	index  = new int[row];
	
	//initializing target array to zero
	for(i=0; i<row; i++)			//row = sparse[0][1] OR ftrans[0][0]
	{
		total[i] = 0;
	}
	//creating target array. (we have to traverse through sparse matrix columns)
	for(i=1; i<=sparse[0][2]; i++)
	{
		rno = sparse[i][1];
		total[rno]++;
	}
	//for index array initialize index[0] = 1 always
	index[0] = 1;
	for(i=1; i<row; i++)		//row = sparse[0][1] OR ftrans[0][0]
	{
		index[i] = index[i-1] + total[i-1];				//formula
	}
	
	for(i=1; i<=sparse[0][2]; i++)			//traversing through sparse matrix only once & adding elements in ftrans
	{
		row = sparse[i][1];
		col = sparse[i][0];
		val = sparse[i][2];
		
		pos = index[row];
		index[row]++;
		
		ftrans[pos][0] = row;
		ftrans[pos][1] = col;
		ftrans[pos][2] = val;
	}
	
	delete[] total;
	delete[] index;
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
	
	int ftrans[10][3];
	fastTranspose(sparse,ftrans);
	cout<<"\n\nFast Transpose Sparse MAtrix :\n";
	printSparse(ftrans);
	
	cout<<"\n\nConverting Sparse Matrix to 2-D MAtrix.....";
	sparse_to_matrix(ftrans,trans); 
	
	cout<<"\n\nTranspose of MAtrix :\n";
	printMatrix(trans,col,row);			//rows & columns are interchanged
	return 0;
}
