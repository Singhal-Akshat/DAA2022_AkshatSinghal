/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))
*/
#include<iostream>
using namespace std;
void merge(int *a, int lb, int  mid, int ub)
{
    int k=lb,i=0,j=mid;
    int *B = new int[ub-lb+1];
    while(lb<=j &&( mid+1)<=ub)
    {
        if(a[lb]<a[mid+1])
        {
            B[i++]=a[lb++];
        }
        else
        B[i++] = a[1+ mid++];
    }

    while(lb<=j)
    {
        B[i++] = a[lb++];
    }

    while((mid+1)<=ub)
    {
        B[i++] = a[1+ mid++];
    }

    for(int i=k;i<=ub;i++)
    {
        a[i] = B[i-k];
    }
}

void merge_sort(int *a, int lb,int ub)
{
    if(lb<ub)
    {
        int mid = lb  + (ub-lb)/2   ;

        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);

        merge(a,lb,mid,ub); 
    }
}

void find_pair(int *a, int n,int key)
{   
    int flag = 0;
    for(int i=0,j=n-1;i<j;)
    {   
       
        if(a[j]==key-a[i])
        {
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;
            j--;
            flag = 1;
        }
        else if(a[j]>key-a[i])
        {
            j--;
        }
        else
        i++;
    }

    if(flag ==0)
    {
        cout<<"No such Element Exist"<<endl;
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

        int *a =  new int [n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }  

        int key ;
        cin>>key;

        merge_sort(a,0,n-1);
        
        find_pair(a,n,key);
    }
}
