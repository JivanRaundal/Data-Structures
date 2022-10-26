// Open Hashing (no limits on memory) (array of linked list is used to implement open hashing)

#include<iostream>
using namespace std;

class Node
{
	public:
		int key;
		Node * next;
		Node()
		{
			key = 0;
			next = NULL;
		}
		Node(int x)
		{
			key = x;
			next = NULL;
		}
};

class OpenHashing
{
	private:
		Node ** hashTable;
		int size;				//size of has table
	public:
		OpenHashing()
		{
			cout<<"\nEnter the size of hash table : ";
			cin>>size;
			//creating hashtable (i.e. array of head pointers)
			hashTable = new Node*[size];
			for(int i=0; i<size; i++)
			{
				hashTable[i] = NULL;
			}
		}
		
		int hashFunction(int key)
		{
			return (key % size);			//hash function
		}
		
		void getData()
		{
			int bno=0, key=0;
			cout<<"\nKeep entering keys & enter -1 to stop\n";
			while(1)
			{
				cin>>key;
				if(key == -1)
				{
					return;
				}
				//HASH FUNCTION to find bucket no i.e. bno
				insertKey(key);
			}
		}
		
		void insertKey(int key)
		{
			int bno = hashFunction(key);
			if(hashTable[bno] == NULL)
			{
				hashTable[bno] = new Node(key);
			}
			else
			{
				Node *p = hashTable[bno];
				while(p->next != NULL)
				{
					if(p->key == key)
					{
						cout<<"duplicate data\n";
						return;
					}
					p = p->next;
				}
				if(p->key == key)			//for last node check duplicacy
				{
					cout<<"duplicate data\n";
					return;
				}
				p->next = new Node(key);
			}
		}
		
		void showTable()
		{
			cout<<"\n\nHash Table\n";
			Node * P = NULL;
			for(int i=0; i<size; i++)
			{
				cout<<"\n"<<i;
				P = hashTable[i];
				while(P != NULL)
				{
					cout<<" -> "<<P->key;
					P = P->next;
				}
			}
		}
		
		int searchKey(int key)
		{
			int bno = hashFunction(key);
			Node * P;
			P = hashTable[bno];
			while(P != NULL)
			{
				if(P->key == key)
				{
					return 1;		//FOUND
				}
				P = P->next;
			}
			return 0;				//NOT FOUND
		}
		
		void deleteKey(int key)
		{
			int bno = hashFunction(key);
			if(hashTable[bno] == NULL)
			{
				cout<<"cannot delete\n";
				return;
			}
			if(hashTable[bno]->key == key)		//if first element in list
			{
				Node * temp = hashTable[bno];
				hashTable[bno] = temp->next;
				delete temp;
				return;
			}
			Node * p = hashTable[bno];
			Node * q = p;
			while(p != NULL)
			{
				if(p->key == key)
				{
					q->next = p->next;
					delete p;
					return;
				}
				q = p;
				p = p->next;
			}
			cout<<"\n\nNot found\n";
		}
};

int main()
{
	OpenHashing obj;
	obj.getData();
	obj.showTable();
	
	int x;
	cout<<"\n\nEnter key to search : ";
	cin>>x;
	if(obj.searchKey(x))
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not Found";
	}
	
	obj.deleteKey(25);
	obj.showTable();
	obj.deleteKey(3);
	obj.showTable();
	obj.deleteKey(15);
	obj.showTable();
	obj.deleteKey(88);
	
	return 0;
}


