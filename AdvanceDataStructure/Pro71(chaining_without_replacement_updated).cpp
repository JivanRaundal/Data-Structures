// Linear Probing with chaining without replacement (updated code):-

#include<iostream>
#include<iomanip>
using namespace std;

class Hashing
{
	private:
		int ** HT;
		int capacity;
		int size;			//to check if hashtable is full or not
	public:
		Hashing()
		{
			size = 0;			//initially size is zero
			cout<<"\nEnter size of hash table : ";
			cin>>capacity;
			HT = new int*[capacity];
			for(int i=0; i<capacity; i++)
			{
				HT[i] = new int[2];			//BCZ we want HT[capacity][2] array only
				//initialize all hashtable keys & chains to -1
				HT[i][0] = HT[i][1] = -1;
			}
		}
		Hashing(int x)			//parameterized constructor 
		{
			capacity = x;
			HT = new int*[capacity];
			for(int i=0; i<capacity; i++)
			{
				HT[i] = new int[2];			//BCZ we want HT[capacity][2] array only
				//initialize all hashtable keys & chains to -1
				HT[i][0] = HT[i][1] = -1;
			}
		}
		
		int hashFun(int key)
		{
			return (key % capacity);
		}
		
		void readData()
		{
			int x;
			cout<<"\nKeep entering data or -1 to stop\n";
			while(1)
			{
				cin>>x;
				if(x == -1)
				{
					break;
				}
				insertKey(x);
			}
		}
		
		void insertKey(int key)
		{
			if(size == capacity)
			{
				cout<<"HashTable if Full\n";
				return;
			}
			int bno = hashFun(key);
			int ind = bno;
			//linear probing to search empty location for key
			while(HT[ind][0] != -1)
			{
				//check for duplication of key
				if(HT[ind][0] == key)
				{
					cout<<"duplicate key\n";
					return;
				}
				ind = (ind + 1) % capacity;
			}
			//here, we get empty location at index ind
			HT[ind][0] = key;
			size = size + 1;				//whenever key is added size of table is incremented
			//if key inserted at index is first key of it's home location, then (ind==bno) no need to maintain chain
			if(ind == bno)
				return;
			// means (ind != bno), So need to maintain chain here
			if(hashFun(HT[ind][0]) == hashFun(HT[bno][0]))		//i.e. new key and its home location key maps to same location
			{
				//need to only maintain chain
				while(HT[bno][1] != -1)
				{
					bno = HT[bno][1];			//follow chain & update the chain for recently added key
				}
				HT[bno][1] = ind;
			}
			else if(hashFun(HT[ind][0]) != hashFun(HT[bno][0]))		//misplaced key
			{
				//find location from where the series for misplaced elements with same home location is starting
				//and maintain the chain for misplaced element
				while(hashFun(HT[ind][0]) != hashFun(HT[bno][0]))
				{
					bno = (bno + 1) % capacity;
				}
				//NOTE:- if(ind==bno) it is first element in series, so no need to maintain chain
				if(ind != bno)
				{
					while(HT[bno][1] != -1)
					{
						bno = HT[bno][1];
					}
					HT[bno][1] = ind;
				}
			}
		}
		
		void showTable()
		{
			cout<<"\n\nHash Table\n\n";
			cout<<"Capacity = "<<capacity<<"\tSize = "<<size;
			cout<<"\n\nind  key  "<<setw(6)<<"chain\n";
			cout<<"---------------\n";
			for(int i=0; i<capacity; i++)
			{
				if(HT[i][0] != -1)
				{
					cout<<i<<setw(6)<<HT[i][0]<<setw(6)<<HT[i][1]<<endl;
				}
			}
		}
		
		int searchKey(int key)
		{
			int bno = hashFun(key);
			if(hashFun(key) != hashFun(HT[bno][0]))
			{
				while(hashFun(key) != hashFun(HT[bno][0]))
				{
					bno = (bno + 1) % capacity;
					if(bno == hashFun(key))
					{
						return 0;			//data not found
					}
				}
			}
			while(bno != -1)
			{
				if(HT[bno][0] == key)
				{
					return 1;			//data found
				}
				bno = HT[bno][1];		//follow chain
			}
			return 0;				//key not found
		}
		
		void deleteKey(int key)
		{
			int bno = hashFun(key);
			if(hashFun(key) != hashFun(HT[bno][0]))
			{
				while(hashFun(key) != hashFun(HT[bno][0]))
				{
					bno = (bno + 1) % capacity;
					if(bno == hashFun(key))
					{
						cout<<"\n"<<key<<" not found, cannot delete";
						return;
					}
				}
			}
			int prev = -1;
			while(bno != -1)
			{
				if(HT[bno][0] == key)
				{
					break;
				}
				prev = bno;
				bno = HT[bno][1];		//follow chain
			}
			if(bno == -1)			//data not found
			{
				cout<<"\n"<<key<<" not found, cannot delete";
				return;
			}
			//data to be deleted found, delete it and update the chain
			if(prev == -1)		//means, it is the first element in it's series
			{
				HT[bno][0] = HT[bno][1] = -1;
			}
			else
			{
				//delete that data & maintain chain for its series
				HT[prev][1] = HT[bno][1];
				HT[bno][0] = HT[bno][1] = -1;
			}
			size = size - 1;			//decrease the size of table after deletion
		}
};

int main()
{
	//Hashing H(10);
	Hashing H;
	H.readData();
	H.showTable();
	
	if(H.searchKey(33))
		cout<<"\nPresent";
	else
		cout<<"\nNot Present";
	if(H.searchKey(11))
		cout<<"\nPresent";
	else
		cout<<"\nNot Present";
	if(H.searchKey(99))					
		cout<<"\nPresent";
	else
		cout<<"\nNot Present";
	
	H.deleteKey(33);
	H.showTable();
	H.deleteKey(11);
	H.showTable();
	
	return 0;
}
