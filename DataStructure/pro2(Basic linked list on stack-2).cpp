//			LINKED LIST
// # Basic linked list on stack :-
// eg- using head pointer access data of all Nodes

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
};

int main()
{
	Node T1,T2,T3;
	
	Node * head;
	head = &T1;
	//assign values to T1,T2 & T3 data using head, link Nodes using head & also print data using head pointer
	head->next = &T2;				//same as	T1.next = &T2;
	head->next->next = &T3;			//same as	T2.next = &T3;
	head->next->next->next = NULL;	//same as   T3.next = NULL;
	
	head->data 	= 10;				//T1.data = 10;
	head->next->data = 20;			//T2.data = 20;
	head->next->next->data = 30;	//T3.data = 30;
	
	cout<<"\nT1 data = "<<head->data;
	cout<<"\nT2 data = "<<head->next->data;
	cout<<"\nT3 data = "<<head->next->next->data;
	
	return 0;
}
