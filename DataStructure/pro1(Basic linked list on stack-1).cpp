//			LINKED LIST
// # Basic linked list on stack :-
// eg-

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
	
	T1.data = 10;
	T2.data = 20;
	T3.data = 30;
	
	//linkind Nodes
	T1.next = &T2;
	T2.next = &T3;
	T3.next = NULL;
	
	//accessing x of T1,T2 & T2 using T1 only
	cout<<"\nT1 data = "<<T1.data;
	cout<<"\nT2 data = "<<T1.next->data;
	cout<<"\nT3 data = "<<T1.next->next->data;
	
	return 0;
}
