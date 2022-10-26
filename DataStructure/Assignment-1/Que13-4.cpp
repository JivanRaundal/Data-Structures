// Q 13]. diagram-4)

#include<iostream>
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		Student * next;
		
		void scan()
		{
			cout<<"\nEnter name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			cin.ignore(1);
		}
};

int main()
{
	Student S1,S2,S3;
	
	S1.scan();
	S2.scan();
	S3.scan();
	
	S1.next = &S2;
	S2.next = &S3;
	S3.next = NULL;
	
	cout<<"\nS1 : Name = "<<S1.name<<"\t\tAge = "<<S1.age;
	cout<<"\nS2 : Name = "<<S1.next->name<<"\t\tAge = "<<S1.next->age;
	cout<<"\nS3 : Name = "<<S1.next->next->name<<"\t\tAge = "<<S1.next->next->age;
	
	return 0;
}
