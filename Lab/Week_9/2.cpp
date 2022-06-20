#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<float,pair<int,int>> a, pair<float,pair<int,int>> b)
{
    return a.first > b.first;
}
void fractional_knapsack(vector<pair<float,pair<int,int>>> data, int k)
{   
    float tot_value = 0;
    sort(data.begin(), data.end(),compare); // sorting wrt to value_per_kg in descending order

    for(auto a: data) // traversing in data vector
    {   
        
        if(k>a.second.first)
        {
            k-= a.second.first;
            tot_value  += a.first * a.second.first;
            
        }
        else
        {
            tot_value += a.first * k;
            break; 
        }

    }

    cout<<tot_value;
}
int main()
{
    vector<pair<float,pair<int,int>>> data; // making a vector for data

    // pair< int ,   pair< int,   int>>
    //     value_per_kg    weight  value

    int n;
    cin>>n ; // number of items 

    for(int i=0;i<n;i++)
    {
        int weight, value;
        float value_per_kg ;

        cin>>weight>>value;
        value_per_kg = value/float(weight); // getting value_per_kg for sorting purpose as we need that element whch have more value_per_kg first

        data.push_back(make_pair(value_per_kg,make_pair(weight,value)));
    }

    for(int i=0;i<n;i++)
    {
        cout<<data[i].first<<endl;
    }
    int k;
    cin >> k; // total weight we can carry 
    fractional_knapsack(data,k);    
}