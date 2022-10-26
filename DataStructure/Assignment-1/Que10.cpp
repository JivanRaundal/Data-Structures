// Q 10].

#include<iostream>
using namespace std;

class Number
{
	public:
		int x,y;
		
		Number()	//default
		{
			x = 0;
			y = 0;
		}
		void copy(Number T)
		{
			x = T.x;
			y = T.y;
		}
		void set(int x,int y)
		{
			this->x = x;
			this->y = y;
		}
		void show()
		{
			cout<<"\nx = "<<x<<"\ty = "<<y;
		}
};

int main()
{
	Number obj,var;
	obj.set(3,5);
	var.copy(obj);
	// This copies obj in var
	var.show();
	return 0;
}
