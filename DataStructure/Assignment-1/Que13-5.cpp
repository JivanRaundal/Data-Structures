// Q 13]. diagram-4)

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		//char name[30];
		string name;
		int age;
		Student * next;
		
		Student()
		{
			name = " ";
			age = 0;
			next = NULL;
		}
		Student(string _name,int x)
		{
			name = _name;
			age = x;
			next = NULL;
		}
};

int main()
{
	Student *p,*q,*r;
	
	p = new Student("Jivan Raundal", 20);
	q = new Student("Ashwin Bettawar", 21);
	r = new Student("Prasad Chemate", 19);
	
	p->next = q;
	q->next = r;
	
	cout<<"\nName = "<<p->name<<"\t\tAge = "<<p->age;
	cout<<"\nName = "<<p->next->name<<"\t\tAge = "<<p->next->age;
	cout<<"\nName = "<<p->next->next->name<<"\t\tAge = "<<p->next->next->age;
	
	delete p;
	delete q;
	delete r;
	return 0;
}
