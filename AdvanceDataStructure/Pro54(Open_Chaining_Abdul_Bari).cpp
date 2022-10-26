#include <iostream>

using namespace std;

// Linked List node

class Node{

public:
	int data;
	Node* next;
};
// Hash Table
class HashTable{

public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	void showTable();
	~HashTable();
};

HashTable::HashTable() {
	HT = new Node* [4];
	for (int i=0; i<4; i++){
		HT[i] = NULL;
	}
}

int HashTable::hash(int key) {
	return key % 4;
}

void HashTable::Insert(int key) 
{
	int bno = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = NULL;
	// Case: No nodes in the linked list
	if (HT[bno] == NULL)
	{
		HT[bno] = t;
	}
	else if(HT[bno]->next == NULL)
	{
		// Case: insert position is first
		if(key > HT[bno]->data)
		{
			HT[bno]->next = t;
		}
		else if(key < HT[bno]->data)
		{
			t->next = HT[bno];
			HT[bno] = t;
		}
	} 
	else 
	{
		Node* p = HT[bno];
		Node *q=HT[bno];
		// Traverse to find insert position
		while (p != NULL && p->data < key){
			q = p;
			p = p->next;
		}
		t->next = q->next;
		q->next = t;
	}
}

int HashTable::Search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p){
		if (p->data == key){
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable() {
	for (int i=0; i<4; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

void HashTable::showTable()
{
		cout<<"\n\nHash Table\n";
		Node * P = NULL;
		for(int i=0; i<4; i++)
		{
			cout<<"\n"<<i;
			P = HT[i];
			while(P != NULL)
			{
			cout<<" -> "<<P->data;
			P = P->next;
		}
	}
}

int main() {
	int A[] = {25, 29, 15, 3, 8, 65, 70};		//NOTE:- code fails for this input, think different logic
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}
	
	H.showTable();
	
	int key = 29;
	int value = H.Search(key);
	cout<<"\n\nsuccessfull search\n";
	cout << "Key: " << key << ", Value: " << value << endl;
	cout<<"\n\nsuccessfull search\n";
	key = 25;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout<<"\nunsuccessfull search\n";
	key = 30;
	value = H.Search(key);
	cout << "key: " << key << ", Value: " << value << endl;

	return 0;
}
