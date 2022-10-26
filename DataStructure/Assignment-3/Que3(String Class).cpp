// Q 3].

#include<iostream>
#include<stdlib.h>
using namespace std;

class String
{
	private:
		char * str;
		
	public:
		String()
		{
			str = new char[100];
		}
		~String()
		{
			delete[] str;
		}
		
		void scan()
		{
			cout<<"\nEnter String : ";
			cin.getline(str,98,'\n');
		}
		
		void show()
		{
			cout<<str;
		}
		
		int length()
		{
			int i=0;
			while(*(str+i) != '\0')
			{
				i++;
			}
			return i;
		}
		
		void copy(String S)
		{
			int i=0;
			while(*(S.str+i) != '\0')
			{
				*(str+i) = *(S.str+i);
				i++;
			}
			*(str+i) = '\0';
		}
		
		void concat(String S)
		{
			int i=0;
			while(*(str+i) != '\0')
			{
				i++;	
			}
			//OR i = this->length();
			
			int j=0;
			while(*(S.str+j) != '\0')
			{
				*(str+i) = *(S.str+j);
				i++;
				j++;
			}
			*(str+i) = '\0';
		}		
		
		int equal(String S)
		{
			if(this->length() != S.length())
			{
				return 0;	//Not equal -bcz length must be same if strings are equal
			}
			
			int i=0;
			while(*(str+i) != '\0' && *(S.str+i) != '\0')		//only one condition is also valid
			{
				if(*(str+i) != *(S.str+i))
				{
					return 0;	//Not equal
				}
				i++;
			}
			return 1;	//equal
		}
		
		String reverse()
		{
			String S;
			int i = (this->length() - 1);	//length() will work for calling object 
			int j = 0;
			while(i>=0)
			{
				*(S.str+j) = *(str+i);
				i--;
				j++;
			}
			*(S.str+j) = '\0';
			return S;
		}
		
		/*int chk_substring(String S)
		{
			int i,j,k;
			
			for(i=0; i < length(); i++)
			{
				if(*(str+i) == *(S.str+0))	//if first char of main string & substring is same chk for next char
				{
					k = i;
					for(j=0; j < S.length(); j++)
					{
						if(*(str+k) != *(S.str+j))
						{
							break;
						}
						k++;
					}
					if(j == S.length())
					{
						return 1;	//substring present
					}
				}
			}
			return 0;
		} */
		
		// OR function to check substring
		int chk_substring(String S)
		{
			int i,j;
			for(i=0; i<length(); i++)
			{
				for(j=0; j<S.length(); j++)
				{
					if(*(str+i+j) != *(S.str+j))	//Note - *(str+i+j)
					{
						break;
					}
				}
				if(j == S.length())
				{
					return 1;
				}
			}
			return 0;
		}
		
		void chardelete(char ch)
		{
			int i=0,j=0;
			while(*(str+i) != '\0')
			{
				if(*(str+i) == ch)		//if *(str+i) == ch, then j-- bcz we want to avoid the character at index i
				{
					j--;
				}
				else
				{
					*(str+j) = *(str+i);	//copy as it is if *(str+i) != ch
				}
				i++;
				j++;
			}
			*(str+j) = '\0';
		}
		
		void frequency_of_str()
		{
			int i=0;
			while(*(str+i) != '\0')
			{
				if(*(str+i) != ' ')		//to avoid space
				{
					int j=0;
					int count=0;
					int flag = 0;
					
					while(*(str+j) != '\0')
					{
						if(*(str+i) == *(str+j))
						{
							count++;
						}
						if(j<i && count>0)		// if j < i & count > 0, then the element is repeated & hence we set 
						{						// the flag=1 & break the loop
							flag = 1;
							break;
						}
						j++;
					}
					if(flag == 0)
					{
						cout<<"\nFrequency occurence of "<<*(str+i)<<" is : "<<count;
					}
				}
				i++;
			}
		}
		
		int frequency_of_char(char ch)
		{
			int i=0,count=0;
			while(*(str+i) != '\0')
			{
				if(*(str+i) == ch)
				{
					count++;
				}
				i++;
			}
			return count;
		}
		
