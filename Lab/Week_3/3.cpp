/*
Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))
*/

#include<iostream>
using namespace std;
void merge(int *a, int lb, int mid, int ub);
void merge_sort(int *a, int lb, int ub)
{
    int mid = 0;

    if(lb<ub)
    {
        mid = lb + (ub-lb)/2;

        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

void merge(int *a, int lb, int mid, int ub)
{
    int k=lb , i=0, j=mid;
    int *B = new int[ub - lb + 1];

    while(lb<=j && (mid+1)<=ub)
    {
        if(a[lb]<a[mid+1])
        {
            B[i++] = a[lb++];
        }
        else
        {
            B[i++] = a[1 + mid++];
        }
    }

    while(lb<=j)
    {
        B[i++] = a[lb++];
    }

    while(mid+1 <= ub )
    {
        B[i++] = a[1 + mid++];
    }


    for(int i=k;i<=ub;i++)
    {
        a[i] = B[i-k];
    };



}

bool find_dupli(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i] ==  a[i+1])
        return true;
    }

    return false;
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


        merge_sort(a,0,n-1);

        if(find_dupli(a,n))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
}