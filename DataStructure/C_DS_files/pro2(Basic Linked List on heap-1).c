// Q. Basic Linked List on heap using struct in C.
// Note => 
// 1] scanf() needs address of memory where you want to store data.
// 2] struct Node* p = &T1; & int *q = &(T1.data);	//Both p & q will have same value (memory address) But, their 
//	  datatype is different.
// 3] Why typecasting in malloc()..? :- malloc() returns void pointer (typeless address). we cannot assign void pointer 
//	  directly to specific pointer. we have to use typecasting.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Node *p,*q,*r;
	
	//allocating memory on heap at runtime
	p = (struct Node*) malloc(sizeof(struct Node));
	q = (struct Node*) malloc(sizeof(struct Node));
	r = (struct Node*) malloc(sizeof(struct Node));
	
	//scanning values
	printf("Enter values\n");
	scanf("%d", &(p->data));
	scanf("%d", &(q->data));
	scanf("%d", &(r->data));
	
	//linking nodes
	p->next = q;
	q->next = r;
	r->next = NULL;	//explicitly we have to make NULL bcz no constructor here
	
	//printing list using p only
	printf("\n\nLIST :\n");
	printf("%d ", p->data);
	printf("%d ", p->next->data);
	printf("%d ", p->next->next->data);
	
	free(p);
	free(q);
	free(r);
	return 0;	
}
