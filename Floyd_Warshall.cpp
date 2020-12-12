
#include <bits/stdc++.h> 
using namespace std; 


#define V 4 


#define INF 99999 

 
void printSolution(int dist[][V]); 


void floydWarshall (int graph[][V]) 
{ 
	
	int dist[V][V], i, j, k; 


	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 


	for (k = 0; k < V; k++) 
	{ 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) 
		{ 
			
			for (j = 0; j < V; j++) 
			{ 
				
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 


	printSolution(dist); 
} 


void printSolution(int dist[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 


int main() 
{ 

	int graph[V][V] = { {0, 10, INF, 20}, 
						{INF, 0, 30, INF}, 
						{INF, INF, 0, 11}, 
						{INF, INF, INF, 12} 
					}; 


	floydWarshall(graph); 
	cout<<"mahins-Air:~ mahinmittal$ ";
	return 0; 
} 
