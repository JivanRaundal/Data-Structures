//

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
	Node* h_arr[5] = {new Node()};
	int x,y;
	
	for(int i=0; i<5; i++)
	{
		cout<<"\nEnter element : ";
		cin>>x;
		y = x%5;
		h_arr[y] = new Node(x);
	}
	
	cout<<"\n\nArray :\n";
	for(int i=0; i<5; i++)
	{
		cout<<" "<<h_arr[i]->data;
	}
	
	cout<<"\nEnter element to be searched : ";
	cin>>x;
	y = x%5;
	if(h_arr[y]->data == x)
	{
		cout<<"\nFound";
	}
	else
	{
		cout<<"\nNot Found";
	}
	return 0;
}
