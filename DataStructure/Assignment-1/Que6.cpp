// Q 6].

#include<iostream>
using namespace std;

class Student
{
		char name[30];
		int age;
		
	public:
		Student()
		{
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			cin.ignore(1);
		}
		~Student()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<age;
		}
};

int main()
{
	Student st[5];
	return 0;
}
