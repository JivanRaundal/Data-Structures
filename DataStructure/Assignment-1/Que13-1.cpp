// Q 13]. diagram-1)

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
	
	T1.next = &T2;
	T2.next = &T3;
	T3.next = NULL;
	
	cout<<"\nList :\n";
	cout<<" "<<T1.data;
	cout<<" "<<T1.next->data;
	cout<<" "<<T1.next->next->data;
	return 0;
}
