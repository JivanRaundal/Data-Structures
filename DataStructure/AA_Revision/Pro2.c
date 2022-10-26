
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n;
	printf("\nHow many integers ? ");
	scanf("%d", &n);
	int * p;
	p = (int*)malloc(sizeof(int) * n);
	puts("\nEnter the integers :\n");
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",(p+i));
	}
	int sum=0;
	i=0;
	while(i<n)
	{
		sum = sum + *(p+i);
		i++;
	}
	printf("\nAddition = %d",sum);
	free(p);
}
