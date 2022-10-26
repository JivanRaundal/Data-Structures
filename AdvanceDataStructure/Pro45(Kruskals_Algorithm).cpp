// Kruskal's Algorithm (to find Minimum Spanning Tree)

#include<iostream>
using namespace std;

class Edge
{
	public:
		int u, v, w;
};

void kruskal()
{
	int n;
	cout<<"\nEnter number of vertices : ";
	cin>>n;
	//create Edge array
	int x = ((n*(n-1))/2);		//Note:- if graph has n vertices then maximum edges graph can have will be n*(n-1)/2
	Edge * elist = new Edge[x];
	int i,j,k,u,v,w,total;
	//scanning edges from user in an array
	cout<<"\n\nKeep entering edges in (u,v,w) form\n";
	i=0;
	while(1)
	{
		cin>>u>>v>>w;
		if(u==-1 || v==-1 || w==-1)
		{
			break;
		}
		elist[i].u = u;
		elist[i].v = v;
		elist[i].w = w;
		i++;
	}
	total = i;			//total number of edges entered by user in elist array
	//sort elist array in ascending order of weight
	Edge temp;
	for(i=0; i<total; i++)
	{
		for(j=i+1; j<total; j++)
		{
			if(elist[i].w > elist[j].w)
			{
				temp     = elist[i];
				elist[i] = elist[j];
				elist[j] = temp;
			}
		}
	}
	
	//now create component array & initialize it to different numbers
	int * component = new int[n];
	for(i=0; i<n; i++)
	{
		component[i] = i;
	}
	int ne = n-1;							//no of edges in MST
	Edge * spanlist = new Edge[ne];			//creating spanlist array
	//NOTE:- basic preparation done, now start kruskal's algorithm
	int cu, cv;
	int mincost = 0;
	i=0;			//i will work as index of elist array
	k=0;			//k will work as index of spanlist array
	while(k < ne)
	{
		u = elist[i].u;
		v = elist[i].v;
		w = elist[i].w;
		//find component number of vertex u & v
		cu = component[u];
		cv = component[v];
		//if component numbers are different, then add that edge in spanlist array
		if(cu != cv)
		{
			//add an edge in spanlist
			spanlist[k].u = u;
			spanlist[k].v = v;
			spanlist[k].w = w;
			k++;
			//calculating min cost here 
			mincost = mincost + w;
			//now, replace every cv by cu in component array
			for(j=0; j<n; j++)
			{
				if(component[j] == cv)
				{
					component[j] = cu;
				}
			}
		}
		i++;
	}
	
	cout<<"\n\nPrinting spanlist array (i.e. edges of Minimum Spanning Tree)\n";
	for(i=0; i<ne; i++)
	{
		cout<<"\n"<<spanlist[i].u<<"  "<<spanlist[i].v<<"  "<<spanlist[i].w;
	}
	cout<<"\n\nMinimum Cost = "<<mincost;
}

int main()
{
	kruskal();
	return 0;
}
