// Runtime 2-D Array :- (accessing using pointer arithmetic)

#include<iostream>
using namespace std;

int main()
{
	int row,col;
	int ** num;
	
	cout<<"\nEnter rows & columns : ";
	cin>>row>>col;
	
	num = new int*[row];		//rutime array of pointers on heap;
	
	int i,j;
	for(i=0; i<row; i++)
	{
		*(num+i) = new int[col];			
	}
	
	//scanning
	cout<<"\n\nEnter Matrix :\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"\nelement num["<<i<<"]["<<j<<"] : ";
			cin>>*(*(num+i)+j);
		}
	}
	
	//printing matrix
	cout<<"\n\nPrinting Matrix :\n\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<*(*(num+i)+j);
		}
		cout<<"\n";
	}
	
	delete[] num;
	return 0;
}
