// Q. Basic Linked List on heap using struct in C.
// Note => 
// 1] scanf() needs address of memory where you want to store data.
// 2] struct Node* p = &T1; & int *q = &(T1.data);	//Both p & q will have same value (memory address) But, their 
//	  datatype is different.
// 3] Why typecasting in malloc()..? :- malloc() returns void pointer (typeless address). we cannot assign void pointer 
//	  directly to specific pointer. we have to use typecasting.
// eg - using p only

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Node* p;
	
	//allocating memory
	p = (struct Node*) malloc(sizeof(struct Node));
	p->next = (struct Node*) malloc(sizeof(struct Node));
	p->next->next = (struct Node*) malloc(sizeof(struct Node));
	p->next->next->next = NULL;
	
	//scanning values
	printf("\nEnter Values\n");
	scanf("%d", &(p->data));
	scanf("%d", &(p->next->data));
	scanf("%d", &(p->next->next->data));
	
	//printing list
	printf("\nLIST :\n");
	printf("%d ", p->data);
	printf("%d ", p->next->data);
	printf("%d ", p->next->next->data);
	
	free(p->next->next);
	free(p->next);
	free(p);
	return 0;
}
