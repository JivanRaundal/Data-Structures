// Random Access File :- (Binary File)
// NOTE:- Here, we will write objects in file not data
// =>  file_object.write((char*)(addr_of_obj), sizeof(obj));
// =>  file_object.read((char*)(addr_of_obj), sizeof(obj));

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
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
	fobj.open("myfile2.txt", ios::in | ios::out | ios::trunc);			//opened in read mode
	
	if(fobj.fail())
	{
		cout<<"\ncannot connect";
		exit(1);	
	}
		
	Student S;
	cout<<"\n\nEnter data of 3 students\n";
	for(int i=1; i<=3; i++)
	{
		S.getData();
		fobj.write((char*)&S, sizeof(S));
	}
	
	cout<<"\nData written in file";
	
	fobj.seekg(0, ios::beg);
	
	cout<<"\n\nReading data from file\n";
	for(int i=1; i<=3; i++) 	//while(fobj.eof()==0)
	{
		fobj.read((char*)&S, sizeof(S));
		S.showData();
	}
	
	cout<<"\n\nDetails of student 2\n";
	int n = 2;			//details of nth student
	fobj.seekg((n-1)*sizeof(S) ,ios::beg);
	fobj.read((char*)&S, sizeof(S));
	S.showData();

	return 0;
}

