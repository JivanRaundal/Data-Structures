// Adjacency List using Array of Vectors :-

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, e, start;
	cout<<"\nEnter number of vertices and edges : ";
	cin>>n>>e;
	cout<<"\nEnter start vertex : ";
	cin>>start;
	
	vector<int> adjlist[n];			//creating adjacency list using array of vectors
	
	int u,v;
	cout<<"\nEnter edges in (u,v) format\n";
	for(int i=0; i<e; i++)
	{
		cin>>u>>v;
		adjlist[u-start].push_back(v-start);
		adjlist[v-start].push_back(u-start);
	}
	
	cout<<"\n\nPrinting Adjacency List\n";
//	vector<int>::iterator itr;
//	for(int i=0; i<n; i++)
//	{
//		cout<<"\n"<<i+start<<" -> ";
//		for(itr = adjlist[i].begin(); itr < adjlist[i].end(); itr++)		
//		{
//			cout<<*itr+start<<" ";											
//		}
//	}

	//OR
	
//	for(int i=0; i<n; i++)
//	{
//		cout<<"\n"<<i+start<<" -> ";
//		for(int j=0; j<adjlist[i].size(); j++)
//		{
//			cout<<adjlist[i][j]+start<<" ";
//		}
//	}

	//OR
	
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<i+start<<" -> ";
		for(auto x : adjlist[i])
		{
			cout<<x+start<<" ";
		}
	}

	
	return 0;
}
