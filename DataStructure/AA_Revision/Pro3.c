#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	puts("\nHow many students : ");
	scanf("%d",&n);
	int * wt;
	wt = (int*) malloc(sizeof(int)*n);
	printf("\nEnter the weights :\n");
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",(wt+i));
	}
	int max = *(wt+0);
	for(i=1; i<n; i++)
	{
		if(max < *(wt+i))
		{
			max = *(wt+i);	
		}
	}
	printf("\nMaximum Weight is = %d",max);
	free(wt);
	return 0;
}
