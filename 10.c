#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 9
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");#include <stdio.h>
const int max=10;
int s[10], x[10];
int d,flag=0;
void sumofsub(int,int,int);
int main()
{
	int i,n,sum=0;
printf("Enter maximum no\n");
	scanf("%d",&n);
	printf("Enter the set in increasing order\n");
	
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	printf("Enter the maximum subset value:");
	scanf("%d",&d);
	for(i=1;i<=n;i++)
		sum+=s[i];
	if(sum<d || s[1]>d)
	{
		printf("No subset possible\n");
		flag=1;
	}
	 sumofsub(0,1,sum);
	if(flag==0)
		printf("no subset possible\n");
	return 0;
}
void sumofsub(int m,int k,int r)
{
	x[k]=1;
	if((m+s[k])==d)
	{
		printf("{");
		for(int i=1;i<=k;i++)
		 
			if(x[i]==1)
			{
				printf(" %d ",s[i]);
				flag=1;
			}
			printf("}");
			printf("\n");
	}
	else 
	{
		if(m+s[k]+s[k+1]<=d)
			sumofsub(m+s[k],k+1,r-s[k]);
		if((m+r-s[k]>=d) && (m+s[k+1]<=d))
		{
			x[k]=0;
			sumofsub(m,k+1,r-s[k]);
		}
	}
}

	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) 
{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v]&& dist[u] != INT_MAX&& dist[u] + 
                                                                 graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                                        };
	dijkstra(graph, 0);
	return 0;
}
