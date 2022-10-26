// 2-D Matrix :-

#include<iostream>
using namespace std;

int main()
{
	int row, col;
	cout<<"\nEnter row & column : ";
	cin>>row>>col;
	
	int ** num;
	num = new int*[row];
	int i;
	for(i=0; i<row; i++)
	{
		//*(num+i) = new int[col];
		num[i] = new int[col];
	}
	
	cout<<"\n\nEnter "<<row<<"X"<<col<<" matrix\n";
	int j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cin>>num[i][j];
		}
	}
	
	cout<<"\n\nMatrix\n";
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"  "<<num[i][j];
		}
		cout<<"\n";
	}
	
	return 0;
}
