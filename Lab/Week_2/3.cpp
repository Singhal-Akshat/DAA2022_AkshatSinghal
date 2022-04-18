/*
Given an array of nonnegative integers, design an algorithm and a program to count the number 
of pairs of integers such that their difference is equal to a given key, K. 
*/

#include<iostream>
using namespace std;

int pair_equal_to_k(int *a, int n, int key)
{   
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {   
    
            if(abs(a[i]-a[j])==key)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int *a =  new int[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int k;
        cin>>k;
        cout<<pair_equal_to_k(a,n,k);
    }
}
