// Bridges In Graph :-

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	private:
		int ** G;
		int n;
		int dir, wt, start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs yout graph directed ? 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted ? 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
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
			int u,v,w=1;
			if(wt == 0)
			{
				cout<<"\nKeep entering edges in the form (u,v) & enter -1 to stop\n";
				while(1)
				{
					cin>>u>>v;
					if(u==-1 || v==-1)
					{
						break;
					}
					insert(u-start, v-start, w);		//here w = 1
				}
			}
			else if(wt == 1)
			{
				cout<<"\nKeep entering edges in the form (u,v,w) & enter -1 to stop\n";
				while(1)
				{
					cin>>u>>v>>w;
					if(u==-1 || v==-1 || w==-1)
					{
						break;
					}
					insert(u-start, v-start, w);
				}
			}
		}
		
		void insert(int u,int v,int w)
		{
			G[u][v] = w;
			if(dir == 0)
			{
				G[v][u] = w;
			}
		}
		
		void showgraph()
		{
			cout<<"\n\nPrinting Graph Matrix\n";
			cout<<"    ";
			for(int i=0; i<n; i++)
			{
				cout<<setw(5)<<i+start;
			}
			cout<<"\n--------------------------------------------\n";
			for(int i=0; i<n; i++)
			{
				cout<<i+start<<" | ";
				for(int j=0; j<n; j++)
				{
					cout<<setw(5)<<G[i][j];
				}
				cout<<"\n";
			}
		}
		
		void findBridges()
		{
			int * vis = new int[n];
			int * tin = new int[n];
			int * low = new int[n];
			for(int i=0; i<n; i++)
			{
				vis[i] = 0;
				tin[i] = low[i] = -1;
			}
			int count=0;
			
			cout<<"\n\nBridges in graph are\n";
			for(int i=0; i<n; i++)
			{
				if(vis[i] == 0)
				{
					DFS(i, -1, vis, tin, low, count);
				}
			}
		}
		
		void DFS(int v,int parent,int * vis,int * tin,int * low,int& count)
		{
			vis[v] = 1;
			tin[v] = low[v] = count++;
			//find adjacent nodes of v
			for(int i=0; i<n; i++)
			{
				if(G[v][i] != 0)
				{
					if(i == parent)		//if adjacent node is parent, do nothing
					{
						continue;
					}
					if(vis[i] == 0)		//if adjacent node is not visited, call dfs for it
					{
						DFS(i, v, vis, tin, low, count);
						//update low[v] & check for bridge during backtracking
						low[v] = min(low[v], low[i]);
						if(low[i] > tin[v])				//bridge found
						{
							cout<<v+start<<" -> "<<i+start<<endl;
						}
					}
					else				//means, adjacent node is already visited, just update it's lowest time of insertion
					{
						low[v] = min(low[v], tin[i]);
					}
				}
			}
		}
		
		int min(int& x,int& y)
		{
			return x < y ? x : y;		//return min
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.findBridges();
	
	return 0;
}


