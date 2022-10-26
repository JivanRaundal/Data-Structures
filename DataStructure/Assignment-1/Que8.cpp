// Q 8].

#include<iostream>
using namespace std;

class Time
{
		int *hr,*min;
	public:
		~Time()
		{
			delete hr;
			delete min;
		}
		void scan()
		{
			hr  = new int();
			min = new int();
			
			cout<<"\nEnter Time : ";
			cin>>*hr>>*min;
		}
		void print()
		{
			cout<<"\nTime = "<<*hr<<" hr & "<<*min<<" min.";
		}
		void convert()
		{
			*hr = *hr + (*min)/60;
			*min = (*min)%60;
		}
		static void greater()
		{
			Time T1,T2;
			T1.scan();
			T1.convert();
			T1.print();
			T2.scan();
			T2.convert();
			T2.print();
						
			if(*T1.hr > *T2.hr)
			{
				cout<<"\nT1 is largest than T2";
			}
			else if(*T1.hr < *T2.hr)
			{
				cout<<"\nT2 is largest than T1";
			}
			else
			{
				if(*T1.min > *T2.min)
				{
					cout<<"\nT1 is largest than T2";
				}
				else if(*T1.min < *T2.min)
				{
					cout<<"\nT2 is largest than T1";
				}
				else
				{
					cout<<"\nBoth Times are same";
				}
			}
		}
};

int main()
{
	Time::greater();
	return 0;
}
