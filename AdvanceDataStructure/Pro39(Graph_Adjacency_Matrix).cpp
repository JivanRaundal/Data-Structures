// Graph - Adjacency Matrix

#include<iostream>
#define MAX 20
using namespace std;

class Stack
{
	private:
		int data[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}
		int full()
		{
			if(top == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(top == -1)
				return 1;
			return 0;
		}
		void push(int x)
		{
			if(!full())
			{
				top++;
				data[top] = x;
			}
			else
			{
				cout<<"\nStack is full";
			}
		}
		int pop()
		{
			if(!empty())
			{
				int x;
				x = data[top];
				top--;
				return x;
			}
			else
			{
				cout<<"\nStack is empty";
				return -1;
			}
		}
};

class Queue
{
	private:
		int data[MAX];
		int front, rear;
	public:
		Queue()
		{
			front = rear = -1;
		}
		int full()
		{
			if(rear == MAX-1)
				return 1;
			return 0;
		}
		int empty()
		{
			if(front == -1)
				return 1;
			return 0;
		}
		void enqueue(int x)
		{
			if(!full())
			{
				if(front == -1)
				{
					front++;
				}
				rear++;
				data[rear] = x;
			}
			else
			{
				cout<<"\nQueue is full";
			}
		}
		int dequeue()
		{
			int x = -1;
			if(!empty())
			{
				x = data[front];
				if(front == rear)
				{
					front = rear = -1;
				}
				else
				{
					front++;
				}
				return x;
			}
			else
			{
				cout<<"\nQueue is empty";
				return -1;
			}
		}
};

class Graph
{
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
			cout<<"\nIs your graph directed or not? press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted or not? press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			G = new int*[n];
			int i;
			for(i=0; i<n; i++)
			{
				G[i] = new int[n];
			}
			//initializing graph martix to 0
			int j;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix();
		void showgraph();
		void degree();
		void outdegree();
		void indegree();
		void readgraph_edges();
		void insert(int u,int v,int w=1);
		void traversal();
		void DFS_rec(int * visited,int v);
		void DFS_nonrec(int * visited,int v);
		void BFS(int * visited,int v);
		void isConnectedGraph();
		void totalComponents();		//will give total number of components in graph	
};

void Graph::readgraph_matrix()
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

void Graph::showgraph()
{
	cout<<"\n\nPrinting Graph\n";
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

void Graph::degree()
{
	if(dir == 0)			//undirected graph
	{
		cout<<"\n\nDegree of each vertex in undirected graph\n";
		outdegree();
	}
	else if(dir == 1)		//directed graph
	{
		cout<<"\n\nIndegree of directed graph\n";
		indegree();
		cout<<"\n\nOutdegree of directed graph\n";
		outdegree();
	}
}

void Graph::outdegree()
{
	int i,j,count=0;
	for(i=0; i<n; i++)
	{
		count = 0;
		for(j=0; j<n; j++)
		{
			if(G[i][j] != 0)		//count nonzero entries in row of vertex
			{
				count++;
			}
		}
		cout<<"Outdegree of vertex "<<i+start<<" = "<<count<<endl;
	}
}

void Graph::indegree()
{
	int i,j,count=0;
	for(i=0; i<n; i++)
	{
		count = 0;
		for(j=0; j<n; j++)
		{
			if(G[j][i] != 0)		//count nonzero entries in column of vertex
			{
				count++;
			}
		}
		cout<<"Indegree of vertex "<<i+start<<" = "<<count<<endl;
	}
}

void Graph::readgraph_edges()
{
	int u,v,w;
	if(wt == 0)		//non-weighted graph
	{
		cout<<"\n\nKeep entering graph egdes of the form (u,v)\n";
		while(1)
		{
			cin>>u>>v;
			if(u==-1 || v==-1)
			{
				return;
			}
			//insert(u,v);
			insert(u-start, v-start);		//if start vertex is other than 0
		}
	}
	else if(wt == 1)		//weighted graph
	{
		cout<<"\n\nKeep entering graph edges of the form (u,v,w)\n";
		while(1)
		{
			cin>>u>>v>>w;
			if(u==-1 || v==-1)
			{
				return;
			}
			//insert(u,v,w);
			insert(u-start, v-start, w);			//if start vertex is other than 0
		}
	}
}

void Graph::insert(int u,int v,int w)	//default argument for w=1 (in declaration)
{
	G[u][v] = w;
	if(dir == 0)		//if graph is undirected, then 2 entries for the graph
	{
		G[v][u] = w;
	}
}

void Graph::traversal()
{
	int * visited = new int[n];		//array of visited vertices
	//initilizing visited array to 0
	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nRecursive DFS traversal of graph\n";
	DFS_rec(visited, 0);		//0 means 1st vertex is passed as a parameter

	//initializing visited array to 0 again for nonrec DFS traversal
	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nNon-Recursive DFS traversal of graph\n";
	DFS_nonrec(visited, 0);
	
	//initialize visited array to 0 again for BFS traversal of graph
	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nBFS traversal of graph\n";
	BFS(visited, 0);		//0 is start vertex
}

void Graph::DFS_rec(int * visited,int v)
{
	visited[v] = 1;			//visite vertex 
	//cout<<"  "<<v;
	cout<<"  "<<v+start;	//if start vertes is other than 0
	//find unvisited adjacent vertices of v
	for(int i=0; i<n; i++)
	{
		if(G[v][i]!=0 && visited[i]==0)
		{
			DFS_rec(visited, i);
		}
	}
}

void Graph::DFS_nonrec(int * visited,int v)
{
	Stack S;
	S.push(v);
	while(!S.empty())
	{
		v = S.pop();
		if(visited[v] == 0)
		{
			visited[v] = 1;		//visit the vertex
			//cout<<"  "<<v;
			cout<<"  "<<v+start;			//if start vertes is other than 0
			//now, find unvisited adjecent vertex of v and push it on stack
			for(int i=0; i<n; i++)
			{
				if(G[v][i]!=0 && visited[i]==0)
				{
					S.push(i);
				}
			}
		}
	}
}

void Graph::BFS(int * visited,int v)		//v is start vertex
{
	Queue Q;
	visited[v] = 1;			//visit the start vertex first
	cout<<"  "<<v+start;
	Q.enqueue(v);
	
	while(!Q.empty())
	{
		v = Q.dequeue();
		//find unvisited adjacent vertices of v
		for(int i=0; i<n; i++)
		{
			if(G[v][i]!=0 && visited[i]==0)		//if unvisited adjacent vertex
			{
				visited[i] = 1;
				cout<<"  "<<i+start;
				Q.enqueue(i);
			}
		}
	}
}

void Graph::isConnectedGraph()		//checks if graph is connected or disconnected
{
	int * visited = new int[n];
	int i;
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	//do any rec/nonrec DFS traversal of tree & if there are any unvisited vertex in graph, then it is disconnected graph else
	//it is connected graph
	DFS_rec(visited, 0);
	//checking for unvisited vertices
	for(i=0; i<n; i++)
	{
		if(visited[i] == 0)
		{
			cout<<"\n\nDisconnected Graph";
			break;	
		}
	}
	if(i == n)
	{
		cout<<"\n\nConnected Graph";
	}
}

void Graph::totalComponents()
{
	int * visited = new int[n];
	int i;
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	//counting number of components in graph
	int count=0;
	for(i=0; i<n; i++)
	{
		if(visited[i] == 0)		//if vertex is not visited, do DFS traversal for that vertex
		{
			DFS_rec(visited, i);
			count++;	
		}
	}
	cout<<"\n\nTotal Components = "<<count;
}

int main()
{
	Graph G;
	//G.readgraph_matrix();
	G.readgraph_edges();
	G.showgraph();
	G.degree();
	G.traversal();
	//G.isConnectedGraph();
	//G.totalComponents();
	
	return 0;
}





