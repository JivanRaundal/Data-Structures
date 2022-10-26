// Q 12].

#include<iostream>
using namespace std;

class Number
{
	public:
		int x,y;
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

void copy(Number T, Number * ptr)
{
	ptr->x = T.x;
	ptr->y = T.y;
}

int main()
{
	Number obj,var;
	obj.set(5,6);
	copy(obj,&var);		//copies obj into var
	var.show();
	return 0; 
}
