// Q 6]

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

//prototypes
Node* addatend(Node *p,int x);

Node* create()
{
	char str[10];
	Node * h = NULL;
	
	printf("\nEnter first data or 'STOP' to stop : ");
	scanf("%s", str);
	if(strcmp(str,"STOP") == 0)
	{
		return NULL;
	}
	h = (Node*) malloc(sizeof(Node));
	h->data = atoi(str);
	h->next = NULL;
	
	while(1)
	{
		printf("Enter next data or 'STOP' to stop : ");
		scanf("%s", str);
		if(strcmp(str,"STOP") == 0)
		{
			break;	
		}
		h = addatend(h,atoi(str));
	}
	return h;
}

void show(Node * p)
{
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int count(Node * p)
{
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int search(Node * p,int x)
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

Node* addatbeg(Node * p,int x)
{
	if(p == NULL)
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->next = NULL;
		return p;
	}
	else
	{
		Node * q = NULL;;
		q = (Node*) malloc(sizeof(Node));
		q->data = x;
		q->next = NULL;
		q->next = p;
		return q;
	}
}

Node* addatend(Node * p,int x)
{
	if(p == NULL)
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->next = NULL;
		return p;
	}
	else
	{
		Node * h = p;
		while(p->next != NULL)
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

Node* addbypos(Node * p,int pos,int x)
{
	int n = count(p);
	//check valid position
	if(pos < 1 || pos > n+1)
	{
		printf("\nInvalid Position");
		return p;
	}
	printf("\nValid Position");
	if(pos == 1)
	{
		p = addatbeg(p,x);
		return p;
	}
	else
	{
		Node * h = p;
		Node * q = NULL;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;		// p will refer to node at pos-1 i.e. node to be updated
		}
		q = (Node*) malloc(sizeof(Node));	//q is new node to be added after p
		q->data = x;
		q->next = NULL;
		q->next = p->next;
		p->next = q;
		return h;
	}
}

Node* delatbeg(Node * p)
{
	if(p == NULL)
	{
		printf("\nCan't delete ..list is empty");
		return NULL;
	}
	if(p->next == NULL)		//if list contains only 1 node
	{
		free(p);
		return NULL;
	}
	else
	{
		Node * q = p->next;
		free(p);
		return q;
	}
}

Node* delatend(Node * p)
{
	if(p == NULL)
	{
		printf("\nCan't delete ..list is empty");
		return NULL;
	}
	if(p->next == NULL)		//if list contains only 1 node
	{
		free(p);
		return NULL;
	}
	else
	{
		Node * h = p;
		Node * q;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		free(p);
		return h;
	}
}

Node* delbypos(Node * p,int pos)
{
	int n = count(p);
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
		Node * h = p;
		Node * q = NULL;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;		//p will refer to previous node of node to bbe deleted
		}
		q = p->next;	//q will refer to node to bbe deleted
		p->next = q->next;
		free(q);
		return h;
	}
}

int main()
{
	SLL L;
	L.head = NULL;
	int pos,x,ch;
	
	do
	{
		printf("\n\n__________MENUE__________");
		printf("\n1.  create list");
		printf("\n2.  show list");
		printf("\n3.  count nodes");
		printf("\n4.  search data");
		printf("\n5.  add at beg");
		printf("\n6.  add at end");
		printf("\n7.  add by position");
		printf("\n8.  del at beg");
		printf("\n9.  del at end");
		printf("\n10. del by position");
		printf("\n11. exit");
		printf("\n_________________________");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				L.head = create();
				break;
				
			case 2:
				printf("\nLIST :\n");
				show(L.head);
				break;
				
			case 3:
				printf("\nTotal Nodes = %d", count(L.head));
				break;
				
			case 4:
				printf("\nEnter data to be searched : ");
				scanf("%d", &x);
				if(search(L.head,x))
				{
					printf("\nData Found");
				}
				else
				{
					printf("\nData Not Found");
				}
				break;
				
			case 5:
				printf("\nEnter data to add at beg : ");
				scanf("%d", &x);
				L.head = addatbeg(L.head,x);
				break;
				
			case 6:
				printf("\nEnter data to add at the end : ");
				scanf("%d", &x);
				L.head = addatend(L.head,x);
				break;
				
			case 7:
				printf("\nEnter position & data to be added : ");
				scanf("%d%d", &pos,&x);
				L.head = addbypos(L.head,pos,x);
				break;
				
			case 8:
				L.head = delatbeg(L.head);
				break;
				
			case 9:
				L.head = delatend(L.head);
				break;
				
			case 10:
				printf("\nEnter position of data to be deleted : ");
				scanf("%d", &pos);
				L.head = delbypos(L.head,pos);
				break;
				
			case 11:
				exit(0);
				
			default:
				printf("\nInvalid Choice...Plz try again!!!");
		}
		
	}while(ch != 11);
	return 0;
}
