//	SLL

#include<iostream>
using namespace std;

class SLL;	//forward declaration
class Student
{
	private:
		int ind;
		char name[30];
		int roll;
		int age;
		Student * next;
	
	public:
		Student()
		{
			next = NULL;
			cout<<"\nEnter index no : ";
			cin>>ind;
			cin.ignore(1);
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Roll No : ";
			cin>>roll;
			cout<<"\nEnter Age : ";
			cin>>age;
		}
		
		friend class SLL;
};

class SLL
{
	private:
		Student * head;
	
	public:
		SLL()
		{
			head = NULL;
		}
		
		void create();
		void show();
		int count();
		int search(int x);
		void addatbeg(Student * T);
		void addatend(Student * T);
		void addbypos(int pos,Student * T);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
};

void SLL::create()
{
	Student * p = NULL;
	int n,i;
	cout<<"\nHow Many Students? ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid number";
		return;
	}
	
	cout<<"\nEnter data of first student ";
	head = new Student();
	p = head;
	
	for(i=1; i<=n-1; i++)
	{
		cout<<"\nEnter data for next student ";
		p->next = new Student();
		p = p->next;
	}
}

void SLL::show()
{
	Student * p = head;
	cout<<"\nSR NO.\tNAME\t\t\tROLL NO.\tAGE\n";
	while(p != NULL)
	{
		cout<<p->ind<<"\t"<<p->name<<"\t\t"<<p->roll<<"\t\t"<<p->age<<endl;;
		p = p->next;
	}
}

int SLL::count()
{
	Student * p = head;
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int SLL::search(int x)
{
	Student * p = head;
	while(p != NULL)
	{
		if(p->roll == x)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

void SLL::addatbeg(Student * T)
{
	Student * p = T;
	p->next = head;
	head = p;
}

void SLL::addatend(Student * T)
{
	if(head == NULL)	//i.e. if list is empty
	{
		head = T;
	}
	else
	{
		Student * p = head;
		while(p->next != NULL)	//will stop at last node & not crossover last node
		{
			p = p->next;
		}
		p->next = T;
	}
}

void SLL::addbypos(int pos,Student * T)
{
	int n;
	n = count();
	//check if position is valid or not
	if(pos < 1 || pos > n+1)
	{
		cout<<"\nInvalid Position";
		return;	
	}
	cout<<"\nValid Position";
	
	if(pos == 1)
	{
		addatbeg(T);
	}
	else
	{
		Student * p = head;
		Student * temp = NULL;
		
		for(int i=1; i<(pos-1); i++)	//will stop at (pos-1) node
		{
			p = p->next;
		}
		
		temp = T;
		temp->next = p->next;
		p->next = temp;
		
		//Now to update index (SR.NO.) numbers after adding in middle data
		if(pos != n+1)
		{
			while(temp != NULL)
			{
				temp = temp->next;
				if(temp != NULL)
				{
					temp->ind += 1;
				}
			}
		}
	}
}

void SLL::delatbeg()
{
	if(head == NULL)	//list is empty
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//list contains only 1 node
	{
		delete head;
		head = NULL;
	}
	else			//list contains more than 1 node
	{
		Student * p;
		p = head;
		head = head->next;
		delete p;
	}
	cout<<"\nStudent removed successfully";
}

void SLL::delatend()
{
	if(head == NULL)
	{
		cout<<"\nCan't delete...List is empty";
		return;
	}
	
	if(head->next == NULL)		//list contains single node
	{
		delete head;
		head = NULL;
	}
	else		//list contains multiple nodes
	{
		Student * p = head;
		Student * q = NULL;
		while(p->next != NULL)		//p will point to last node i.e. at (n)th node
		{
			q = p;					//q will point to last 2nd node. i.e. (n-1)th node (previous node of p)
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}
}

void SLL::delbypos(int pos)
{
	int n;
	n = count();
	//check position is valid or not
	if(pos < 1 || pos > n)
	{
		cout<<"\nInvalid position";
		return;
	}
	cout<<"\nValid position";
	if(pos == 1)
	{
		delatbeg();
	}
	else
	{
		Student * p = head;
		Student * q = NULL;
		for(int i=1; i<(pos-1); i++)
		{
			p = p->next;	//p will refer to the previous node i.e. node at (pos-1)th location
		}
		q = p->next;		//q will refer to node which is to be deleted i.e. node at location (pos)th
		p->next = q->next;
		delete q;
	}
}

int main()
{
	SLL obj;
	Student * S;
	int pos;
	
	obj.create();
	
	cout<<"\nSTUDENT'S LIST :";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	/*int x;
	cout<<"\nEnter Roll No of student to be searched : ";
	cin>>x;
	if(obj.search(x))
	{
		cout<<"\nStudent found.";
	}
	else
	{
		cout<<"\nStudent not found.";
	}
	
	cout<<"\n\nEnter details of student to add at beginning";
	S = new Student();
	obj.addatbeg(S);

	cout<<"\nSTUDENT'S LIST :";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	cout<<"\n\nEnter details of student to add at end";
	S = new Student();
	obj.addatend(S);

	cout<<"\nSTUDENT'S LIST :";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	cout<<"\nEnter postion and data : ";
	cin>>pos;
	S = new Student();
	obj.addbypos(pos,S);
	
	cout<<"\nSTUDENT'S LIST : ";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	obj.delatbeg();			//delatbeg()
	
	cout<<"\nSTUDENT'S LIST : ";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	obj.delatend();			//delatend()
	
	cout<<"\nSTUDENT'S LIST : ";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();*/
	
	cout<<"\nEnter position of student to be delete/remove : ";
	cin>>pos;
	obj.delbypos(pos);
	
	cout<<"\nSTUDENT'S LIST : ";
	obj.show();
	
	cout<<"\n\nTotal Student's = "<<obj.count();
	
	return 0;
}
