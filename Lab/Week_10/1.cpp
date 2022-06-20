#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
    return a.second.second < b.second.second;  // will sort wrt end time in ascending order
}

void activity_selection(vector<pair<int,pair<int,int>>> activity)
{
    sort(activity.begin(),activity.end(),compare); // sorting w.r.t end_time

    int prev = 0; // fr storing prev end time
    int count=1; // as first activity will always be selected;

    cout<<activity[0].first<<" "; // first activity printing
    prev = activity[0].second.second; // getting end time
    for(int i=1;i<activity.size(); i++)
    {
        if(activity[i].second.first >=  prev) // cheching if start time of current activity is larger then the previous end time
        {
            cout<<activity[i].first<<" "; // printing that activity
            count ++;
            prev = activity[i].second.second; // getting it's end time
        }
    }
}


int main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> activity; // making a vector for storing start time, end time, and index
    // int        pair<     int,           int  >
    // index           start_time       end_time
    for(int i=0;i<n;i++)
    {
        int start,end;
        cin>>start>>end;

        activity.push_back(make_pair(i,make_pair(start,end)));
    }

    activity_selection(activity);
}
