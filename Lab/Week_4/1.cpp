/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.

*/

#include<iostream>
using namespace std;

void merge(int *a, int lb, int mid, int ub, int *inv,int *cmp)
{
    int k=lb, i =0, j=mid;
    
    
    int *b = new int[ub-lb+1];
    while(lb<=j && mid+1<=ub)
    {   
        (*cmp)++;
        if(a[lb]>a[mid+1])
        {   
            b[i++] = a[1 + mid++];
          
            (*inv)+= j+1-lb; // we are coutning that the given element is smaller than how many numbers
            // for ex:
            // 23 45 21
            // so if current element is 21 
            // then 21 is smaller than 2 elements 
            // so this time inversion will be 2
    
          
        }
        else
        {
            b[i++]= a[lb++];
        }
    }

    while(lb<=j)
    {
        b[i++] = a[lb++];
    }

    while(mid+1<=ub)
    {
        b[i++] = a[1+mid++];
    }

    for(int i=k;i<=ub;i++)
    {
        a[i]=b[i-k];
    }
}
void merge_sort(int*a, int lb, int ub, int *inv,int *comp)
{
    if(lb<ub)
    {
        int mid = lb + (ub-lb)/2;

        merge_sort(a,lb,mid,inv,comp);
        merge_sort(a,mid+1,ub,inv,comp);

        merge(a,lb,mid,ub,inv,comp);;
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int *a = new int[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        int inv=0,cmp=0;
        merge_sort(a,0,n-1,&inv,&cmp);

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }

        cout<<"Inversion = "<<inv<<"\nComp = "<<cmp;
    }
}