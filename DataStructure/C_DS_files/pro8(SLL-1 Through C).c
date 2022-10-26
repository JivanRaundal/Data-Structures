// SLL through C

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}Node;

typedef struct SLL
{
	Node * head;
}SLL;

Node* create()
{
	Node * h = NULL;
	Node * p = NULL;
	int n,x,i;
	
	printf("\nHow many nodes? ");
	scanf("%d", &n);
	//check if number is valid or not
	if(n < 1)
	{
		printf("\nInvalid Number");
		return NULL;
	}
	
	printf("\nEnter first data : ");
	scanf("%d", &x);
	h = (Node*) malloc(sizeof(Node));
	h->data = x;
	h->next = NULL;
	
	p = h;
	for(i=1; i<=n-1; i++)
	{
		printf("\nEnter next data : ");
		scanf("%d", &x);
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
		p->data = x;
		p->next = NULL;
	}
	printf("\nList created successfully");
	return h;
}

void show(Node *p)
{
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int count(Node *p)
{
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int search(Node *p,int x)
{
	while(p != NULL)
	{
		if(p->data == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

Node* addatbeg(Node *p,int x)
{
	if(p == NULL)	//if list ie empty
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->next = NULL;
		return p;
	}
	else			//if list is not empty
	{
		Node *q = NULL;
		q = (Node*) malloc(sizeof(Node));
		q->data = x;
		q->next = NULL;
		q->next = p;
		return q;
	}
}

Node* addatend(Node *p,int x)
{
	if(p == NULL)	//if list is empty
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->next = NULL;
		return p;
	}
	else			//if list is not empty
	{
		Node * h = p;
		while(p->next != NULL)	//p will refer to last node
		{
			p = p->next;
		}
		p->next = (Node*) malloc(sizeof(Node));
		p = p->next;
		p->data = x;
		p->next = NULL;
		return h;
	}
}

Node* addbypos(Node *p,int pos,int x)
{
	int n;
	n = count(p);
	//check if position is valid or not
	if(pos < 1 || pos > n+1)
	{
		printf("\nInvalid Position");
		return p;
	}
	printf("\nValid position");
	if(pos == 1)
	{
		p = addatbeg(p,x);
		return p;
	}
	else
	{
		Node *h = p;
		Node *q;
		int i;
		for(i=1; i<(pos-1); i++)	//p will refer to node at location (pos-1) i.e. node to be updated
		{
			p = p->next;
		}
		q = (Node*) malloc(sizeof(Node));	//q will refer to node which is to be added at position
		q->data = x;
		q->next = NULL;
		q->next = p->next;
		p->next = q;
		return h;
	}
}

Node* delatbeg(Node *p)
{
	if(p == NULL)			//if list is empty
	{
		printf("\nEmpty List, Can't delete");
		return NULL;
	}
	if(p->next == NULL)		//if list contains only 1 node
	{
		free(p);			//delete node
		return NULL;
	}
	else					//list contains more than 1 nodes
	{
		Node * q = NULL;
		q = p->next;
		free(p);
		return q;
	}
}

Node* delatend(Node *p)
{
	if(p == NULL)			//if list is empty
	{
		printf("\nEmpty List, Can't delete");
		return NULL;
	}
	if(p->next == NULL)		//if list contains only 1 node
	{
		free(p);
		return NULL;
	}
	else					//if list contains more than 1 node
	{
		Node *h = p;
		Node *q = NULL;
		while(p->next != NULL)		//p will refer to last node. i.e. node to be deletd
		{
			q = p;					//q will refer to last second node. i.e. node to be updated
			p = p->next;
		}
		q->next = NULL;
		free(p);
		return h;
	}
}

Node* delbypos(Node *p,int pos)
{
	int n;
	n = count(p);
	//check is position is valid or not
	if(pos < 1 || pos > n)
	{
		printf("\nInvalid Position");
		return p;
	}
	printf("\nValid Position");
	if(pos == 1)
	{
		p = delatbeg(p);
		return p;
	}
	else
	{
		Node *h = p;
		Node *q = NULL;
		int i;
		for(i=1; i<(pos-1); i++)	//p will refer to node at location (pos-1) i.e. node to be updated
		{
			p = p->next;
		}
		q = p->next;					//q will refer to the node to be deleted
		p->next = q->next;
		free(q);
		return h;
	}
}

void concat(Node *h1,Node *h2)	//Note - this fun will not work of h1 is NULL (i.e. if 1st list is empty)
{
	while(h1->next != NULL)
	{
		h1 = h1->next;
	}
	h1->next = h2;
}

/*Node* concat(Node *h1,Node *h2)	//Note - this will work for all possibilities
{
	if(h1 == NULL)	//if list1 is empty
	{
		h1 = h2;
		return h1;
	}
	else
	{
		Node *p = h1;
		while(h1->next != NULL)
		{
			h1 = h1->next;
		}
		h1->next = h2;
		return p;
	}
}*/

int main()
{
	SLL L1,L2;
	L1.head = NULL;
	L2.head = NULL;
	
	int pos,x,ch;
	do
	{
		puts("\n\n____________MENUE____________");
		puts("\n1.  create list");
		puts("\n2.  show list");
		puts("\n3.  count nodes");
		puts("\n4.  search data");
		puts("\n5.  add at beginning");
		puts("\n6.  add at end");
		printf("\n7.  add by position");
		printf("\n8.  delete at beginning");
		printf("\n9.  delete at end");
		printf("\n10. delete by position");
		printf("\n11. concatenate");
		printf("\n12. exit");
		printf("\n_____________________________");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				L1.head = create();
				break;
				
			case 2:
				printf("\nLIST :\n");
				show(L1.head);
				break;
				
			case 3:
				printf("\nTotal nodes = %d", count(L1.head));
				break;
				
			case 4:
				printf("\nEnter data to search : ");
				scanf("%d", &x);
				if(search(L1.head,x))
				{
					printf("\nData Found");
				}
				else
				{
					printf("\nData Not Found");
				}
				break;
				
			case 5:
				printf("\nEnter data to add at beginning : ");
				scanf("%d", &x);
				L1.head = addatbeg(L1.head,x);
				break;
				
			case 6:
				printf("\nEnter data to add at end : ");
				scanf("%d", &x);
				L1.head = addatend(L1.head,x);
				break;
				
			case 7:
				printf("\nEnter position & data : ");
				scanf("%d%d", &pos, &x);
				L1.head = addbypos(L1.head,pos,x);
				break;
				
			case 8:
				L1.head = delatbeg(L1.head);
				break;
				
			case 9:
				L1.head = delatend(L1.head);
				break;
				
			case 10:
				printf("\nEnter position of data to be deleted : ");
				scanf("%d", &pos);
				L1.head = delbypos(L1.head,pos);
				break;
				
			case 11:
				printf("\nCreate another list to be concatenated");
				L2.head = create();
				concat(L1.head, L2.head);
				//L1.head = concat(L1.head,L2.head);
				break;
				
			case 12:
				exit(0);
				
			default:
				printf("\nInvalid choice...Plz try again!!!");
		}
	}while(ch != 12);
	return 0;
}
