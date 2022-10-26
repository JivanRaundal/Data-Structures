// Sparse Matrix

#include<iostream>
using namespace std;

void scanMatrix(int mat[10][10],int row,int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
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

//this function will create sparse matrix from given (MxN) matrix
void createSparseMatrix(int mat[10][10],int sparse[10][3],int row,int col)
{
    //0th row is an information row in sparse matrix
    sparse[0][0] = row;
    sparse[0][1] = col;
    int k=1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(mat[i][j] != 0)      //if element is non-zero, then make it's entry in sparse matrix
            {
                sparse[k][0] = i;           //row
                sparse[k][1] = j;           //col
                sparse[k][2] = mat[i][j];   //value
                k++;
            }
        }
    }
    sparse[0][2] = k-1;         //total non-zero elements in matrix
}

void printSparseMatrix(int sparse[10][3])
{
    //printing information row first
    cout<<"  "<<sparse[0][0]<<"  "<<sparse[0][1]<<"  "<<sparse[0][2];
    cout<<"\n-----------\n";
    for(int i=1; i<=sparse[0][2]; i++)
    {
        cout<<"  "<<sparse[i][0]<<"  "<<sparse[i][1]<<"  "<<sparse[i][2]<<"  \n";
    }
}

//this function is used to calculate simple transpose of matrix
void simpleTranspose(int sparse[10][3],int strans[10][3])
{
    strans[0][0] = sparse[0][1];
    strans[0][1] = sparse[0][0];
    strans[0][2] = sparse[0][2];
    int k=1;
    for(int i=0; i<strans[0][0]; i++)
    {
        for(int j=1; j<=sparse[0][2]; j++)
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

//this function will convert sparse matrix to nornmal matrix
void sparseToMat(int sparse[10][3],int transpose[10][10])
{
    for(int i=1; i<=sparse[0][2]; i++)
    {
        int row = sparse[i][0];
        int col = sparse[i][1];
        int val = sparse[i][2];
        transpose[row][col] = val;
    }
}

//fast transpose
void fastTranspose(int sparse[10][3],int ftrans[10][3])
{
    //initialize Information row
    ftrans[0][0] = sparse[0][1];
    ftrans[0][1] = sparse[0][0];
    ftrans[0][2] = sparse[0][2];

    //create target & index array
    int row = sparse[0][1];     //Or row = ftrans[0][0];
    int* total;
    int* index;
    total = new int[row];
    index  = new int[row];

    //initializing total array to 0
    int i;
    for(i=0; i<sparse[0][1]; i++)       //OR i<row
    {
        total[i] = 0;
    }

    //now, initializing total array elements using sparse matrix
    //here, total array will store total number of elements in each row of transpose matrix
    for(i=1; i<=sparse[0][2]; i++)
    {
        int row_no = sparse[i][1];
        total[row_no]++; 
    }
    
    //Now, intialing index array using target array
    //index array will store starting index of ith row elements
    index[0] = 1;               //0th row element will be stored in ftrans matrix from 1st index
    for(i=1; i<sparse[0][1]; i++)           //OR i<row
    {
        index[i] = index[i-1] + total[i-1];            //formula
    }

    //Now, we will insert record in ftrans matrix
    int col,val,pos;
    for(i=1; i<=sparse[0][2]; i++)
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
}

int main()
{
    int mat[10][10];
    int row,col;
    cout<<"\nEnter rows & columns : ";
    cin>>row>>col;
    cout<<"\nEnter Matrix elements\n";
    scanMatrix(mat,row,col);
    cout<<"\n\nMatrix\n";
    printMatrix(mat,row,col);

    //convert to sparse matrix
    int sparse[10][3];
    createSparseMatrix(mat,sparse,row,col);
    cout<<"\n\nSparse Matrix\n";
    printSparseMatrix(sparse);

    //simple transpose
    int strans[10][3];          //transpose matrix
    simpleTranspose(sparse, strans);
    cout<<"\n\nSparse Transpose Matrix\n";
    printSparseMatrix(strans);
    

    //converting sparse matrix to normal matrix
    int transpose[10][10] = {0};        //initialize to zero
    sparseToMat(strans,transpose);
    cout<<"\n\nTranspose of Matrix\n";
    printMatrix(transpose,col,row);

    //Fast Transpose 
    int ftrans[10][3];              //fast transpose sparse matrix
    int fastTrans[10][10] = {0};    //transpose of original matrix
    fastTranspose(sparse,ftrans);
    cout<<"\n\nFast Transpose Matrix\n";
    printSparseMatrix(ftrans);
    sparseToMat(ftrans,fastTrans);
    cout<<"\n\nTranspose of Matrix\n";
    printMatrix(fastTrans,col,row);

    return 0;
}