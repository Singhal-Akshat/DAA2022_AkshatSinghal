/*
Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)

Input Format:
Input will be the graph in the form of adjacency matrix or adjacency list.
Source vertex number and destination vertex number is also provided as an input.

Output Format:
Output will be 'Yes Path Exists' if path exists, otherwise print 'No Such Path Exists'.
*/

#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map< int, list<int> > adj;

    public:
    void DFS(int v,int start, int dest)
    {
        vector<bool> status;
        status.resize(v,false);

        list<int> stack;

        status[start] = true;
        stack.push_front(start);
        cout<<start<<" ";
       
        int flag = 0;
        while(!stack.empty())
        {   
            flag = 0;
            int t = stack.front();
          
            for(auto a: adj[t])
            {   
               
                if(!status[a])
              {
                    flag =1;
                    status[a] = true;
                    stack.push_front(a);
                   // cout<<a<<" ";
                    if(a==dest)
                   {    
                       cout<<"yes path exist";
                        return;}
                    
                    break;
                }
            } 
            if(flag == 0)
            {
                stack.pop_front();
            }
        }
        cout<<"Path does not exist";
    }

     void BFS(int v,int start, int dest)
    {
        vector<bool> status;
        status.resize(v,false);

        list<int> queue;

        status[start] = true;
        queue.push_back(start);
        cout<<start<<" ";
       
        int flag = 0;
        while(!queue.empty())
        {   
            flag = 0;
            int t = queue.front();
            queue.pop_front();
            for(auto a: adj[t])
            {   
               
                if(!status[a])
              {
                    flag =1;
                    status[a] = true;
                    queue.push_back(a);
                    //cout<<a<<" ";
                    if(a==dest)
                    {   
                        cout<<"yes path exist";
                        return;}
                    
                }
            } 
        }
        cout<<"No path exist";
        
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

    Graph g; 
    for(int i=0;i<v;i++)
    {
        int node=0;
        cout<<endl<<"Enter for node: "<<i<<": ";
        while(1)
        {
            cin>>node;
            if(node==-1)
            break;
            g.addEdge(i,node);
        }
    }

    g.DFS(v,0,6);
}