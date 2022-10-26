// Q 4]. For class Student, create an array of 5 students and print them Using STACK.

#include<iostream>
# define MAX 10
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

class Stack
{
	private:
		Student data[MAX];
		int top;
	
	public:
		Stack()
		{
			top = -1;
		}
		
		int full();
		int empty();
		void push(Student S);
		Student pop();
};

int Stack::full()
{
	if(top == MAX-1)
	{
		return 1;
	}
	return 0;
}

int Stack::empty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}

void Stack::push(Student S)
{
	if(full())
	{
		cout<<"\nStack Full";
	}
	else
	{
		top++;
		data[top] = S;
	}
}

Student Stack::pop()
{
	Student S;
	if(empty())
	{
		cout<<"\nStack Empty";
		return S;		      //to satisy returntype
	}
	else
	{
		S = data[top];
		top--;
		return S;
	}
}

int main()
{
	Stack S;
	Student St;
	
	cout<<"\nEnter details of students :\n";
	for(int i=0; i<5; i++)
	{
		St.scan();
		S.push(St);
	}
	cout<<"\n\nStudent's details :\n";
	while(!S.empty())
	{
		St = S.pop();
		St.show();
	}
	return 0;
}
