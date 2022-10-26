 // Q 2].

#include<iostream>
using namespace std;

void sort(int *p,int n)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(*(p+i) > *(p+j))
			{
				int temp;
				temp   = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

void merge(int *r,int *p,int *q)
{
	int i=0, j=0, k=0;
	
	while(i<6 && j<4)
	{
		if(*(p+i) < *(q+j))
		{
			*(r+k) = *(p+i);
			i++;
			k++;
		}
		else
		{
			*(r+k) = *(q+j);
			j++;
			k++;
		}
	}
	while(i<6)
	{
		*(r+k) = *(p+i);
		i++;
		k++;
	}
	while(j<4)
	{
		*(r+k) = *(q+j);
		j++;
		k++;
	}
}

int main()
{
	int num1[] = {32,5,16,55,18,41};
	int num2[] = {12,3,6,36};
	int res[10];
	
	sort(num1,6);
	sort(num2,4);
	merge(res,num1,num2);
	
	cout<<"\n\nResult array :\n";
	for(int i=0; i<10; i++)
	{
		cout<<" "<<res[i];
	}
	
	return 0;
}
