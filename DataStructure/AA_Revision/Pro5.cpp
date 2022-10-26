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
	
	Node * head;
	head = &T1;
	head->next = &T2;
	head->next->next = &T3;
	head->next->next->next = NULL;
	
	cout<<"\nPrinting data :\n";
	cout<<head->data<<" ";
	cout<<head->next->data<<" ";
	cout<<head->next->next->data;
	
	return 0;
}
