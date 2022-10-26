// Adjacency List :- (for non-weighted graph)

#include<iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

class Node
{
	public:
		int vertex;
		//int weight;		//try yourself for weight
		Node * next;
		Node()
		{
			vertex = -1;
			next = NULL;
		}
		Node(int v)
		{
			vertex = v;
			next = NULL;
		}
};

class Graph
{
	private:
		Node** G;		//pointer to array of pointers
		int n;			//no of vertices
		int dir, wt;
		int start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			G = new Node*[n];		//creating array of Node* pointers at runtime
			//initializing array of pointers to NULL
			for(int i=0; i<n; i++)
			{
				G[i] = NULL;	
			}
		}
		
		void readgraph_edges();			//reading grapn from user by edges
		void insert(int u,int v);
		void showgraph();
		void degree();
		void outdegree();
		void indegree();
		void traversal();
		void DFS_rec(int * visited,int v);
		void DFS_nonrec(int * visited,int v);
		void BFS(int * visited,int v);
};

void Graph::readgraph_edges()		//for non-weighted graph
{
	int u,v;
	cout<<"\n\nKeep entering edges if the form (u,v)\n";
	while(1)
	{
		cin>>u>>v;
		if(u==-1 || v==-1)
		{
			//break;
			return;
		}
		//insert(u, v);
		insert(u-start, v-start);		//if start vertex is other than 0
		//if graph is undirected, entry is repeated
		if(dir == 0)
		{
			//insert(v, u);
			insert(v-start, u-start);
		}
	}
}

void Graph::insert(int u,int v)
{
	Node * P;
	P = G[u];
	if(P == NULL)
	{
		G[u] = new Node(v);	
	}
	else
	{
		while(P->next != NULL)
		{
			P = P->next;
		}
		P->next = new Node(v);
	}
}

void Graph::showgraph()
{
	cout<<"\n\nPrinting Adjacency List\n";
	Node * P = NULL;
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<i+start;
		P = G[i];
		while(P != NULL)
		{
			cout<<" -> "<<(P->vertex)+start;
			P = P->next;
		}
	}
}

void Graph::degree()
{
	if(dir == 0)		//undirected graph
	{
		cout<<"\n\nDegree of Undirected Graph\n";
		outdegree();
	}
	else if(dir == 1)
	{
		cout<<"\n\nOutdegree of Directed Graph\n";
		outdegree();
		cout<<"\n\nIndegree of Directed Graph\n";
		indegree();
	}
}

void Graph::outdegree()
{
	Node * P = NULL;
	int i,count=0;
	for(i=0; i<n; i++)
	{
		count = 0;
		P = G[i];
		while(P != NULL)
		{
			count++;
			P = P->next;
		}
		cout<<"\n outdegree of "<<i+start<<" = "<<count;
	}
}

void Graph::indegree()
{
	Node * P = NULL;
	int i,j,count=0;
	for(i=0; i<n; i++)
	{
		count = 0;
		for(j=0; j<n; j++)
		{
			P = G[j];
			while(P != NULL)
			{
				if(P->vertex == i)
				{
					count++;
				}
				P = P->next;
			}
		}
		cout<<"\nindegree of "<<i+start<<" = "<<count;
	}
}

void Graph::traversal()
{
	int * visited = new int[n];
	int i;
	//initializing visited array to zero
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nRecursive DFS traversal of graph\n";
	DFS_rec(visited, 0);		//0 is the start vertex
	
	//initializing visited array to zero
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nNon-Recursive DFS traversal of graph\n";
	DFS_nonrec(visited, 0);		//0 is the start vertex

	//initializing visited array to zero
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	cout<<"\n\nBFS traversal of graph\n";
	BFS(visited, 0);		//0 is the start vertex
}

void Graph::DFS_rec(int * visited,int v)
{
	visited[v] = 1;
	cout<<"  "<<v+start;
	//find unvisited adjacent vertices of v & send them to DFS_rec()
	Node * P = G[v];
	while(P != NULL)
	{
		if(visited[P->vertex] == 0)			//if not visited
		{
			DFS_rec(visited, P->vertex);
		}
		P = P->next;
	}
}

void Graph::DFS_nonrec(int * visited,int v)
{
	Stack<int> S;
	S.push(v);		//push start vertex in stack
	while(!S.empty())
	{
		v = S.pop();
		if(visited[v] == 0)		//if not visited
		{
			visited[v] = 1;
			cout<<"  "<<v+start;
			//find unvisited adjacent vertices of v & push them on stack
			Node  * P = G[v];
			while(P != NULL)
			{
				if(visited[P->vertex] == 0)
				{
					S.push(P->vertex);
				}
				P = P->next;
			}
		}
	}
}

void Graph::BFS(int * visited,int v)
{
	Queue<int> Q;
	visited[v] = 1;
	cout<<"  "<<v+start;
	Q.enqueue(v);
	while(!Q.empty())
	{
		v = Q.dequeue();
		//find unvisited adjacent vertices of v, visit them & enqueue them 
		Node * P = G[v];
		while(P != NULL)
		{
			if(visited[P->vertex] == 0)		//if not visited
			{
				visited[P->vertex] = 1;
				cout<<"  "<<(P->vertex)+start;
				Q.enqueue(P->vertex);
			}
			P = P->next;
		}
	}
}

int main()
{
	Graph G;
	G.readgraph_edges();
	G.showgraph();
	G.degree();
	G.traversal();
	
	return 0;
}




