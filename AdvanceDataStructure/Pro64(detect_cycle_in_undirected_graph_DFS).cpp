// Detect Cycle in Undirected Graph using DFS logic :-

#include<iostream>
#include<iomanip>
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
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<setw(5)<<G[i][j];
				}
				cout<<"\n";
			}	
		}
		
		bool isCyclic()				//helper for checkCycle()
		{
			int * visited = new int[n];
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
			}
			//call recursive checkCycle() function
			for(int i=0; i<n; i++)				//will work for disconnected graph also
			{
				if(visited[i] == 0)
				{
					if(checkCycle(i, -1, visited))		//-1 is passed as parent for starting vertex
					{
						return true;
					}
				}
			}
			return false;		//cycle not found
		}
		
		bool checkCycle(int v,int parent,int * visited)		//DFS logic
		{
			visited[v] = 1;				//visit vertex v
			for(int i=0; i<n; i++)
			{
				if(G[v][i] != 0)		//find adjacent vertices of v
				{
					if(visited[i] == 0)		//if adj. vertex is not visited, call checkCycle() for it
					{
						if(checkCycle(i, v, visited))
						{
							return true;
						}
					}
					else if(i != parent)		//means, vertex i is already visited, check if it is not parent of v
					{
						return true;		//cycle found
					}
				} 
			}
			return false;			//cycle not found
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	if(G.isCyclic())
	{
		cout<<"\n\nGraph contains cycle (cyclic)";
	}
	else
	{
		cout<<"\n\nGraph does not contain cycle (acyclic)";
	}
	
	return 0;
}




