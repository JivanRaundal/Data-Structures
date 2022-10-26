// Q 8]. JOB SCHEDULING CODE

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Job
{
	public:
		int job_no;
		int time;
		
		Job()
		{
			job_no = 0;
			time = 0;
		}
		void getjob(int job_no,int time)
		{
			this->job_no = job_no;
			this->time   = time;
		}
};

class Node
{
	public:
		Job data;		//composition
		Node * next; 
		
		Node()
		{
			//data.getjob();
			next = NULL;
		}
		Node(int job_no,int time)
		{
			data.getjob(job_no,time);
			next = NULL;
		}
};

class CLL
{
	private:
		Node *front, *rear;
	
	public:
		CLL()
		{
			front = rear = NULL;
		}
		
		void create_job();
		void show_job();
		int count_job();
		int search_job(int job_no_);
		void add_job(int job_no,int time);
		void execute_job();
		void delete_job(int pos);
		void delatbeg();
};

/*void Job::getjob(int job_no,int time)
{
	//cout<<"\nEnter Job No : ";
	//cin>>job_no;
	//cout<<"\nEnter No of days to complete Job : ";
	//cin>>time;
	this->job_no = job_no;
	this->time   = time;
} */

void CLL::create_job()
{
	if(front != NULL)
	{
		cout<<"\nJob's already created";
		return;
	}
	
	cout<<"\nCreating Job's";
	int n,i;
	int job_no,time;
	
	cout<<"\nHow many job's you want to create ? : ";
	cin>>n;
	if(n < 1)
	{
		cout<<"\nInvalid Number";
		return;
	}
	
	cout<<"\nEnter Job No & No of days to complete Job : ";
	cin>>job_no>>time;
	front = new Node(job_no,time);
	front->next = front;
	rear = front;
	
	for(i=1; i<=n-1; i++)
	{
		do	
		{
			cout<<"\nEnter Job No & No of days to complete Job : ";
			cin>>job_no>>time;
			if(this->search_job(job_no))
			{
				cout<<"\nThis Job already exists...plz enter different Job";
			}
		}while(this->search_job(job_no));
		
		rear->next = new Node(job_no,time);
		rear = rear->next;
		rear->next = front;
	}
	cout<<"\nJob's Created Successfully";
}

int CLL::search_job(int job_no_)
{
	if(front == NULL)
	{
		return 0;	//list empty
	}
	Node * p = front;
	do
	{
		if(p->data.job_no == job_no_)
		{
			return 1;
		}
		p = p->next;
	}while(p != front);
	return 0;
}

int CLL::count_job()
{
	if(front == NULL)
	{
		return 0;
	}
	Node * p = front;
	int i=0;
	do
	{
		i++;
		p = p->next;
	}while(p != front);
	return i;
}

void CLL::show_job()
{
	if(front == NULL)
	{
		cout<<"\nNo Job's remained";
		return;
	}
	cout<<"\nRemaining Job's are : ";
	Node * p = front;
	do
	{
		cout<<"\nJob No = "<<p->data.job_no<<"\tNo of days required to complete Job = "<<p->data.time;
		p = p->next;
	}while(p != front);
}

void CLL::add_job(int job_no,int time)
{
	if(front == NULL)
	{
		front = new Node(job_no,time);
		front->next = front;
		rear = front;
	}
	else
	{
		rear->next = new Node(job_no,time);
		rear = rear->next;
		rear->next = front;
	}
}

void CLL::execute_job()
{
	if(front == NULL)
	{
		cout<<"\nNo Job's available to execute";
	}
	
	cout<<"\n\nCompleted Job's sequence is :\n";
	Node * p = front;
	Node * q;
	while(p != NULL)
	{
		p->data.time--;
		//cout<<"\n\nPending Job's are : ";
		//show_job();
		if(p->data.time == 0)
		{
			//cout<<"\n\nCompleted Job is :\n";
			if(p == front)
			{
				cout<<"\nJob No = "<<p->data.job_no<<"\tNo of days required to complete Job = "<<p->data.time;
				delatbeg();
				p = rear;		//after deletion front p must refer to rear so that p = p->next => p = front
			}
			else
			{
				q = front;
				while(q->next != p)
				{
					q = q->next;
				}
				q->next = p->next;
				cout<<"\nJob No = "<<p->data.job_no<<"\tNo of days required to complete Job = "<<p->data.time;
				if(p == rear)
				{
					rear = q;
				}
				delete p;
				p = q;
			}
		}
		if(p != NULL)
		{
			p = p->next;
		} 
		//p = p->next;	
	}
}

void CLL::delatbeg()
{
	if(front == NULL)
	{
		cout<<"\nCan't delete";
		return;
	}
	if(front == rear)
	{
		delete front;
		front = rear = NULL;
	}
	else
	{
		Node * p = front;
		front = front->next;
		rear->next = front;
		delete p;
	}
}

int main()
{
	CLL L;
	int job_no,time;
	
	L.create_job();
	cout<<"\n";
	L.show_job();
	cout<<"\n\nTotal available Job's are = "<<L.count_job();
	do
	{
		cout<<"\n\nEnter Job No & No of days required to complete Job : ";
		cin>>job_no>>time;
		if(L.search_job(job_no))
		{
			cout<<"\nThis Job already exists...plz enter different Job";
		}
	}while(L.search_job(job_no));
	L.add_job(job_no,time);
	
	cout<<"\n\nTotal available Job's are = "<<L.count_job();
	cout<<"\n";
	L.show_job();
	
	L.execute_job();
	cout<<"\n";
	L.show_job();
	
	
	return 0;
}
