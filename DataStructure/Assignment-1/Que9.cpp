// Q 9].

#include<iostream>
using namespace std;

class Student
{
		char *name;
		int *age;
		
	public:
		Student()
		{
			name = new char[30];
			age = new int();
			
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>*age;
			cin.ignore(1);
		}
		~Student()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<*age;
			
			delete[] name;
			delete age;
		}
};

int main()
{
	Student st[5];
	return 0;
}
