// Implementing 'N' stacks in 1 array :- (imp)
//	Note => Plz refer to notebook notes for theory

#include<iostream>
#define MAX 20
using namespace std;

class Stack
{
		int data[MAX];
		int * top;
		int * bottom;
		
	public:
		Stack()							//constructor
		{
			int N,ne,i;					//N = No. of stacks, ne = No. of elements per stack
			cout<<"\nHow many Stacks? ";
			cin>>N;
			
			ne = MAX/N;					//ne = No. of elements per stack
			top    = new int[N+1];		//top array will store top of each stack
			bottom = new int[N+1];		//bottom array will store index of bottom/beginning elelemt of each stack
			
			//initializing top & bottom array
			for(i=0; i<=N; i++)				//OR i<N+1
			{
				top[i] = i * ne - 1;		//formula
				bottom[i] = top[i] + 1;		//OR bottom[i] = i * ne
			}
		}
		
		int full(int st_no)
		{
			int i = st_no;					//here, i is used just for readability
			if(top[i]+1 == bottom[i+1])		//Note the condition OR if(top[i] == bottom[i+1]-1)
			{
				return 1;
			}
			return 0;
		}
		
		int empty(int st_no)
		{
			if(top[st_no]+1 == bottom[st_no])	//Note the condition OF if(top[st_no] == bottom[st_no]-1)
			{
				return 1;
			}
			return 0;
		}
		
		void push(int st_no,int x)
		{
			if(!full(st_no))
			{
				top[st_no]++;
				data[top[st_no]] = x;
			}
			else
			{
				cout<<"\nStack Full";
			}
		}
		
		int pop(int st_no)
		{
			if(!empty(st_no))
			{
				int x;
				x = data[top[st_no]];
				top[st_no]--;
				return x;
			}
			else
			{
				cout<<"\nStack Empty";
				return -1;
			}
		}
		
		void Display_stack(int N)		//N = total number of stacks 
		{
			cout<<"\n\nDisplaying all stacks :\n";
			int i=0,j=0;
			while(i < N)
			{
				cout<<"\nStack "<<i<<" :\n";
				j = bottom[i];
				while(j <=top[i])
				{
					cout<<" "<<data[j];
					j++;
				}
				i++;
			}
		}
		
		void Display_stack_no(int st_no)	//will display stack of given no. only
		{
			int i;
			cout<<"\n\nDisplaying Stack "<<st_no<<" :\n";
			i = bottom[st_no];
			while(i <= top[st_no])
			{
				cout<<" "<<data[i];
				i++;
			}
		}
};

int main()
{
	Stack S;
	int st_no;
	int x;
	
	cout<<"\nEnter Stack No. & data : ";
	cin>>st_no>>x;
	S.push(st_no,x);
	
	S.push(0,23);
	S.push(1,10);
	S.push(2,20);
	S.push(1,30);
	S.push(3,-12);
	S.push(1,11);
	S.push(2,22);
	S.push(3,40);
	S.push(0,2);
	
	/*x = S.pop(0);
	cout<<"\n"<<x;
	x = S.pop(1);
	cout<<"\n"<<x;
	x = S.pop(2);
	cout<<"\n"<<x;
	x = S.pop(3);
	cout<<"\n"<<x;
	x = S.pop(1);
	cout<<"\n"<<x;
	x = S.pop(3);
	cout<<"\n"<<x; */
	
	S.Display_stack(4);				//parameter = total number of stacks 
	
	S.Display_stack_no(2);			//parameter = satck No. which you want to display
	
	cout<<"\n\nUnwinding Stack 0 :\n";
	while(!S.empty(0))
	{
		x = S.pop(0);
		cout<<" "<<x;	
	}
	
	cout<<"\n\nUnwinding Stack 1 :\n";
	while(!S.empty(1))
	{
		x = S.pop(1);
		cout<<" "<<x;	
	}
	cout<<"\n\nUnwinding Stack 2 :\n";
	while(!S.empty(2))
	{
		x = S.pop(2);
		cout<<" "<<x;	
	}
	cout<<"\n\nUnwinding Stack 3 :\n";
	while(!S.empty(3))
	{
		x = S.pop(3);
		cout<<" "<<x;	
	}
	
	S.Display_stack(4);
	
	return 0;
}
