// Q 7].

#include<iostream>
using namespace std;

class Employee
{
	private:
		string name;
		int sal;
	
	public:
		void getdata()
		{
			cout<<"\nEnter Name   : ";
			getline(cin,name);
			cout<<"\nEnter Salary : ";
			cin>>sal;
			cin.ignore(1);
		}
		
		void showdata()
		{
			cout<<"\nName = "<<name<<"\t\tSalary = "<<sal;
		}
		
		static void Sort(Employee E[6])			//static member function (bcz datamembers are private)
		{
			int i,j,flag;
			Employee temp;
			//modified bubble sort
			for(i=1; i<6; i++)
			{
				flag=0;
				for(j=0; j<6-i; j++)
				{
					if(E[j].sal < E[j+1].sal)		//descending order
					{
						//swapping objects
						temp   = E[j];
						E[j]   = E[j+1];
						E[j+1] = temp;
						flag=1;
					}
				}
				if(flag==0)
				{
					break;
				}
			}
		}
};

int main()
{
	Employee Emp[6];
	int i;
	
	cout<<"\n\nEnter details of employees\n";
	for(i=0; i<6; i++)
	{
		Emp[i].getdata();
	}
	
	cout<<"\n\nEmployee List\n";
	for(i=0; i<6; i++)
	{
		Emp[i].showdata();
	}
	
	Employee::Sort(Emp);
	
	cout<<"\n\nFirst 3 employees having highest salary are\n";
	for(i=0; i<3; i++)
	{
		Emp[i].showdata();
	}
	
	return 0;
}
