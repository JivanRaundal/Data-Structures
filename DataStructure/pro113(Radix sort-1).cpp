// Radix Sort

#include<iostream>
using namespace std;

int find_max(int * p,int n)		//this function will return maximum element from array
{
	int i;
	int max=*(p+0);
	for(i=0; i<n; i++)
	{
		if(*(p+i) > max)
		{
			max = *(p+i);
		}
	}
	return max;
}

int main()
{
	int num[10];
	int i;
	cout<<"\nEnter elements of array\n";
	for(i=0; i<10; i++)
	{
		cout<<"\nelement "<<i<<" : ";
		cin>>num[i];
	}
	
	cout<<"\n\nArray Before Sorting :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	
	//-------------------------------------------RADIX SORT-------------------------------------------------
	int bucket[10][20];				//2-D bucket array (rows will be 10 always, columns can be changed)
	int count[10];					//count array will store total no. of elements in each bucket
	int n=10;
	int bucketno,col,j,k,max,passes=0,div=1;
	
	//find max element in array
	max = find_max(num,n);
	cout<<"\n\nMax element in array : "<<max;
	
	//now, passes will be the no. of digits in max element
	while(max > 0)
	{
		max = max/10;
		passes++;
	}
	cout<<"\n\nNo of iterations, passes = "<<passes;
	
	//main loop
	while(passes > 0)
	{
		//initialize count array		(to make bucket array virtual empty)
		for(i=0; i<10; i++)
		{
			count[i] = 0;
		}
		
		//classify all elements in bucket array based on unit,tens,hundreds... digit 
		for(i=0; i<n; i++)			// n = no. of elements in array
		{
			bucketno = (num[i]/div)%10;		//will give row/bucket number
			col = count[bucketno];			//column / position in individual bucket
			//place num[i] in bucket array
			bucket[bucketno][col] = num[i];
			count[bucketno]++;
		}
		
		/*cout<<"\n\nBucket array\n";				//for understanding the iterations
		for(i=0; i<10; i++)
		{
			cout<<i<<" th row : ";
			for(j=0; j<count[i]; j++)
			{
				cout<<" "<<bucket[i][j];
			}
			cout<<"\n";
		} */
		
		//copy all elements from bucket array to the original array (sequence = row wise & inside row column wise)
		k=0;									//k is index of original array (num array)
		for(i=0; i<=9; i++)						//i is bucket number
		{
			for(j=0; j<count[i]; j++)			//count[i] will give total no. of elements in ith bucket
			{
				num[k] = bucket[i][j];
				k++;
			}
		}
		
		//1st iteration ends here for next iteration
		div = div * 10;
		passes--;
	}
	//--------------------------------------------------------------------------------------------------------
	
	cout<<"\n\nArray After Sorting :\n";
	for(i=0; i<10; i++)
	{
		cout<<" "<<num[i];
	}
	return 0;
}
