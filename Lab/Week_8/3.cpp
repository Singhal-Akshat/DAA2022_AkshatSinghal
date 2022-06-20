#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#include<list>
using namespace std;


class disjoint_set  // for implementing disjoint_set
{   
    public: 
    int find(int u, vector<int> &parent) // return parent node of every node
    {
        if(parent[u]<0)
        return u;
        else
        return find(parent[u],parent);
    }

    void unionByWeight(int pu, int pv, vector<int> &parent) // it make the union if elements belog to differnet parents
    {
        
            if(parent[pu]<parent[pv])
            {
                parent[pu]+=parent[pv];
                parent[pv] = pu;
            }
            else
            {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
    }
};

class Graph
{
    map<int,list<pair <int,int> > > graph;  // adjacency list for representing graph    
    vector<pair<int, pair<int,int>>> table; // a table for storing the edges in form of a table so that it can be sorted according to wieght
    vector<pair<int, pair<int,int>>> res; //  a res for storing the edges with wieght which are included in min spanning tree'

    private: 

    void print_table( vector<pair<int, pair<int,int>>> table) // printing table ( any initial or final)
    {
        for(int i=0;i<table.size();i++)
        {
            cout<<table[i].first<<" "<<table[i].second.first<<" "<<table[i].second.second<<endl;
        }
    }

    public:

    void create_table_kruskals()  // create a table from the given graph
    {
        for(int i=0;i<graph.size();i++)
        {
            for(auto a : graph[i])
            {
                table.push_back(make_pair(a.first,make_pair(i,a.second)));
            }
        }

        sort(table.begin(), table.end());
    }

    

     void krushkal() // krushkal algo
    {   
        int sum=0;
        int s,d,w; 
        disjoint_set ob;
        vector<int> parent(graph.size(),-1); // making a parent array with all values to -1 initially

        for(int i=table.size()-1;i>=0;i--) // for max spanning tree
        {
            s = table[i].second.first; // getting source 
            d = table[i].second.second; // getting destination
            w = table[i].first; // getting wieght on the edge

            int ps = ob.find(s,parent); // finding parent of source
            int pd = ob.find(d,parent); // finding parent of destination
        

            if(ps!=pd) // if parent of both are not same then we cann add it to spanning tree as it will not form a cycle 
            {   
                res.push_back(table[i]); // adding that edge to our spanning tree
                ob.unionByWeight(ps,pd,parent); // making a union so that this new becomes a single tree
                sum+=w; // adding the wieghts
            }
        }

        print_table(res);
        cout<<"Total weight of minimum spanning tree is: "<<sum;
    }

    void addEdge(int u, int w, int v) // adding edge to a node
    {
        graph[u].push_back(make_pair(w,v));
    }
};

int main()
{
    int v;
    cin>>v; // No of vertices

    Graph ob;

    for(int i=0;i<v;i++)
    {
        int v,w;
        
        cout<<"Enter for : "<<i<<endl;  // enntering adjanceny list for each node
        while(1)
        {   
            cin>>v;
            if(v==-1)
            break;
            cin>>w;
            ob.addEdge(i,w,v);
        }
    }
    
    ob.create_table_kruskals(); // creating a table for krushkal's
    ob.krushkal(); // applying krushkal's algo

}