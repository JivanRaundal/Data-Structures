#include<stdio.h>

int main()
{
    int * p;
    p = (int*) malloc(2 * sizeof(int));
    puts("Enter two numbers :\n");
    scanf("%d%d",(p+0),(p+1));
    printf("Two numbers are :\n");
    printf("%d  %d",*(p+0),*(p+1));
    return 0;
}