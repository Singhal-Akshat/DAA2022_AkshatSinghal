/*
Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
deadline associated with it. You have to design an algorithm and implement it using a program to
find maximum number of tasks that can be completed without crossing their deadlines and also
find list of selected tasks
*/

#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}
void max_tasks(vector<pair<int,int>> &tasks)
{
    sort(tasks.begin(),tasks.end(),cmp);
    int counter =0;
    vector<int> activity_selected;
    for(auto a:tasks)
    {
        cout<<a.first<<" "<<a.second<<endl;
    }
    int max =0;
    for(auto a: tasks)
    {
        if(a.second>max)
        max = a.second;
    }
    vector<int> time(max,-1);

    for( auto a: tasks)
    {   
        int count = a.first;

        // cout<<"count: "<<count<<endl;//
        int k=a.second-1;
        // cout<<"out k: "<<k<<" "<<time[k]<<endl;//
        if(time[k]!=-1)
        {   int flag =0;
            for(int m=k-1;m>=0;m--)
            {   
                if(time[m]==-1)
                {
                    k=m;
                    flag =1;
                    break;
                }
            }

            if(flag==0)
            continue;
        }
       
        if(k+1-count>=0)
       {    
        int flag =0;
        for(int j=0;j<count;j++)
        {
            if(time[k-j]!=-1)
            {flag =1;
            break;
            }
        }
        if(flag ==1)
        continue;

            // cout<<"k : "<<k<<endl;/
        for(int j=0;j<count;j++)
        {
            time[k-j] = a.first;
        }
        counter++;
        
            // for(int a:time)
            // {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
    }

    
    }

    for(int a:time)
    {
        cout<<a<<" ";
    }
    cout<<endl<<counter;
}
int main()
{
    vector<pair<int,int>> data;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int time,deadline;
        cin>>time>>deadline;

        data.push_back({time,deadline});
    }

    // for(auto a:data)
    // {
    //     cout<<a.first<<" "<<a.second<<endl;
    // }
    max_tasks(data);
}