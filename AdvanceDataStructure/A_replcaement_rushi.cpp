#include<iostream>
using namespace std;
typedef struct HashNode
{
	int data;
	int chain;
	public:
	HashNode(int v)
	{
		data = v;
		chain=-1;
	}
}HN;
class ClosedHash
{
	HN** table;
	int div;
	public:
		int capacity;
		int size;
		ClosedHash(int x,int cap)
		{
			capacity = cap;size=0;
			div = x;
			table = new HN*[capacity];
			for(int i=0; i<capacity; i++)
				table[i]=NULL;
		}
		int HashFunc(int x)
		{
			return x%div;
		}
		void Insert(int x)
		{
			if(size == capacity)
			{
				cout<<"\nHash Table is full! ";
				return;
			}
//			HN* t = new HN(x);
			int ind = this->HashFunc(x);
			int index = ind;
			//linear probing 
			while(table[ind]!=NULL && table[ind]->data!=x)//to find next empty slot and avoid duplications
			{
				ind++;	
				ind = ind%capacity;
			}
			//we get here next empty slot
			if(table[ind]==NULL)//check empty slot is from null or deleted ele
			{
				table[ind]= new HN(x);
				if(ind!=index)//two possiblieties data misplaced or not
				{
					if(index!=this->HashFunc(table[index]->data))//data is misplaced
					{
						HN* t;
						t = table[index];
						table[index] = table[ind];
						table[ind]=t;
						int p=this->HashFunc(table[ind]->data);
						while(table[p]->chain!=index)
						{
							p = table[p]->chain;
						}
						table[p]->chain=ind;
						return;
					}
					while(table[index]->chain!=-1)//data not misplaced chain is made
					{
						index = table[index]->chain;
					}
					table[index]->chain = ind;
					
				}	
				size= size+1;
			}
			else
			{
				cout<<"\nDuplicate entry";
			}
		}
		void Delete(int x)
		{
			if(this->Search(x)==1)
			{
				int ind = this->HashFunc(x);
				int prev=-1;
				do
				{
					if(table[ind]->data==x)
					{
						break;
					}
					prev = ind;
					ind = table[ind]->chain;	
				}while(ind!=-1);
				if(prev==-1)
				{
					delete table[ind];
					table[ind]=NULL;
				}	
				else
				{
					delete table[ind];
					table[ind]=NULL;
					table[prev]->chain=-1;
				}
				size = size -1;	
			}
			else
			{
				cout<<"\nCan not delete, data not present! ";
			}
		}
		int Search(int x)
		{
			int ind = this->HashFunc(x);
			do
			{
				if(table[ind]->data==x)
				{
					cout<<"\nData is found";
					return 1;
				}
				ind = table[ind]->chain;	
			}while(ind!=-1);
			cout<<"\nData not found";
			return 0;
		}
		void Show()
		{
			for(int i=0; i<capacity; i++)
			{
				if(table[i]!=NULL)
				{
					cout<<"\n"<<i<<": "<<table[i]->data<<" "<<table[i]->chain<<" ";
				}
			}
		}
};
int main()
{
	ClosedHash CH(7,8);

/*	for(int i=1; i<10; i++)
	{
		CH.Insert(i*6);
	}*/
	CH.Insert(5);
	CH.Insert(47);
	// CH.Show();
	CH.Insert(6);
	CH.Insert(27);
	CH.Insert(34);
	//cout<<"\nsize: "<<CH.size<<endl;
	CH.Show();
//	CH.Search(48);
	//CH.Delete(6);
	//CH.Show();
	return 0;
}

