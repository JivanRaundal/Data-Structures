// Warshall's Algorithm -

#include<iostream>
using namespace std;

class Graph
{
	private:
		int ** G;
		int n;
		int dir, wt;
		int start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			G = new int*[n];
			int i,j;
			for(i=0; i<n; i++)
			{
				G[i] = new int[n];
			}
			//initialize graph to 0
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix();
		void showgraph();
		int** addMatrix(int ** M1,int ** M2);	//here for addition 2nd matrix is G matrix which is datamember & directly available
		int** mulMatrix(int ** M);			    //here for addition 2nd matrix is G matrix which is datamember & directly available
		void transitiveClosure();
};

void Graph::readgraph_matrix()
{
	cout<<"\n\nEnter "<<n<<"*"<<n<<" matrix\n";
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cin>>G[i][j];
		}
	}
}

void Graph::showgraph()
{
	cout<<"\n\nPrinting Graph Matrix\n";
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout<<" "<<G[i][j];
		}
		cout<<"\n";
	}
}

int** Graph::addMatrix(int ** M1,int ** M2)
{
	int i,j;
	int ** add = new int*[n];
	for(i=0; i<n; i++)
	{
		add[i] = new int[n];
		for(j=0; j<n; j++)
		{
			add[i][j] = 0;
		}
	}
	// add = TC + A;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			add[i][j] = M1[i][j] + M2[i][j];
			if(add[i][j] > 0)
			{
				add[i][j] = 1;
			}
		}
	}
	return add;
}

int** Graph::mulMatrix(int ** M)
{
	int i,j,k;
	int ** mul = new int*[n];
	for(i=0; i<n; i++)
	{
		mul[i] = new int[n];
		for(j=0; j<n; j++)
		{
			mul[i][j] = 0;
		}
	}
	//mul = M * G;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				mul[i][j] += M[i][k] * G[k][j];  
			}
		}
	}
	return mul;
}

void Graph::transitiveClosure()
{
	int ** A  = new int*[n];
	int ** TC = new int*[n];
	int i,j;
	for(i=0; i<n; i++)
	{
		TC[i] = new int[n];
		A[i]  = new int[n];
	}
	//now, copying graph matrix G in matrix A & intializing TC to 0
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			TC[i][j] = 0;
			A[i][j]  = G[i][j];
		}
	}
	
	//finding TC matrix
	for(i=0; i<n; i++)
	{
		TC = addMatrix(TC, A);
		A = mulMatrix(A);		
	}
	
	cout<<"\n\nPrinting Transitive Closure Matrix\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout<<"  "<<TC[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	Graph G;
	G.readgraph_matrix();
	G.showgraph();
	G.transitiveClosure();
	
	return 0;
}






