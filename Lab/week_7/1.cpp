// /*
// After end term examination, Akshay wants to party with his friends. All his friends are living as
// paying guest and it has been decided to first gather at Akshay’s house and then move towards
// party location. The problem is that no one knows the exact address of his house in the city.
// Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
// came up with an amazing idea to help his friends. He draws a graph by looking in to location of
// his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
// shortest distance and path covering that distance from each of his friend’s location to his house
// and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
// developed the program that implements Dijkstra’s algorithm but not sure about correctness of
// results. Can you also implement the same algorithm and verify the correctness of Akshay’s
// results? -(Hint: Print shortest path and distance from friends’ location to Akshay’s house)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Djisktra
{   
    int n;
    // vector<pair<int,int>> graph[n];
    map<int,list<pair<int,int>>> graph;
    int INF = INT_MAX;
    public:
    Djisktra(int n)
    {
        this->n = n;
    }
    void insert_graph()
    {
        for(int i=0;i<n;i++)
        {   
            cout<<"Insert for "<<i<<": "<<endl;
            int y,wt;
            while(1)
            {
                cin>>y;
                if(y==-1)
                break;

                cin>>wt;
                graph[i].push_back({y,wt});
            }
        }
    }

    void Dijsktra(int source)
    {
        vector<int> dist(n,INF);
        vector<bool> vis(n,false);

        set<pair<int,int>> st;

        st.insert({0,source});
        dist[source] = 0;

        while(st.size() > 0)
        {
            auto node = *st.begin(); // to get least element
            int v = node.second;
            int v_dist = node.first;
            st.erase(st.begin());
            vis[v] =true;
            for(auto a: graph[v])
            {
                if(dist[a.first] > dist[v] + a.second)
                {   
                    cout<<a.first<<" ";
                    dist[a.first] = dist[v] + a.second;
                    st.insert({dist[a.first],a.first});
                }
            }
            cout<<dist[v]<<endl;
        }


        for(int i=0;i<n;i++)
        {
            cout<<dist[i]<<" ";
        }
    }
};

int main()
{   
    int n;
    cin>>n;
    Djisktra ob(n);
    ob.insert_graph();
    ob.Dijsktra(0);

}