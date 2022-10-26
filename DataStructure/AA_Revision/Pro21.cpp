// Scan details of 5 students & print them using stack.

#include<iostream>
#define MAX 5
using namespace std;

class Student
{
	public:
		char * name;
		int age;
		
		void scan()
		{
			name = new char[20];
			cout<<"\nEnter Name : ";
			cin.getline(name,18,'\n');
			cout<<"\nEnter Age  : ";
			cin>>age;
			cin.ignore(1);
		}
		void show()
		{
			cout<<"\nName = "<<name<<"	Age = "<<age;
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
		int full()
		{
			if(top == MAX-1)
			{
				return 1;
			}
			return 0;
		}
		int empty()
		{
			if(top == -1)
			{
				return 1;
			}
			return 0;
		}
		void push(Student st)
		{
			if(full())
			{
				cout<<"\nStackOverflow";
			}
			else
			{
				top++;
				data[top] = st;
			}
		}
		Student pop()
		{
			Student st;
			if(empty())
			{
				cout<<"\nStackUnderflow";
				return st; 
			}
			else
			{
				st = data[top];
				top--;
				return st;
			}
		}
};

int main()
{
	Stack S;
	Student st;
	for(int i=1; i<=5; i++)
	{
		st.scan();
		S.push(st);
	}
	cout<<"\n\nPrinting Data\n";
	while(!S.empty())
	{
		st = S.pop();
		st.show();
	}
	return 0;
}
