// Linear Probing with chaining without replacement :-

#include<iostream>
#include<iomanip>
using namespace std;

class Hashing
{
	private:
		int ** HT;
		int size;
	public:
		Hashing()
		{
			cout<<"\nEnter size of hash table : ";
			cin>>size;
			HT = new int*[size];
			for(int i=0; i<size; i++)
			{
				HT[i] = new int[2];			//BCZ we want HT[size][2] array only
				//initialize all hashtable keys & chains to -1
				HT[i][0] = HT[i][1] = -1;
			}
		}
		Hashing(int x)			//parameterized constructor 
		{
			size = x;
			HT = new int*[size];
			for(int i=0; i<size; i++)
			{
				HT[i] = new int[2];			//BCZ we want HT[size][2] array only
				//initialize all hashtable keys & chains to -1
				HT[i][0] = HT[i][1] = -1;
			}
		}
		
		int hashFun(int key)
		{
			return (key % size);
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
			int bno = hashFun(key);			//bucket number
			if(HT[bno][0]==-1 && HT[bno][1]==-1)		//home location is empty for key
			{
				HT[bno][0] = key;
				return;
			}
			//i.e. if(HT[bno][0] != -1)			//another key already present in home location
			int chain;
			if(hashFun(HT[bno][0]) == bno)		//if key in home location has valid remainder,then follow chain
			{
				chain = HT[bno][1];
				if(chain == -1)
					chain = bno;
				while(HT[chain][1] != -1)		
				{
					chain = HT[chain][1];			//follow chain
				}
				//perform linear probing
				int ind = (chain + 1) % size;
				while(ind != chain)
				{
					if(HT[ind][0]==-1 && HT[ind][1]==-1)
					{
						HT[ind][0] = key;
						HT[chain][1] = ind;			//update chain
						return;
					}
					ind = (ind + 1) % size;
				}
				if(ind == chain)
				{
					cout<<"Hash Table is Full\n";
					return;
				}
			}
			else if(hashFun(HT[bno][0]) != bno)		//for misplaced elements (without replacement we have to adjust them in table)
			{
				int flag = 0;
				int i = (bno + 1) % size;
				while(i != bno)
				{
					if(hashFun(HT[i][0]) == bno)
					{
						flag = 1;
						chain = HT[i][1];
						if(chain == -1)
							chain = i;		//will need further
						break;								//do not return here
					}
					i = (i + 1) % size;
				}
				//if (flag==0) first misplaced element of given bucket number
				if(flag == 0)
				{
					int ind = (bno + 1) % size;
					while(ind != bno)
					{
						if(HT[ind][0]==-1 && HT[ind][1]==-1)
						{
							HT[ind][0] = key;
							return;
						}
						ind = (ind + 1) % size;
					}
					if(ind == bno)
					{
						cout<<"Hash Table is Full\n";
						return;
					}
				}
				// if (flag==1)  more than 1 misplaced elements exist for given bucket no location
				if(flag == 1)
				{
					//NOTE:- chain is updated in while loop of i
					while(HT[chain][1] != -1)
					{
						chain = HT[chain][1];
					}
					int ind = (chain + 1) % size;
					while(ind != chain)
					{
						if(HT[ind][0]==-1 && HT[ind][1]==-1)
						{
							HT[ind][0] = key;
							HT[chain][1] = ind;
							return;
						}
						ind = (ind + 1) % size;
					}
					if(ind == chain)
					{
						cout<<"Hash Table is Full\n";
						return;
					}
				}
			}
		}
		
		void showTable()
		{
			cout<<"\n\nHash Table\n\n";
			cout<<"key  "<<setw(6)<<"chain\n";
			for(int i=0; i<size; i++)
			{
				cout<<HT[i][0]<<setw(6)<<HT[i][1]<<endl;
			}
		}
};

int main()
{
	Hashing H;
	H.readData();
	H.showTable();
	
	return 0;
}
