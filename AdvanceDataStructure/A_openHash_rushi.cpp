#include<iostream>
#include"SLL.h"
using namespace std;
class OpenHash//hash(x) = x%7;
{
	int div;
	SLL *S;
	public:
		OpenHash(int x)
		{
			div = x;
			S = new SLL[div];
		}
		int HashFunc(int x)
		{
			return x%div;
		}
		void addData()
		{
			int x;
			cout<<"\nKeep Entering data(-1 to stop): ";
			while(1)
			{
				cin>>x;
				if(x==-1)
					break;
				S[x%div].AddAtBeg(x);		
			}
		}
		void Insert(int x)
		{
			S[x%div].AddAtBeg(x);
		}
		void Delete(int x)
		{
			S[x%div].deleteNode(x);
		}
		void ShowData()
		{
			for(int i=0; i<div; i++)
			{
				cout<<i<<" -> ";
				S[i].show();
				cout<<endl;
			}
		}
		void Search(int x)
		{
			S[x%div].search(x);
		}
};
int main()
{
	OpenHash OH(7);
	OH.addData();
	OH.Delete(39);
	OH.Insert(25);
	OH.ShowData();
	
	return 0;
}

