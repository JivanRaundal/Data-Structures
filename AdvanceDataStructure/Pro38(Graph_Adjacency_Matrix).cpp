// GRAPH :- Adjacency Matrix

#include<iostream>
using namespace std;

class Graph
{
		int** G;
		int n;			//no of vertices
		int dir;		// if dir==0 (undirected), if dir==1 (directed)
		int wt;			// if wt==0 (non-weighted), if wt==1 (weighted)
		int start;		//start vertex of graph

	public:
		Graph()
		{
			cout<<"\nEnter number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter starting vertex of graph : ";
			cin>>start;
			
			G = new int*[n];
			int i;
			for(i=0; i<n; i++)
			{
				G[i] = new int[n];
			}
			//initializing graph matrix G 
			int j;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix()
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
			cout<<"\n\nPrinting Graph\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<"  "<<G[i][j];
				}
				cout<<"\n";
			}
		}
		
		void degree()
		{
			if(dir == 0)			//undirected graph
			{
				outdegree();
			}
			else if(dir == 1)		//directed graph
			{
				indegree();
				outdegree();
			}
		}
		
		void outdegree()
		{
			int i,j,count=0;
			for(i=0; i<n; i++)
			{
				count=0;
				for(j=0; j<n; j++)
				{
					if(G[i][j] != 0)		//count nonzero entries in row of vertex
					{
						count++;
					}
				}
				cout<<"\nOutdegree of vertex "<<i+start<<" = "<<count;
			}
		}
		
		void indegree()
		{
			int i,j,count=0;
			for(i=0; i<n; i++)
			{
				count=0;
				for(j=0; j<n; j++)
				{
					if(G[j][i] != 0)
					{
						count++;
					}
				}
				cout<<"\nIndegree of vertex "<<i+start<<" = "<<count;
			}
		}
		
		void readgraph_edges()			//scan edges from user & create matrix
		{
			int u,v,w;
			if(wt == 0)			//non-weighted graph (u,v)
			{
				cout<<"\nKeep entering edges of the form(u,v)\n";
				while(1)
				{
					cin>>u>>v;
					if(u==-1 || v==-1)
					{
						return;
					}
					insert(u, v);
				}
			}
			else if(wt == 1)	//weighted graph (u,v,w)
			{
				cout<<"\nKeep entering edges of the form (u,v,w)\n";
				while(1)
				{
					cin>>u>>v>>w;
					if(u==-1 || v==-1)
					{
						return;
					}
					insert(u, v, w);
				}
			}
		}
		
		void insert(int u,int v,int w=1)		//w has default argument
		{
			G[u][v] = w;
			if(dir == 0)			//undirected graph
			{
				G[v][u] = w;
			}
		}
		
		void traversal()
		{
			cout<<"\n\nDFS traversal of Graph\n";
			int * visited = new int[n];
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
			}
			DFS_rec(visited, 0);
		}
		
		void DFS_rec(int * visited,int v)
		{
			visited[v] = 1;			//mark vertex as visited
			cout<<"\nvisited vertex = "<<v;
			for(int j=0; j<n; j++)
			{
				if(G[v][j]!=0 && visited[j]==0)
				{
					DFS_rec(visited, j);
				}
			}
		}
};

int main()
{
	Graph obj;
	//obj.readgraph_matrix();
	obj.readgraph_edges();
	obj.showgraph();
	cout<<"\n\nDegree of each vertex\n";
	obj.degree();
	obj.traversal();
	
	return 0;
}



