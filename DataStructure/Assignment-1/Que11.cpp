// Q 11].

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
		Number(int x,int y)
		{
			this->x = x;
			this->y = y;
		}
		void show()
		{
			cout<<"\nx = "<<x<<"\ty = "<<y;
		}
};

void copy(Number T1, Number & T2)
{
	T2.x = T1.x;
	T2.y = T1.y;
}

int main()
{
	Number obj(4,6);
	Number var;
	copy(obj,var);	//copies obj into var
	var.show();
	return 0;
}
