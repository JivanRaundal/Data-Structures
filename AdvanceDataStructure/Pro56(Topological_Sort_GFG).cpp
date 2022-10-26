// Topological Ordering :- (Topological Sort)
// Note:- Graph should be directed & acyclic for topological sort.

#include<iostream>
#include"Stack.h"
using namespace std;

class Graph
{
	public:
		int ** G;
		int n;
		Graph()
		{
			cout<<"\nEnter number of vertices : ";
			cin>>n;
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
	
		void topological_ordering()
		{	
			//creating & initializing visited array
			int i;
			int * visited = new int[n];
			for(i=0; i<n; i++)
			{
				visited[i] = 0;
			}
			
			Stack<int> S;
			for(int i=0; i<n; i++)
			{
				if(visited[i] == 0)
				{
					topologicalSort(i, visited, S);
				}
			}
			
			cout<<"\n\nTopological Order\n";
			while(!S.empty())
			{
				cout<<"  "<<S.pop();
			}
		}
		
		void topologicalSort(int v,int * visited, Stack<int>& S)		//S is passed by referece
		{
			//mark the current node as visited
			visited[v] = 1;
			//recur for all vertices adjacent to this vertex
			for(int i=0; i<n; i++)			
			{
				//find unvisited adjacent vertex of v
				if(G[v][i] != 0 && visited[i] == 0)
				{
					topologicalSort(i, visited, S);
				}
			}
			//push current vertex on stack during backtracking process
			S.push(v);
		}
};


int main()
{
	
	Graph graph;
	graph.readgraph();
	graph.showgraph();	
	graph.topological_ordering();
		
	return 0;
}
