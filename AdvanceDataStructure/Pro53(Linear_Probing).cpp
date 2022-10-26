// Linear Probing :-

#include<iostream>
using namespace std;

class Hashing
{
	private:
		int * hashTable;
		int size;
	public:
		Hashing()
		{
			cout<<"\nEnter hashtable size : ";
			cin>>size;
			hashTable = new int[size];
			for(int i=0; i<size; i++)
			{
				hashTable[i] = -1;
			}
		}
		
		int hashfun(int key)
		{
			return (key % size);			//hashfunction
		}
		
		void readData()
		{
			int key;
			cout<<"\nKeep entering keys or -1 to stop\n";
			while(1)
			{
				cin>>key;
				if(key == -1)
				{
					return;
				}
				insertKey(key);
			}
		}
		
		void insertKey(int key)		//linear probing is used to probe key if collision occurs
		{
			int bno = hashfun(key);			//bno = bucket number
			if(hashTable[bno] == -1)		//means, bucket/slot is not occupied, insert key in it
			{
				hashTable[bno] = key;
			}
			else if(hashTable[bno] != -1)		//means, bucket/slot is occupied, collision occurs
			{
				//linear probing
				int i = bno;
				do
				{
					if(hashTable[i] == key)
					{
						cout<<"duplicate data\n";
						return;
					}
					if(hashTable[i] == -1)
					{
						hashTable[i] = key;
						break;
					}
					i = (i + 1) % size;				//we have to start from 0 if we reached to end i.e. size
				}while(i != bno);
				if(i == bno)
				{
					cout<<"\nHashTable is full, cannot add key in table.";
				}
			}
		}
		
		int showTable()
		{
			cout<<"\nPrinting Hash Table\n\n";
			cout<<"ind  "<<"keys\n";
			for(int i=0; i<size; i++)
			{
				cout<<i<<"    "<<hashTable[i]<<"\n";
			}
		}
		
		int searchKey(int key)
		{
			int bno = hashfun(key);
			if(hashTable[bno] == key)
			{
				return 1;							//found
			}	
			else
			{
				//linear probing
				int i = bno+1;
				while(i!=bno && hashTable[i]!=-1)    // OR while(i != bno && hashTable[i] != -1)   -optimized condition
				{
					if(hashTable[i] == key)
					{
						return 1;					//found
					}
					i = (i + 1) % size;				//we have to start from 0 if we reached to end i.e. size
				}
				return 0;							//Not found
			}
		}
};

int main()
{
	Hashing obj;
	obj.readData();
	obj.showTable();
	int x;
	cout<<"\nEnter key to search : ";
	cin>>x;
	if(obj.searchKey(x))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not found";
	}
	cout<<"\nEnter key to search : ";
	cin>>x;
	if(obj.searchKey(x))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not found";
	}
	
	return 0;
}
