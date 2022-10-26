//	structure in cpp

#include<iostream>
using namespace std;

struct Node
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
		void show()
		{
			cout<<"\nIn Node show()";
		}
};

struct child : public struct Node
{
	public:
		int x;
		void show()
		{
			x = 10;
			cout<<"\nIn child show(), x = "<<x;
		}
};

int main()
{
	struct Node T1,T2,T3;
	T1.data = 10;
	T2.data = 20;
	T3.data = 30;
	T1.next = &T2;
	T2.next = &T3;
	cout<<"List :\n";
	cout<<" "<<T1.data;
	cout<<" "<<T1.next->data;
	cout<<" "<<T1.next->next->data;
	
	struct child obj;
	obj.Node::show();
	//obj.show();
	
	struct Node * p = &obj;
	//cout<<"\n"<<p->show();
	return 0;
}
