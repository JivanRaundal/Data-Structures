

#include<iostream>
#include<iomanip>
#include "Queue.h"
using namespace std;

class Graph
{
	public:
		int ** G;
		int n;
		int dir, wt, start;
		Graph()
		{
			cout<<"\nEnter number of vertices : ";
			cin>>n;
			cout<<"\nIs graph directed ? 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs graph weighted ? 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex : ";
			cin>>start;
			
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
			cout<<"\n\nEnter edges in (u,v) format\n";
			int u,v;
			while(1)
			{
				cin>>u>>v;
				if(u==-1 || v==-1)
				{
					break;
				}
				insert(u-start, v-start);
			}
		}
		
		void insert(int u,int v)
		{
			G[u][v] = 1;
			if(dir == 0)
			{
				G[v][u] = 1;
			}
		}
		
		void showgraph()
		{
			cout<<"\n\nPrinting Graph Matrix\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<setw(5)<<G[i][j];
				}
				cout<<"\n";
			}
		}
		
		bool checkBipartite()
		{
			int * color = new int[n];
			for(int i=0; i<n; i++)
			{
				color[i] = -1;
			}
			
			for(int i=0; i<n; i++)
			{
				if(color[i] == -1)
				{
					if(!bipartiteBFS(i, color))
						return false;
				}
			}
			return true;
		}
		
		bool bipartiteBFS(int src,int * color)
		{
			Queue<int> Q;
			color[src] = 0;			//OR 1
			Q.enqueue(src);
			while(!Q.empty())
			{
				int v = Q.dequeue();
				for(int i=0; i<n; i++)
				{
					if(G[v][i] != 0)
					{
						if(color[i] == -1)
						{
							color[i] = 1 - color[v];
							Q.enqueue(i);
						}
						else if(color[i] == color[v])
						{
							return false;
						}
					}
				}
			}
			return true;
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	if(G.checkBipartite())
		cout<<"\nGraph is Bipartite";
	else
		cout<<"\nGraph is not Bipartite";
	
	return 0;
}
