/*
 Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. 

Input Format:
Input will be the graph in the form of adjacency matrix or adjacency list.

Output Format:
Output will be 'Yes Bipartite' if graph is bipartite, otherwise print 'Not Bipartite'.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Biparite
{

    map< int, list<int>> adj ;

    public:

    int check_biparite(int v, int start)
    {
        vector<bool> status;
        status.resize(v,false);

        list<int> queue;
        queue.push_back(start);
        status[start] = true;
        int color = 1;
        vector<int> colors;

        colors.resize(v,0);

        while(!queue.empty())
        {
            int t = queue.front();
            queue.pop_front();

            for(auto a: adj[t])
            {   
                if(colors[a] == colors[t])
                {
                    return -1;
                }
                if(!status[a])
                {
                    queue.push_front(a);
                    status[a]=true;
                    colors[a]=color;
                }
            }
            color*=-1;


        }

        return 0;
    }

    void addEdge(int e, int w)
    {
        adj[e].push_back(w);
    }
};

int main()
{
      int v;
    cin>>v;

    Biparite b; 
    for(int i=0;i<v;i++)
    {
        int node=0;
        cout<<endl<<"Enter for node: "<<i<<": ";
        while(1)
        {
            cin>>node;
            if(node==-1)
            break;
            b.addEdge(i,node);
        }
    }
    int start;
        
    if(b.check_biparite(v,0)==-1)
    {
        cout<<"Not Biparite";
    }
    else
    cout<<"Biparite";

    
}