//   checck if expression is well parenthesis or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[20];
	cout<<"\nEnter expression : ";
	cin.getline(str, 18,'\n');
	
	stack<char> st;
	int i=0;
	int flag=0;
	int count=0;
	while(str[i] != '\0')		//{()}[]
	{
		char expn = str[i];
		if(expn=='('||expn=='['||expn=='{')
		{
			st.push(expn);
		}
		else if(expn==')'||expn==']'||expn=='}')
		{
			char ch = st.top();
			st.pop();
			if(expn==')' && ch!='(' || expn==']' && ch!='[' || expn=='}' && ch!='{')
			{
				flag=1;
				break;
			}
			else
			{
				count++;
			}
		}
		i++;
	}
	if(flag==1 || !st.empty())			//i.e if flag is 1 and stack is not empty
	{
		cout<<"\nNot Balanced";
	}
	else if(flag==0)				//if flag is 0 and stack is empty
	{
		cout<<"\nBalanced";
	}
	cout<<"\ncount of pairs of balanced parenthesis = "<<count;
	
	return 0;
}
