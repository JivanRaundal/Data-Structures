// Linked List

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
		
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int x)
		{
			data = x;
			next = NULL;
		}
};

int main()
{
	Node T1(10);
	Node T2(20);
	Node T3(30);
	
	T1.next = &T2;
	T2.next = &T3;
	
	cout<<"\nT1.data = "<<T1.data;
	cout<<"\nT2.data = "<<T1.next->data;
	cout<<"\nT3.data = "<<T1.next->next->data;
	
	return 0;
}
