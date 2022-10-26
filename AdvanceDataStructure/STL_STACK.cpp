// STL Stack

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int> S;
	
	S.push(10);
	S.push(20);
	S.push(30);
	S.push(40);
	S.push(50);
	
	cout<<"\nStack = ";
	while(!S.empty())
	{
		cout<<"  "<<S.top();
		S.pop();
	}
	
	return 0;
}
