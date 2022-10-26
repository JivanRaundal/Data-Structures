// Q 3]. DLL through C

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev, *next;
}Node;

typedef struct DLL
{
	Node * head;
}DLL;

Node* create()
{
	Node * h = NULL;
	Node * p = NULL;
	
	char str[10];
	printf("\nEnter first data or 'STOP' to stop : ");
	scanf("%s",str);		//str = &str[0]
	if(strcmp(str,"STOP") == 0)
	{
		return;
	}
	h = (Node*) malloc(sizeof(Node));
	h->data = atoi(str);
	h->prev = NULL;
	h->next = NULL;
	
	p = h;
	while(1)
	{
		printf("\nEnter next data or 'STOP' to stop : ");
		scanf("%s", str);	//str = &str[0]
		if(strcmp(str,"STOP") == 0)
		{
			break;
		}
		p->next = (Node*) malloc(sizeof(Node));
		p->next->prev = p;
		p = p->next;
		p->data = atoi(str);
		p->next = NULL;	
	}
	return h;
}

void show(Node * p)
{
	if(p == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	while(p != NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
}

void rev_show(Node * p)
{
	if(p == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	while(p->next != NULL)
	{
		p = p->next;
	}
	while(p != NULL)
	{
		printf(" %d", p->data);
		p = p->prev;
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

Node* addatbeg(Node *p,int x)
{
	if(p == NULL)
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->prev = NULL;
		p->next = NULL;
		return p;
	}
	else
	{
		Node * h = (Node*) malloc(sizeof(Node));
		h->data = x;
		h->prev = NULL;
		h->next = NULL;
		h->next = p;
		p->prev = h;
		return h;	
	}
}

Node* addatend(Node *p,int x)
{
	if(p == NULL)
	{
		p = (Node*) malloc(sizeof(Node));
		p->data = x;
		p->prev = NULL;
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
		p->next->prev = p;
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
	if(pos < 1 || pos > n+1)
	{
		printf("\nInvalid Posotion");
		return p;
	}
	printf("\nValid Postion");
	if(pos == 1)
	{
		p = addatbeg(p,x);
		return p;
	}
	else
	{
		Node * h = p;
		Node * q;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = (Node*) malloc(sizeof(Node));
		q->data = x;
		q->prev = NULL;
		q->next = NULL;
		
		q->next = p->next;
		p->next = q;
		q->prev = p;
		if(q->next != NULL)		//OR if(pos != n+1)
		{
			q->next->prev = q;
		}
		return h;
	}
}

Node* delatbeg(Node *p)
{
	if(p == NULL)
	{
		printf("\nEmpty List...can't delete'");
		return p;
	}
	if(p->next == NULL)		//List contains only 1 element
	{
		free(p);
		return NULL;
	}
	else					//list contains multiple nodes
	{
		Node * h;
		h = p->next;
		h->prev = NULL;
		free(p);
		return h;
	}
}

Node* delatend(Node *p)
{
	if(p == NULL)
	{
		printf("\nEmpty List...can't delete'");
		return p;
	}
	if(p->next == NULL)		//List contains only 1 element
	{
		free(p);
		return NULL;
	}
	else					//list contains multiple nodes
	{
		Node * h = p;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->prev->next = NULL;
		free(p);
		return h;
	}
}

Node* delbypos(Node *p,int pos)
{
	int n;
	n = count(p);
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
		Node * q;
		int i;
		for(i=1; i<pos-1; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		if(q->next != NULL)		//OR if(pos != n)
		{
			p->next->prev = p;
		}
		free(q);
		return h;
	}
}

Node* makeEmpty(Node *p)
{
	Node * q;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		if(p != NULL)
		{
			p->prev = NULL;
		}
		//printf("\n-");
		free(q);
	}
	return NULL;
}

int main()
{
	DLL L;
	L.head = NULL;	
	int pos,x,ch;
	
	do
	{
		printf("\n\n____________MENUE____________");
		printf("\n1.  create list");
		printf("\n2.  show list");
		printf("\n3.  show reverse list");
		printf("\n4.  count nodes");
		printf("\n5.  search data");
		printf("\n6.  add at beginning");
		printf("\n7.  add at end");
		printf("\n8.  add by position");
		printf("\n9.  delete at beginning");
		printf("\n10. delete at end");
		printf("\n11. delete by position");
		printf("\n12. make list empty");
		printf("\n13. exit");
		printf("\n_____________________________");
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
				printf("\nList in reverse order :\n");
				rev_show(L.head);
				break;
				
			case 4:
				printf("\nTotal nodes = %d", count(L.head));
				break;
				
			case 5:
				printf("\nEnter data to search : ");
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
				
			case 6:
				printf("\nEnter data to add at beginning : ");
				scanf("%d", &x);
				L.head = addatbeg(L.head,x);
				break;
				
			case 7:
				printf("\nEnter data to add at end : ");
				scanf("%d", &x);
				L.head = addatend(L.head,x);
				break;
				
			case 8:
				printf("\nEnter position & data : ");
				scanf("%d%d", &pos, &x);
				L.head = addbypos(L.head,pos,x);
				break;
				
			case 9:
				L.head = delatbeg(L.head);
				break;
				
			case 10:
				L.head = delatend(L.head);
				break;
				
			case 11:
				printf("\nEnter position of data to be deleted : ");
				scanf("%d", &pos);
				L.head = delbypos(L.head,pos);
				break;
				
			case 12:
				L.head = makeEmpty(L.head);
				break;
				
			case 13:
				exit(0);
				
			default:
				printf("\nInvalid choice...Plz try again!!!");
		}
	}while(ch != 13);
	return 0;
}

