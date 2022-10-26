// Detect Cycle in Directed Graph using DFS logic:-

//NOTE:- Directed Graph

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
		
		bool isCyclic()				//helper for checkCycle()
		{
			int * visited = new int[n];
			int * dfsvis = new int[n];		//we will require another array for directed graph, to keep track of recursion stack
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
				dfsvis[i]  = 0;
			}
			//call recursive checkCycle() function
			for(int i=0; i<n; i++)				//will work for disconnected graph also
			{
				if(visited[i] == 0)
				{
					if(checkCycle(i, visited, dfsvis))		
						return true;
				}
			}
			return false;		//cycle not found
		}
		
		bool checkCycle(int v,int * visited,int * dfsvis)			//DFS logic
		{
			visited[v] = 1;
			dfsvis[v]  = 1;
			//find adjacent vertices of v
			for(int i=0; i<n; i++)
			{
				if(G[v][i] != 0)
				{
					if(visited[i] == 0)		//if i is not visited
					{
						if(checkCycle(i, visited, dfsvis))
							return true;
					}
					else if(dfsvis[i] == 1)	//vertex i is already visited, check if it is present in recursion stack i.e. in dfsvis
					{
						return true;		//cycle found
					}
				}
			}
			dfsvis[v] = 0;				//remove vertex v from recursion stack during backtracking
			return false;				//cycle not found
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




