// Q 6].

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		int roll;
		char name[30];
		
		void getdata()
		{
			cout<<"\nEnter Name : ";
			cin.getline(name,28,'\n');
			cout<<"\nEnter Roll : ";
			cin>>roll;
			cin.ignore(1);
		}
		
		void showdata()
		{
			cout<<"\nName = "<<name<<"\t\tRoll = "<<roll;
		}
};

int main()
{
	Student S[6];
	int i,j;
	
	cout<<"\n\nEnter Student's details\n";
	for(i=0; i<6; i++)
	{
		S[i].getdata();
	}
	
	cout<<"\n\nStudent's List Before Sorting\n";
	for(i=0; i<6; i++)
	{
		S[i].showdata();
	}
	
	
	int ch;
	Student temp;
	do
	{
		cout<<"\n\n----------------------";
		cout<<"\n1. Sort by roll";
		cout<<"\n2. Sort by name";
		cout<<"\n3. Print list";
		cout<<"\n4. exit";
		cout<<"\n----------------------";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				//Sort by roll (Insertin Sort)
				for(i=1; i<6; i++)
				{
					temp = S[i];
					for(j=i-1; j>-1; j--)
					{
						if(S[j].roll > temp.roll)
						{
							S[j+1] = S[j];
						}
						else
						{
							break;
						}
					}
					S[j+1] = temp;
				}
				break;
				
			case 2:
				//sort by name (Insertion Sort)
				for(i=1; i<6; i++)
				{
					temp = S[i];
					for(j=i-1; j>-1; j--)
					{
						if(strcmp(S[j].name,temp.name) == 1)		//i.e. if(S[j].name > temp.name);
						{
							S[j+1] = S[j];
						}
						else
						{
							break;
						}
					}
					S[j+1] = temp;
				}
				break;
				
			case 3:
				cout<<"\n\nSorted Student's List\n";
				for(i=0; i<6; i++)
				{
					S[i].showdata();
				}
				break;
			
			case 4:
				exit(0);
				
			default:
				cout<<"\nInvaid Choice!!!";
		}
	}while(ch != 4);
	
	return 0;
}
