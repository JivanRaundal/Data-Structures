// sequential file (Text File)

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Student
{
	public:
		char name[30];
		int age;
		void getData()
		{
			cout<<"\nEnter Name : ";
			cin.getline(name, 28);
			cout<<"Enter Age  : ";
			cin>>age;
			cin.ignore(1);
		}
		void showData()
		{
			cout<<"\nName = "<<name<<"\tAge = "<<age;
		}
};

int main()
{
	fstream fobj;
	fobj.open("myfile.txt", ios::in | ios::out | ios::trunc);
	if(fobj.fail())
	{
		cout<<"\ncannot connect";
		exit(1);	
	}
	
	Student S;
	cout<<"\nEnter data for 3 students\n";
	for(int i=1; i<=3; i++)
	{
		S.getData();
		fobj<<S.name<<"\n";
		fobj<<S.age<<"\n";
	}
	
	cout<<"\n\nData Written In File";
	
	fobj.seekg(0, ios::beg);
	cout<<"\n\nReading data from file\n";
	for(int i=1; i<=3; i++)			//OR while(fobj.eof()==0)
	{
		fobj.getline(S.name, 28);
		fobj>>S.age;
		fobj.ignore(1);
		S.showData();	
	}
	
	fobj.clear();
	fobj.close();
	
	return 0;
}