		void replace_substr(String S1,String S2)
		{
			int i,j,k;
			int flag = 0;
			for(i=0; i<length(); i++)
			{
				for(j=0; j<S1.length(); j++)
				{
					if(*(str+i+j) != *(S1.str+j))	//Note - *(str+i+j)
					{
						break;
					}
				}
				if(j == S1.length())
				{
					flag = 1;
					cout<<"\nSubstring "<<S1.str<<" found at index "<<i;
					//-------------------Extra String temp to store string after substring to concatenate---
					//char temp_str[50];
					String temp;
					int x = S1.length();
					int ind = 0;
					while(*(str+i+x+ind) != '\0')
					{
						temp.str[ind] = *(str+i+x+ind);
						ind++;
					}
					temp.str[ind] = '\0';
					//----------To replace without change in remaining string----------
					for(k=0; k<S2.length(); k++)
					{
						*(str+i+k) = *(S2.str+k);
					}
					//-------------------------END-------------------------
					*(str+i+k) = '\0';
					//this->concat(temp);
					//------------Concatenation Logic------------
					i=0,j=0;
					while(*(str+i) != '\0')
					{
						i++;
					}
					while(temp.str[j] != '\0')
					{
						*(str+i) = temp.str[j];
						i++;
						j++;
					}
					*(str+i) = '\0';
					//-------------------------------------------
				}
			}
			if(flag == 0)
			{
				cout<<"\nSubstring Not Found";
			}
		}
		
		void Delete(int start,int len)
		{
			int i,j;
			i=j= start;
			while(*(str+i+len) != '\0')
			{
				*(str+j) = *(str+i+len);
				i++;
				j++;
			}
			
			*(str+j) = '\0';	//'\0' is must at end of string.
		}
		
		//friend void getline(istream & din, String & S);
		//friend ostream& operator<<(ostream & dout,String S)
};

