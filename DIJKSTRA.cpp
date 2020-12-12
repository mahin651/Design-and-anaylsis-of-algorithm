#include<iostream>
#include<climits>     /*Used for INT_MAX*/
using namespace std;
#define vertex 7      /*It is the total no of verteices in the graph*/
int minimumDist(int dist[], bool Dset[])   /*A method to find the vertex with minimum distance which is not yet included in Dset*/
{
	int min=INT_MAX,index;                 /*initialize min with the maximum possible value as infinity does not exist */
	for(int v=0;v<vertex;v++)
	{
		if(Dset[v]==false && dist[v]<=min)      
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void dijkstra(int graph[vertex][vertex],int src) /*Method to implement shortest path algorithm*/
{
	int dist[vertex];                             
	bool Dset[vertex];
	for(int i=0;i<vertex;i++)                      
	{
		dist[i]=INT_MAX;
		Dset[i]=false;	
	}
	dist[src]=0;                                  
	for(int c=0;c<vertex;c++)                           
	{
		int u=minimumDist(dist,Dset);             
		Dset[u]=true;                              
		for(int v=0;v<vertex;v++)                  
		/*Update dist[v] if not in Dset and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
		{
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		}
	}
	cout<<"HOME'S\t\tDISTANCE FRON HOME'S TO COLLEGE"<<endl;
	for(int i=0;i<vertex;i++)                      
	{
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	
	}
	cout<<"mahins-Air:~ mahinmittal$ ";
}
int main()
{
	int graph[vertex][vertex]={{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
		                        {0,0,0,0,1,0,0}};
	dijkstra(graph,0);
	return 0;	                        
}
