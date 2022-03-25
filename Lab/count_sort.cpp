#include<iostream>
#include <limits.h>
using namespace std;
class Sorting
{   
    int n;
    int *a;

    public:

    Sorting()
    {
        cout<<"Enter number of elements: ";
        cin>>n;

        a = new int[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void count_sort()
    {
        int max = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(a[i]>max)
            max = a[i];
        }

        cout<<"max is : "<<max<<endl;
        int freq[max+1]={0};

        for (int i=0;i<n;i++)
        {
            freq[a[i]]+=1;
        }

        
        int sum=0;
        int sumarray[max+1]={0};
        for (int i=0;i<max+1;i++)
        {   
            sum = sum + freq[i];
            sumarray[i] = sum;
        }


        int sorted_array[n]  = {0};

        for(int i=0;i<n;i++)
        {
            sumarray[a[i]]-= 1;

            sorted_array[sumarray[a[i]]] = a[i];  
        }

        for(int i = 0;i<n;i++)
        {
            cout<<sorted_array[i]<<" ";
        }
    }
};

int main()
{
    Sorting ob;

    ob.count_sort();
}