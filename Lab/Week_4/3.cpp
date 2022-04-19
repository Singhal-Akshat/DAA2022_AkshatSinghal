/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
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
void quickselect(int *a, int low, int high,int *comp, int *swap,int k)
{   
    
    if(k>0)
    {   
       
        int p = partition(a,low,high,comp,swap);
        
        if(p==k-1)
        {
            cout<<a[p];
            return;
        }
        else if(p>k-1)
        quickselect(a,low,p-1,comp,swap,k);
        else
        {
    
            quickselect(a,p+1,high,comp,swap,k);
}
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
        int k;
        cin>>k;
       
        quickselect(a,0,n-1,&comp,&swap,k);

        
      
        cout<<endl;
        

    }
}