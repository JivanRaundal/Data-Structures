// Scan Matrix & Print

#include<iostream>
using namespace std;

void scanMatrix(int mat[10][10],int row,int col)
{
    cout<<"\nEnter "<<row<<" X "<<col<<" matrix :\n";
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin>>mat[i][j];
        }
    }
}

void printMatrix(int mat[10][10],int row,int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<"  "<<mat[i][j];
        }
        cout<<"\n";
    }
}

void addMatrix(int mat1[10][10],int mat2[10][10],int row,int col)
{
    int add[10][10];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            add[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout<<"\n\nAddition Matrix :\n";
    printMatrix(add,row,col);
}

void mulMatrix(int mat1[10][10],int mat2[10][10],int row1,int col1,int col2)
{
    int mul[10][10];
    int sum;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            sum = 0;
            for(int k=0; k<col1; k++)
            {
                sum = sum + (mat1[i][k] * mat2[k][j]);
            }
            mul[i][j] = sum;
        }
    } 

    cout<<"\n\nMultiplication Matrix :\n";
    printMatrix(mul,row1,col2);
}

void transMatrix(int mat[10][10],int row,int col)
{
    int trans[10][10];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            trans[j][i] = mat[i][j];        //rows & col are interchanged
        }
    }

    printMatrix(trans, col, row);
}

int main()
{
    int mat1[10][10];
    int mat2[10][10];
    int row1,col1,row2,col2;
    cout<<"\nEnter rows & columns for Matrix 1 : ";
    cin>>row1>>col1;
    scanMatrix(mat1,row1,col1);
    cout<<"\n\nTranspose of Matrix 1\n";
    transMatrix(mat1,row1,col1);
    cout<<"\nEnter rows & columns fot Matrix 2 : ";
    cin>>row2>>col2;
    scanMatrix(mat2,row2,col2);
    cout<<"\n\nTranspose of Matrix 2\n";
    transMatrix(mat2,row2,col2);
    cout<<"\n\nMatrix 1 :\n";
    printMatrix(mat1,row1,col1);
    cout<<"\n\nMatrix 2 :\n";
    printMatrix(mat2,row2,col2);
    addMatrix(mat1,mat2,row1,col1);     //Note :- for matrix addition rows & col of 2 matrix must be same
    mulMatrix(mat1,mat2,row1,col1,col2);
    return 0;
}