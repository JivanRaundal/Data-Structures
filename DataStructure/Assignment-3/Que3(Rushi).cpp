#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char* p;
	public:
		void Scan()
		{
			cout<<"\nenter string : ";
			p = new char[100];
			cin.getline(p,99);
		}
		void Copy(String &s2)
		{
			
			s2.p = new char[this->length()+1] ;//+1 is for \0 because it is not considered in  string length
			int i = 0;
			while(*(p+i)!='\0')
			{
				*((s2.p) +i) = *(p+i);
				i++;
			}
			*((s2.p) +i) = '\0';
		}
		String Concatenate(String &s2)
		{
			int i =0;
			char* New = new char[this->length()+s2.length()+1];
			while(*(p+i)!='\0')
			{
				*(New+i)=*(p+i);
				i++;
			}
			int j=0;
			while(*((s2.p)+j)!='\0')
			{
				*(New+i) = *((s2.p )+ j);
				i++;
				j++;
			}
			*(New+i)='\0';
			String temp;
			temp.p = New;
			return temp;;
		}
		int length()
		{
			int i=0;
			while(*(p+i)!='\0')
			{
				i++;
			}
			return i;
		}
		void show()
		{
			cout<<p;
			cout<<"\n";
		}
		int Isequal(String S)
		{
			int flag =1 ;
			int i = 0;
			while(*(p+i)!='\0')
			{
				if(*(p+i) != *((S.p)+i))
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(flag==0)
				cout<<"\nnot Same! ";
			if(flag==1)
			{
				if(*(p+i)=='\0' && *((S.p)+i)=='\0')
					cout<<"\nsame";
				else
					cout<<"\nnot same";
				
			}

		}
		void Reverse()
		{
			char* temp  = new char[this->length()+1];
			//strcpy(temp,p);
			//delete []p;
			int i = this->length()-1;
			int j =0;
			while(i!=-1)
			{
				*(temp+j) = *(p+i) ; 
				i--;
				j++;
			}
			*(temp+j)='\0';
			strcpy(p,temp);
			
		}
		int Frequency()
		{
			char ch;int i=0; int count=0;
			cout<<"\nenter character to find it's frequency: ";cin>>ch;
			while(*(p+i)!='\0')
			{
				if(*(p+i)==ch)
				{
					count++;
				}
				i++;
			}
			if(count==0)
			{
				cout<<"\ncharacter is not present";
			}
			else
				cout<<"\ncharacter is present "<<count<<" times";
				
		}
		int  Issubstring(char* s)
		{
			int l = strlen(s);
			int i=0,j,k;
			while(*(p+i+l-1)!='\0')
			{
				
				for(j=0;j<l;j++)
				{
					if(*(s+j) != *(p+i+j))
					{
						break;
					}
				}
				if(j==l)
				{
					return i;	
				}
				i++;		
			}
			return -1;	
			
		}
			
		void chardelete()
		{
			char ch;
			cout<<"\nenter character whose occurence you want to delete!";cin>>ch;
			int i  = 0;
			while(*(p+i)!='\0')
			{
				if(*(p+i)==ch)
				{
					
					int j = 0;
					while(*(p+i+j+1)!='\0')
					{
						*(p+i+j) = *(p+i+j+1);
						j++;
					}
					*(p+i+j)='\0';
				}
				i++;
			}
		}
		void Delete(int start, int length)
		{
			if(start>strlen(p)||length>strlen(p))
			{
				cout<<"\ncan not delete!";
				return;
			}
			
			int i =0;
			while(*(p+start+i)!='\0')
			{
				*(p+start+i) = *(p+start+length+i);
				i++;
			}
			*(p+start+i) = '\0';
			
		}
		void freq_word()
		{
			char* s = new char[20];
			cout<<"\nEnter word want to find frequency in string: ";cin.getline(s,19);
			int l = strlen(s);
			int i=0,j,count=0,flag=0;
			while(*(p+i+l-1)!='\0')
			{
				
				for(j=0;j<l;j++)
				{
					if(*(s+j) != *(p+i+j))
					{
						break;
					}
				}
				i++;
				if(j==l)
				{
					count++;
					flag=1;	
				}		
			}
			if(flag==1)
				cout<<"\nthe word "<<s<<" is presnet "<<count<<" times!";
			else
				cout<<"\nword is not present in the string!";
		}
		void replace_word()
		{
			char* temp = new char[100];
			cout<<"\nthe string is :";
			this->show();
			char Old[20];
			char New[20];
			int i=0,j=0,k=0;
			//int flag=1;
			int x;
			cout<<"\nEnter word which you want to replace from string: ";cin.getline(Old,19);
			cout<<"\nEnter a new word which you want to insert: ";cin.getline(New,19);
			x = this->Issubstring(Old);
			if(x==-1)
			{
				cout<<"\nWord is not present!";
				return;
			}
			while(*(p+i)!='\0')
			{
				if(x==i)
				{
					while(New[j]!='\0')
					{
						*(temp+k)=New[j];
						k++;
						j++;
					}
	
					j = 0;
					while(Old[j] != '\0')
					{
						i++;
						j++;
					}
				}
				
				*(temp+k)= *(p+i);
				i++;
				k++;	
			}
			*(temp+k)='\0';
			cout<<i<<" "<<k<<"\n";
			cout<<temp;
			//strcpy(p,temp);
		}
	
};

int main()
{
	//int ch;
	String s1,s2;
	/*String s3;
	while
	{
		cout<<"\n----------------MENU-------------------";
		cout<<"\n1.Enter string\n2.dislplay string.\n3.Copy to another.\n4.Concatenate strings\n5.check Equality.\n6.Reverse String."
		<<"\n7.check frequency of character\n8.check frequency of word\n9.delete a character\n10.delete by position and length\n11.replace string\n12.exit";
		cout<<"\n---------------------------------------";
		cout<<"\nENTER CHOICE: ";cin>>ch;
		switch(ch)
		{
			case 1:
				
		}**/
		
	s1.Scan();
	s1.show();
	/*s2.Scan();
	s2.show();
	s3.Scan();
	s1.Copy(s2);
	s2.show();
	s3 = s1.Concatenate(s2);
	s3.show();
	s1.Isequal(s2);
	s1.Isequal(s3);
	s1.Reverse();
	s1.show();
	s1.Frequency();
	char* s = new char[20];
	cout<<"\nEnter substring you want to check: ";cin.getline(s,19);
	int i=s1.Issubstring(s);
	if(i==-1)
		cout<<"\nnot present";
	else
		cout<<"\nsubstring "<<s<<" is present at "<<i<<"th index!";
	s1.chardelete();
	s1.show();
	s1.Delete(1,5);
	s1.show();
	s1.replace_substring();
	s1.show();*/
	//s1.freq_word();
	//8 }
	//s1.replace_word();
	//s1.show();
	s1.chardelete();
	s1.show();
	return 0;
}
