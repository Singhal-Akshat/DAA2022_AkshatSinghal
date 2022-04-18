/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm 
and implement it using a program to find whether the given key element is present in the array 
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include<iostream>
using namespace std;

int find_dupli(int *a,int n, int key)
{
    int low=0,high = n-1;
    int cnt=0;
    int mid ;
    while(low<=high)
    {
         mid  = low + (high - low ) /2;

        if(a[mid] ==  key)
        {   
            cnt++;
            break;
        }
        else if(a[mid]>key)
        {
            high = mid -1;
        }
        else 
        low = mid +1;
    }

    if(cnt == 1)
    {
        int tmp = mid;

        mid -- ;
        while(a[mid]==key)
        {   
            mid--;
            cnt++;
        }

        mid = tmp+1;

        while(a[mid] == key)
        {   
            mid++;
            cnt++;
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

        int key;
        cin>>key;

        int cnt = find_dupli(a,n,key);

        if(cnt==0)
        {
            cout<<"Not present";
        }
        else
        {
            cout<<key<<"-"<<cnt;
        }
    }
}