
/*
Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int target;
    cin>>target;
    int result[n+1][target+1];
    sort(a,a+n);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target; j++)
        {
              if(j==0)
              {
                  result[i][j] = 1;
              }
              else if(i==0)
              {
                  result[i][j] = 0;
              }
              else
              { 
                  if(a[i-1]> j)
                  { 
                      result[i][j] = result[i-1][j];
                  }
                  else
                  {   
                      result[i][j]=result[i-1][j] + result[i][j-a[i-1]];
                  }
              }
    }
    }
    
    cout<<result[n][target];


}