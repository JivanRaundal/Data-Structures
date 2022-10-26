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
		void warshalls_algo();
		
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

void Graph::warshalls_algo()
{
	//creating a transitive closure matrix & copying a graph matric in it
	int ** TC = new int*[n];
	for(int i=0; i<n; i++)
	{
		TC[i] = new int[n];	
	}
	//copying Graph matrix in TC
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			TC[i][j] = G[i][j];
		}
	}
	
	//warshall's algorith
	int i,j,k;
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(TC[i][j] == 0)		//if there is no path from i to j directly
				{
					//we will check if there is path from i to j via k & if path exists, then we will update TC matrix
					if(TC[i][k] != 0 && TC[k][j] != 0)
					{
						TC[i][j] = 1;
					}
				}
			}
		}
	}
	
	//printing TC matrix
	cout<<"\n\nPrinting Transitive Closure Matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<" "<<TC[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	Graph G;
	G.readgraph_matrix();
	G.showgraph();
	G.warshalls_algo();
	
	return 0;
}






