/*
You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/
#include<iostream>
using namespace std;

void common(int *a, int *b, int n, int m)
{
    for(int i=0,j=0; i<n && j<m;)
    {   
       
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else
        i++;
    }
}

int main()
{
        int n;
        cin>>n;

        int *a = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int m;
        cin>>m;

        int *b = new int[n];
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }


        common(a,b,n,m);

}