// Reverse the words in string using stack

#include<bits/stdc++.h>
using namespace std;

void revWordString(string s)
{
	stack<string> st;
	string word = "";
	
	for(int i=0; i<s.length(); i++)
	{
		word="";
		while(s[i]!=' ' && i<s.length())
		{
			word = word + s[i];
			i++;
		}
		st.push(word);
	}
	
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}

int main()
{
	string str = "hello jivan, are you fine?";
	
	cout<<"\nOriginal String = "<<str;
	
	cout<<"\nAfter reversing words = ";
	
	revWordString(str);
	
	return 0;
}
