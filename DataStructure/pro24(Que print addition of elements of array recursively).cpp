// Q. complete the code for given main() function

#include<iostream>
using namespace std;

int add(int *p, int i)
{
	if(i == -1)
	{
		return 0;
	}
	return *(p+i) + add(p,i-1);
}

int main()
{
	int num[] = {5,7,8,2};
	int sum;
	sum = add(num,3);	//here, 3 is the last index of array
	cout<<"\nSum = "<<sum;
	return 0;
}
