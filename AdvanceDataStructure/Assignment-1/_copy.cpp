// Q.4] create command copy to copy one file into another file. (commandline argument)
// Command => copy source.txt target.txt

#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char * argv[])
{
	cout<<"\nNumber of arguments = "<<argc;
	
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	if(fin.fail() || fout.fail())
	{
		cout<<"\nNot able to connect with file";
		exit(10);		//return value other than 0 means unsuccessful termination
	}
	
	char str[100];
	while(fin.eof() == 0)
	{
		fin.getline(str, 98);
		fout<<str<<endl;
	}
	cout<<"\nFile Copied Successfully";
	//closing file connections
	fin.close();
	fout.close();
	
	return 0;
}


