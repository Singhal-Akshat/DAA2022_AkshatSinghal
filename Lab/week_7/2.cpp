/**
Design an algorithm and implement it using a program to solve previous question's problem
using Bellman- Ford's shortest path algorithm
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define INF 1e8
void bellman_ford(map<int,list<pair<int,int>>> adj, int source)
{   
    int n = adj.size()+1;
    vector<int> dis(n,INF);
    int count =0;
    dis[source] = 0;
    for(int i=0;i<n-1;i++)
    {   
        
       for(int j=0;j<n;j++) 
       {  
            for(auto e : adj[j])
            {
                int u = j;
                int v = e.first;
                int w = e.second;

                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                }
                count++;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<dis[i]<<" ";
    }

}

int main()
{
    // vector<vector<int>> adj;
    // int n,m;
    // cin>>n;
    // cin>>m;

    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w;
    //     cin>>u>>v>>w;

    //     adj.push_back({u,v,w});
    // }

    map<int, list<pair<int,int>>> adj;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
       //cout<<"Enter for node: "<<i;
        while(true)
        {
            int v,w;
            cin>>v;
            if(v==-1)
            break;

            cin>>w;
            adj[i].push_back({v,w});
        } 
    }
    cout<<adj.size()<<endl;
    bellman_ford(adj,0);
}