/*
Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    int *a = new int[n];

    int max = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int maj = n/2;
    int median = 0;
    if(n%2==0)
    {
        median = n/2;
    }
    else
    {
        median = ((n-1)/2 + (n+1)/2)/2;
    }
    int freq[max] ={0};

    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }

    for(int i=0;i<max;i++)
    {
        if(freq[i]>maj)
        {
            cout<<"Yes"<<endl;
            break;
        }
    }
    cout<<a[median]<<endl;
    
}