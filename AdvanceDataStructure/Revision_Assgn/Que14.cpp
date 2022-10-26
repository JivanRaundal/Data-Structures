// Q.14] For class containing name, age & roll create a database of 5 students. Now, search student by roll no or by age.
//       give option for sorting also by name or age.

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	private:
		char name[30];
		int age;
		int roll;
	public:
		Student()
		{
			//scanning details in constructor
			cout<<"\nEnter Roll : ";
			cin>>roll;
			cin.ignore(1);
			cout<<"Enter Name : ";
			cin.getline(name,28,'\n');
			cout<<"Enter Age  : ";
			cin>>age;
		}
		Student(int a)
		{
			strcpy(name, "");
			roll = 0;
			age = 0;
		}
		void printdata()
		{
			cout<<"\n\nRoll = "<<roll;
			cout<<"\nName = "<<name;
			cout<<"\nAge  = "<<age;
		}
		//search student by age
		static void searchByAge(Student * S)
		{
			int age;
			cout<<"\n\nEnter age to be search : ";
			cin>>age;
			int f=0;
			for(int i=0; i<3; i++)
			{
				if(S[i].age == age)
				{
					f=1;
					cout<<"\nPresent";
					S[i].printdata();
					break;
				}
			}
			if(f == 0)
			{
				cout<<"\nNot Present";
			}
		}
		//search student by roll
		static void searchByRoll(Student * S)
		{
			int roll;
			cout<<"\n\nEnter Roll to be search : ";
			cin>>roll;
			int f=0;
			for(int i=0; i<3; i++)
			{
				if(S[i].roll == roll)
				{
					f=1;
					cout<<"\nPresent";
					S[i].printdata();
					break;
				}
			}
			if(f == 0)
			{
				cout<<"\nNot Present";
			}
		}
		//sorting by age
		static void sortByAge(Student * S)
		{
			Student temp(0);
			for(int i=0; i<3; i++)
			{
				for(int j=i+1; j<3; j++)
				{
					if(S[i].age > S[j].age)
					{
						//swapping objects
						temp = S[i];
						S[i] = S[j];
						S[j] = temp;
					}
				}
			}
		}
		//sorting by name
		static void sortByName(Student * S)
		{
			Student temp(0);
			for(int i=0; i<3; i++)
			{
				for(int j=i+1; j<3; j++)
				{
					if(strcmp(S[i].name, S[j].name) == 1)			// S1<S2 => -1, S1==S2 => 0, S1>S2 = 1
					{
						//swapping objects
						temp = S[i];
						S[i] = S[j];
						S[j] = temp;
					}
				}
			}
		}
};

int main()
{
	Student st[3];
	for(int i=0; i<3; i++)
	{
		st[i].printdata();
	}
	
	Student::searchByAge(st);
	Student::searchByRoll(st);
	
	cout<<"\n\nSorted by Age";
	Student::sortByAge(st);
	for(int i=0; i<3; i++)
	{
		st[i].printdata();
	}
	cout<<"\n\nSorted by Name";
	Student::sortByName(st);
	for(int i=0; i<3; i++)
	{
		st[i].printdata();
	}
	
	return 0;
}
