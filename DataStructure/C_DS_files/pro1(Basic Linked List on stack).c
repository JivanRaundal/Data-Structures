// Q. Basic Linked List on stack using structure in C.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

int main()
{
	struct Node T1,T2,T3;
	
	T1.data = 10;
	T2.data = 20;
	T3.data = 30;
	
	//linking nodes
	T1.next = &T2;
	T2.next = &T3;
	T3.next = NULL;
	
	//printing using T1
	printf("LIST :\n");
	printf("%d ", T1.data);
	printf("%d ", T1.next->data);
	printf("%d ", T1.next->next->data);
	
	return 0;
}
