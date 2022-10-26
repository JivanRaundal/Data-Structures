// Detect Cycle in Directed Graph using BFS (topological sort algo i.e. Kahn's Algo):-

#include<iostream>
#include<iomanip>
#include "Queue.h"
using namespace std;

class Graph
{
	private:
		int ** G;
		int n;
		int dir;
		int wt;
		int start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			//creating adjacency matrix
			G = new int*[n];
			for(int i=0; i<n; i++)
			{
				G[i] = new int[n];
				for(int j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph()
		{
			cout<<"\n\nEnter "<<n<<"*"<<n<<" matrix\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cin>>G[i][j];
				}
			}
		}
		
		void showgraph()
		{
			cout<<"\n\nPrinting graph matrix\n";
			cout<<"  ";
			for(int k=0; k<n; k++)
			{
				cout<<setw(5)<<k+start;
			}
			cout<<"\n-----------------------------------------\n";
			for(int i=0; i<n; i++)
			{
				cout<<i+start<<"|";
				for(int j=0; j<n; j++)
				{
					cout<<setw(5)<<G[i][j];
				}
				cout<<"\n";
			}	
		}
		
		bool checkCycle()		//using topoSort() to detect cycle in directed gaph
		{
			//create & initialize indegree array
			int * indegree = new int[n];
			for(int i=0; i<n; i++)
			{
				indegree[i] = 0;
				for(int j=0; j<n; j++)
				{
					if(G[j][i] != 0)
					{
						indegree[i]++;
					}
				}
			}
			
			Queue<int> Q;
			for(int i=0; i<n; i++)
			{
				if(indegree[i] == 0)
				{
					Q.enqueue(i);
				}
			}
			int count = 0;
			while(!Q.empty())
			{
				int v = Q.dequeue();
				count++;
				for(int i=0; i<n; i++)
				{
					if(G[v][i] != 0)
					{
						indegree[i]--;
						if(indegree[i] == 0)
						{
							Q.enqueue(i);
						}
					}
				}
			}
			if(count == n)		//if (count==n), means all vertices are visited in topological ordering, graph is not cyclic
				return false;
			return true;			//if (count!=n), means some vertices are not visited, due to cycle in graph
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	if(G.checkCycle())
	{
		cout<<"\n\nGraph contains cycle (cyclic)";
	}
	else
	{
		cout<<"\n\nGraph does not contain cycle (acyclic)";
	}
	
	return 0;
}




