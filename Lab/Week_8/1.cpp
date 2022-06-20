#include<bits/stdc++.h>
using namespace std;
int find_min(vector<int> dis, vector<bool> stat)
{
    int min=0;
    int min_dis =INT_MAX;

    for(int i=0;i<stat.size();i++)
    {
        if(dis[i]<=min_dis && !stat[i] )
        {
            min = i;
            min_dis = dis[i];
        }
    }
    return min;
}
void prims(map<int,list<pair<int,int>>> adj, int source)
{   
    int n= adj.size();
    vector<int> dis(n,INT_MAX);
    vector<bool> stat(n,false);
    vector<int> parent(n,-1);

    dis[source] = 0;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        int u = find_min(dis,stat);
        stat[u] = true;
        for(auto a: adj[u])
        {
            int w = a.second;
            int v = a.first;

            if(w<dis[v] && !stat[v])
            {   
               
                dis[v] = w;
                parent[v] = u;
            }
        }

    
    }

    for(int i=0;i<n;i++)
    {
        cost+=dis[i];
    }
    cout<<"Minimum spanning weight: "<<cost;
}

int main()
{
    map<int,list<pair<int,int>>> adj;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
       

        while(1)
        {
            int v,w;
            cin>>v;
            if(v==-1)
            break;

            cin>>w;
            adj[i].push_back({v,w});
        }
    }

    prims(adj,0);
}