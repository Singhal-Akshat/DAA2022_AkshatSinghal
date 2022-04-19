/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/

#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;

void rand_pivot(int *a,int n)
{   
    srand(time(0));
    int randpivot = rand()%n;
    
    swap(a[randpivot],a[n-1]);
}

int partition(int *a, int low, int high,int *comp, int *swaps)
{
    int i= low-1, j= low;
    int pivot = a[high];

    while(j<high)
    {   
        (*comp)++;
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
            (*swaps)++;

        }
        j++;
    }
    swap(a[i+1],a[high]);
    (*swaps)++;
    return i+1;
}
void quicksort(int *a, int low, int high,int *comp, int *swap)
{
    if(low<high)
    {   
       
        int p = partition(a,low,high,comp,swap);
        quicksort(a,low,p-1,comp,swap);
        quicksort(a,p+1,high,comp,swap);

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

        int comp=0,swap=0;
        rand_pivot(a,n);
        quicksort(a,0,n-1,&comp,&swap);

        
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparison = "<<comp<<"\nSwaps = "<<swap<<endl;

    }
}