/*
Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
*/
#include<bits/stdc++.h>
using namespace std;
class graph
{   
    vector<bool> status;
    int total;
    map<int,list<int>> adj;
    
    public:
    graph(int total)
    {
        this->total = total;

        status.resize(total,false);
    }

    bool isCycle(int i)
    {
        status[i] = true;

        for(auto a: adj[i])
        {
            if(!status[i])
            {
                status[i]=true;
                isCycle(i);
            }
            else
            return true;
        }
        return false;
    }

    void addnodes(int e, int i)
    {
        adj[e].push_back(i);
    }

};

int main()
{
    int total_edge;

    graph g(total_edge);
    for(int i=0;i<total_edge;i++)
    {
        cout<<"Enter for "<<i;

        int num;

        while(1)
        {
            cin>>num;
            if(num==-1)
            break;

            g.addnodes(i,num);
        }
    }

    if(g.isCycle(0))
    {
        cout<<"yes cycle exist";
    }
    else
    {
        cout<<"Cycle does not exist";
    }
}