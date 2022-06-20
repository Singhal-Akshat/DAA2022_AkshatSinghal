#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX

int shortestPath(int V,int **graph, int u, int v, int k)
{
	
	int sp[V][V][k+1];

	
	for (int e = 0; e <= k; e++)
	{
		for (int i = 0; i < V; i++) 
		{
			for (int j = 0; j < V; j++) 
			{
				
				sp[i][j][e] = INF;

			
				if (e == 0 && i == j)
					sp[i][j][e] = 0;
				if (e == 1 && graph[i][j] != INF)
					sp[i][j][e] = graph[i][j];

			
				if (e > 1)
				{
					for (int a = 0; a < V; a++)
					{
						
						if (graph[i][a] != INF && i != a &&
							j!= a && sp[a][j][e-1] != INF)
						sp[i][j][e] = min(sp[i][j][e], graph[i][a] +
													sp[a][j][e-1]);
					}
				}
		}
		}
	}
	return sp[u][v][k];
}

int main()
{
	int V;
    cin>>V;
    int **graph = new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i] = new int[V];
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
	int u,v,k;
    cin>>u>>v>>k;
	cout << shortestPath(V,graph, u-1, v-1, k);
	return 0;
}
