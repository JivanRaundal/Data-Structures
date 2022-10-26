// delete data from sequential file (Text File)

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
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
	fobj.open("myfile.txt", ios::in);			//opened in read mode
	fstream fvar;
	fvar.open("temp.txt", ios::out);			//opened in write mode
	
	if(fobj.fail() || fvar.fail())
	{
		cout<<"\ncannot connect";
		exit(1);	
	}
	
	Student S;
	char name[30];
	cout<<"\nEnter name of student you want to delete : ";
	cin.getline(name, 28);
	
	for(int i=1; i<=3; i++)			//OR while(fobj.eof()==0)
	{
		//read from fobj & write in fvar except the data to be deleted
		fobj.getline(S.name, 28);
		fobj>>S.age;
		//S.showData();
		fobj.ignore(1);
		
		if(strcmp(S.name, name) != 0)		//similarly you can update any data
		{
			fvar<<S.name<<"\n";
			fvar<<S.age<<"\n";
		}
	}
	
	fobj.clear();
	fvar.clear();
	//NOTE:- file should be closed before using rename() & remove() functions
	fvar.close(); 
	fobj.close();
	
	//now, rename temp.txt as myfile.txt & delere myfile.txt
	if(remove("myfile.txt") == 0)
	{
		cout<<"\nOld file deleted successfully";
	}
	if(rename("temp.txt", "myfile.txt") == 0)
	{
		cout<<"\nFile renamed successfully";
	}

	return 0;
}

