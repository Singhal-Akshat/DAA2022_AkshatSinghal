#include<iostream>
using namespace std;

bool subset_sum(int arr[], int sum,int n)
{
    if(n==0)
    {
        return false;
    }

    if(sum==0)
    {
        return true;
    }

    if(sum<arr[n-1])
    {
        return subset_sum(arr,sum,n-1);
    }
    else
    {
        return subset_sum(arr,sum,n-1) || subset_sum(arr,sum-arr[n-1],n-1);
    }
}

int main()
{
    int n;
    cin>>n;

    int *a = new int[n];
    int sum =0 ;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%2==0)
    {
        if(subset_sum(a,sum/2,n))
        {
            cout<<"yes";
        }
        else
        {
            cout<<"No";
        }
    }
    else
    {
        cout<<"No";
    }
}