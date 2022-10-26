// Q 3].

#include<iostream>
using namespace std;

class Employee
{
	public:
		char * name;
		int * age;
		
		Employee()	//constructor
		{
			name = new char[20];
			age  = new int();
			
			cout<<"\nEnter Name : ";
			cin.getline(name,18,'\n');
			cout<<"\nEnter Age : ";
			cin>>*age;	
		}
		~Employee()	//destructor
		{
			delete[] name;
			delete age;
			cout<<"\n-";	// to show that destructor is called
		}
		void show()
		{
			cout<<"\nName = "<<name<<"\t\tAge = "<<*age;
		}
};

int main()
{
	Employee * E;
	E = new Employee();
	E->show();
	delete E;
	return 0;
}
