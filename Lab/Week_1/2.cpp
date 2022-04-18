/*
Given an already sorted array of positive integers, design an algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/
#include<iostream>
using namespace std;

int binary_search(int *a,int low,int high,int key,int *comp)
{
    

    if(low<=high)
    {   
        int mid = low + (high -low )/2;
        (*comp)++;
        if(a[mid]==key)
        {
            return 1;
        }
        else if(a[mid]>key)
        {
            binary_search(a,low,mid-1,key,comp);
        }
        else
        {
            binary_search(a,mid+1,high,key,comp);
        }
    }
    else 
    return 0;
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

        int key;
        cin>>key;

        int comp =0;
        if (binary_search(a,0,n-1,key,&comp))
        {
            cout<<"Present "<<comp;
        }
        else
        {
            cout<<"Not present "<<comp;
        }


    }
}