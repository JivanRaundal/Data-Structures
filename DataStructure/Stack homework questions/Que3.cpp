// Q 3]. For class Student, create an array of 5 students and print them. Do not use stack.

#include<iostream>
using namespace std;

class Student
{
	private:
		char name[30];
		int age;
		
	public:
		Student()
		{
			//default const
		}
		void scan()
		{
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Age : ";
			cin>>age;
			cin.ignore(1);
		}
		void show()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<age;
		}
};

int main()
{
	Student St[5];	//array of objects
	int i;
	
	cout<<"\nEnter details of students :\n";
	for(i=0; i<5; i++)
	{
		St[i].scan();
	}
	cout<<"\n\nStudenta details :\n";
	for(i=0; i<5; i++)
	{
		St[i].show();
	}
	return 0;
}