int main()
{
	/*String S1,S2,S3;
	S1.scan();
	cout<<"\nS1 = ";
	S1.show();
	cout<<"\nLength of S1 = "<<S1.length(); */
	//S2.copy(S1);
	/*S2.scan();
	cout<<"\nS2 = ";
	S2.show();
	S3.scan();
	cout<<"\nS3 = ";
	S3.show();
	S3.concat(S1);
	cout<<"\nS3 = ";
	S3.show();
	if(S1.equal(S2))
	{
		cout<<"\nS1 & S2 are Same";
	}
	else
	{
		cout<<"\nNot Same";
	}
	
	String S4;
	S4 = S1.reverse();
	cout<<"\nS4 = ";
	S4.show(); */
	
	/*String S5;
	cout<<"\nEnter Substring to be check :\n";
	S5.scan();
	if(S1.chk_substring(S5))
	{
		cout<<"\nSubstring Present";
	}
	else
	{
		cout<<"\nSubstring Not Present";
	} */
	
	/*String S6;
	S1.chardelete('a');
	cout<<"\nString 1 = ";
	S1.show(); */
	
	//S1.frequency_of_str();
	//cout<<"\na occurs "<<S1.frequency_of_char('a')<<" times.";
	
	/*String S7,S8;
	cout<<"\nEnter substring to be replaced : ";
	S7.scan();
	cout<<"\nSub String S7 = ";
	S7.show();
	cout<<"\nEnter string by which substring is to be replaced : ";
	S8.scan();
	cout<<"\nString by which substring is to be replaced is = ";
	S8.show();
	S1.replace_substr(S7, S8);		//syntax- S.replace_sub_str(substring, string_by_which_substring_is_to_be_replace)
	cout<<"\nAfter Replacement S1 = ";
	S1.show(); */
	
	/*cout<<"\n\nAfter deletetion of substring of required length\n";
	S1.Delete(2,5);
	cout<<"\nS1 = ";
	S1.show(); */
	
	String S1,S2,S3;
	char c;
	int start,len,ch;
	
	do
	{
		cout<<"\n\n________________________MENUE________________________";
		cout<<"\n1.  length of string";
		cout<<"\n2.  copy string";
		cout<<"\n3.  concatenate two strings";
		cout<<"\n4.  check Substring";
		cout<<"\n5.  check equal or not";
		cout<<"\n6.  reverse string";
		cout<<"\n7.  frequency of particular char";
		cout<<"\n8.  frequency of all char in string";
		cout<<"\n9.  delete sub string by start & length";
		cout<<"\n10. delete all occurence of char from string";
		cout<<"\n11. replace to make an in-place replacement";
		cout<<"\n12. exit";
		cout<<"\n_____________________________________________________";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		cin.ignore(1);
		
		switch(ch)
		{
			case 1:
				S1.scan();
				cout<<"\nString = ";
				S1.show();
				cout<<"\nLength of string is = "<<S1.length();
				break;
				
			case 2:
				S1.scan();
				cout<<"\nOriginal String S1 = ";
				S1.show();
				S2.copy(S1);
				cout<<"\nCopied String S2   = ";
				S2.show();
				break;
				
			case 3:
				cout<<"\nEnter two strings to concatenate ";
				S1.scan();
				S2.scan();
				cout<<"\nBefore Concatenation";
				cout<<"\nString S1 = ";
				S1.show();
				cout<<"\nString S2 = ";
				S2.show();
				cout<<"\nAfter Concatenating String S2 in String S1";
				S1.concat(S2);		//concat
				cout<<"\nString S1 = ";
				S1.show();
				cout<<"\nString S2 = ";
				S2.show();
				break;
				
			case 4:
				cout<<"\nEnter original String";
				S1.scan();
				cout<<"\nEnter Substring to be checked";
				S2.scan();
				if(S1.chk_substring(S2))
				{
					cout<<"\nSubstring Present";
				}
				else
				{
					cout<<"\nSubstring Not present";
				}
				break;
				
			case 5:
				cout<<"\nEnter two strings";
				S1.scan();
				S2.scan();
				if(S1.equal(S2))
				{
					cout<<"\nStrings are Equal";
				}
				else
				{
					cout<<"\nStrings are Not Equal";
				}
				break;
				
			case 6:
				S1.scan();
				S2 = S1.reverse();		//reversal of S1 will be stored in S2
				cout<<"\nOriginal String = ";
				S1.show();
		 		cout<<"\nReverse string  = ";
		 		S2.show();
		 		break;
		 		
		 	case 7:
		 		S1.scan();
		 		cout<<"\nEnter character to check it's frequency of occurence : ";
		 		cin>>c;
		 		cout<<"\n'"<<c<<"' occurse "<<S1.frequency_of_char(c)<<" times in string.";
		 		break;
		 		
		 	case 8:
		 		S1.scan();
		 		cout<<"\nFrequency occurence of all character's in string :\n";
		 		S1.frequency_of_str();
		 		break;
		 		
		 	case 9:
		 		S1.scan();
		 		cout<<"\nBefore deletion String = ";
		 		S1.show();
		 		cout<<"\nEnter Start index & length of Substring to to be deleted : ";
		 		cin>>start>>len;
		 		S1.Delete(start,len);
		 		cout<<"\nAfter deletion string  = ";
		 		S1.show();
		 		break;
		 		
		 	case 10:
		 		S1.scan();
		 		cout<<"\nBefore deletion String = ";
		 		S1.show();
		 		cout<<"\nEnter Character to delete it's occurence in string : ";
		 		cin>>c;
		 		S1.chardelete(c);
		 		cout<<"\nAfter deletion String = ";
		 		S1.show();
		 		break;
		 		
		 	case 11:
		 		cout<<"\nEnter main string";
		 		S1.scan();
		 		cout<<"\nBefore Replacement String = ";
		 		S1.show();
				cout<<"\nEnter old substring to be replaced";
				S2.scan();
				cout<<"\nEnter new substring by which old substring is to be replaced";
				S3.scan();		 			
		 		S1.replace_substr(S2,S3);
		 		cout<<"\nAfter Replacement String  = ";
		 		S1.show();
		 		break;
		 		
		 	case 12:
		 		exit(0);
		 		
		 	default:
		 		cout<<"\nInvalid Choice...Plz try again!!!";
		}
	}while(ch != 12); 
	
	return 0;
}
