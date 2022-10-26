// Graph Coloring :-
// Possibility: check if we can color our graph using given number of colors (i.e. using M colors).

#include<iostream>
using namespace std;

class Graph
{
	public:
		int ** G;
		int n;
		Graph()
		{
			cout<<"\nEnter total number of vertices : ";
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
			cout<<"\n\nPrinting Graph Matrix\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
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
		Graph graph;
		int M;			//total number of colors
		int * color;	//color array
	public:
		GraphColor()
		{
			graph.readgraph();
			graph.showgraph();
			
			cout<<"\nEnter total number of colors : ";
			cin>>M;
			//creating & intializing colors array
			color = new int[graph.n];
			for(int i=0; i<graph.n; i++)
			{
				color[i] = 0;
			}
		}
		
		void graphcoloring()
		{
			if(colormygraph(0))		//NOTE:- colormygraph() will return true if graph is colored using M colors, else returns false
			{
				cout<<"\nYes, you can color graph with "<<M<<" colors.";
			}
			else
			{
				cout<<"\nNo, you cannot color graph with "<<M<<" colors.";
			}
		}
		
		bool canicolor(int v,int c)		//this method will tell that can we color vertex 'v' witb color 'c'
		{
			for(int i=0; i<graph.n; i++)
			{
				if(graph.G[v][i] != 0 && color[i] == c)		//if adjacent vertex of v has same color c, then return false
				{
					return false;
				}
			}
			return true;			//means vertex v has no any adjacent vertex with color c
		}
		
		bool colormygraph(int v)		//will return true if graph is colored using M colors
		{
			if(v == graph.n)
			{
				cout<<"\nGraph Colored";
				return true;
			}
			else
			{
				for(int c=1; c<=M; c++)
				{
					if(canicolor(v, c))
					{
						color[v] = c;
						return colormygraph(v+1);
					}
				}
				//means, we cannot color graph using M colors
				return false;
			}
		}
};

int main()
{
	GraphColor gc;
	gc.graphcoloring();
	
	return 0;
}
