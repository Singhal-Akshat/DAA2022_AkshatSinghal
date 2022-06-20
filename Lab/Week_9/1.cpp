/*
FLOYD-WARSHALL ALGO
*/

#include<limits.h>
#include<iostream>
using namespace std;
#define INF 1e7;
void floyd_warshall(int v,int *adj[])
{
    int dis[v][v];

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dis[i][j] = adj[i][j];
        }
    }
    

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int v;
    cin>>v;

    int **adj = new int*[v];

    for(int i=0;i<v;i++)
    {
        adj[i] = new int[v];
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            int e;
            cin>>e;
            if(e==-1)
            {
                adj[i][j]= INF;

            }
            else
                adj[i][j] = e;
        }
    }

    floyd_warshall(v,adj);
}