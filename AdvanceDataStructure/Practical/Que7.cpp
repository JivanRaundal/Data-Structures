// Q.7] WAP to scan graph from user and perform DFS.

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
			cout<<"\nEnter number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed ? ";
			cin>>dir;
			cout<<"\nIs your graph weighted ? ";
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
		
		void graphTraversal()
		{
			int * visited = new int[n];
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
			}
			cout<<"\n\nDFS Traversal of Graph\n";
			for(int i=0; i<n; i++)			//for disconnected graph
			{
				if(visited[i] == 0)
				{
					DFS(i, visited);
				}
			}
		}
		
		void DFS(int v,int * visited)
		{
			visited[v] = 1;
			cout<<"visited = "<<v<<endl;
			for(int i=0; i<n; i++)
			{
				if(G[v][i]!=0 && visited[i]==0)
				{
					DFS(i, visited);
				}
			}
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.graphTraversal();
	
	return 0;
}

