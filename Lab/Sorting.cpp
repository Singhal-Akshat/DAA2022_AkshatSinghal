#include<iostream>
#include<limits.h>
using namespace std;

class Sorting
{   
    public: 
    void bubble_sort(int a[],int n)
    {   
        int flag = 0;
        for(int i=0;i<n-1;i++)
        {   
            flag =0;
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    flag =1;
                }
            }

            if(flag == 0)
            break;
        }
    }

    void selection_sort(int a[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            int min = a[i];
            int pos = i;

            for(int j=i+1;j<n;j++)
            {
                if(min>a[j])
                {
                    min = a[j];
                    pos = j;
                }
            }

            if(min!=a[i])
            {
                a[pos] = a[i];
                a[i] = min;
            }
            
        }
    }

    void insertion_Sort(int a[],int n)
    {   
        for(int i=1;i<n;i++)
        {
            int min = a[i];
            int j=i-1;

            while(a[j]>min  && j>=0)
            {   
                a[j+1] = a[j];
                j--;
            }

            if(j!=i-1)
            {
                a[j+1] = min;
            }
        }
    }

    void quick_sort(int a[], int lb, int ub)
    {
        if(lb<ub)
        {
            int pivot = Partition(a,lb,ub);

            quick_sort(a,lb,pivot-1);
            quick_sort(a,pivot+1,ub);
            
        }
    }

    int Partition(int a[], int lb, int ub)
    {
        int i = lb -1;
        int j=lb;
        int pivot = a[ub];

        while(j<ub)
        {
            if(a[j]<=pivot)
            {   
                i++;
                swap(a[i],a[j]);
            }
            j++;
        }
        swap(a[i+1],a[ub]);
        return i+1;
    }

    void merge_sort(int a[], int lb, int ub)
    {   
        if(lb<ub)
        {   
            int mid = lb + (ub-lb)/2;

            merge_sort(a,lb,mid);
            merge_sort(a,mid+1,ub);

            merge(a,lb,mid,ub);
        }
    }

    void merge(int a[], int lb , int mid, int ub)
    {   
        
        int i=lb;
        int j= mid + 1;
        
        int *b = new int[ub-lb+1];
        int k=0;
        while(i<=mid && j<=ub)
        {
            if(a[i]>a[j])
            {
                b[k++] =  a[j++];
            }
            else
            {
                b[k++] = a[i++];
            }
        }

        while(i<=mid)
        {
            b[k++] = a[i++];
        }

        while(j<=ub)
        {
            b[k++] = a[j++];
        }

        for(int i=lb;i<=ub;i++)
        {
            a[i] = b[i-lb];
        }
    }

    int * counting_sort(int a[], int n)
    {
        int max = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(a[i]>max)
            {
                max = a[i];
            }
        }

        int freq[max+1] = {0};

        for(int i=0;i<n;i++)
        {
            freq[a[i]]++;
        }

        for(int i=1;i<max+1;i++)
        {
            freq[i] +=  freq[i-1];
        }

        int sorted_Array[n];

        for(int i=0;i<n;i++)
        {
            freq[a[i]] --;

            sorted_Array[freq[a[i]]] = a[i];
        }

        print_Array(sorted_Array,n);
    }

    void print_Array(int a[], int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    Sorting s;

    //s.bubble_sort(a,n);
   // s.selection_sort(a,n);
   //s.insertion_Sort(a,n);
   //s.quick_sort(a,n);
   //s.merge_sort(a,n);
     s.counting_sort(a,n);
   // s.print_Array(a,n);
}