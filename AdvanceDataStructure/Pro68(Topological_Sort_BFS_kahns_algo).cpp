// Topological Sorting (Kahn's Algorithm) (BFS logic) :-

//NOTE:- for topological sorting graph must be directed & acyclic

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
		
		void topoSort()			//topological sort using BSF logic (Kahn's algorithm)
		{
			//create & initialize indegree array
			int * indegree = new int[n];
			for(int i=0; i<n; i++)
			{
				indegree[i] = 0;
				for(int j=0; j<n; j++)
				{
					if(G[j][i] != 0)		//indegree of i th vertex = columns elements in adj matrix
					{
						indegree[i]++;
					}
				}
			}
			// topo algo starts here
			cout<<"\n\nTopological Ordering Sequence";
			Queue<int> Q;
			//find vertices with indegree 0 & enqueue them in queue
			for(int i=0; i<n; i++)
			{
				if(indegree[i] == 0)
				{
					Q.enqueue(i);
				}
			}
			while(!Q.empty())
			{
				int v = Q.dequeue();		//dequeue vertex from queue
				cout<<"\nvisited = "<<v;	//visit it
				//find adj. vertices of v & decrease there indegree by 1 & enqueue them in queue if indegree becomes 0
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
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.topoSort();
	
	return 0;
}




