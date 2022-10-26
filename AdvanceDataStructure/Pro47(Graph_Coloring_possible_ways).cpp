// Graph Coloring Algorithm :- (greedy algorithm)
// RULE :- No two adjacent vertices can have same color.

#include<iostream>
using namespace std;

class Graph
{
	public:
		int ** G;
		int n;
		int dir, wt;
		int start;
	
		Graph()
		{
			cout<<"\nEnter total number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			int i,j;
			G = new int*[n];
			for(i=0; i<n; i++)
			{
				G[i] = new int[i];
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix()
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
		
		void showgraph()
		{
			cout<<"\n\nPrinting graph matrix\n";
			int i,j;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout<<"  "<<G[i][j];
				}
				cout<<"\n";
			}
		}
};

class GraphColor
{
	private:
		Graph graph;			//graph class object
		int * color;			//color array
		int M;					//total number of colors
	public:
		GraphColor()
		{
			//scanning graph matrix & printing graph matrix of object G
			graph.readgraph_matrix();
			graph.showgraph();
			//----------------------------------------
			cout<<"\nEnter total number of colors : ";
			cin>>M;
			//create & initialize color array to 0
			color = new int[graph.n];
			for(int i=0; i<graph.n; i++)
			{
				color[i] = 0;
			}
		}
		
		void graphcoloring()		///helper
		{
			cout<<"\n\nPrinting all possible ways to color graph using given number of colorr\n";
			colormygraph(0);			//0 is the start vertex
		}
		
		void colormygraph(int v)
		{
			if(v == graph.n)
			{
				//printing possible ways
				cout<<"\n(";
				for(int i=0; i<graph.n; i++)
				{
					cout<<" "<<color[i];
				}
				cout<<" )";
				//return from function
				return;
			}
			else
			{
				for(int c=1; c<=M; c++)		//loop through color numbers (M)
				{
					if(canicolor(v, c))		//if true
					{
						color[v] = c;			//color vertex v with color c
						colormygraph(v+1);		//color next vertex using recursion
						color[v] = 0;			//remove color of v during backtracking for next possibility
					}
				}
			}
		}
		
		bool canicolor(int v,int c)
		{
			for(int i=0; i<graph.n; i++)
			{
				//find if adjacent vertex of v has same color or not
				if(graph.G[v][i] != 0)			//i.e. i th vertex is adjacent vertex of v th vertex
				{
					if(color[i] == c)		//and if adjacent vertex has same color c then return false
					{
						return false;
					}
				}
			}
			return true;					//no any adjacent vertex of v has same color c
		}
};

int main()
{
	GraphColor GC;
	GC.graphcoloring();
	
	return 0;
}

