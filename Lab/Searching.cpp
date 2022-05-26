#include<iostream>
#include<math.h>
using namespace std;

class Searching
{   
    public: 
    int LinearSearch(int a[], int n,int key)
    {
        for(int i = 0;i<n;i++)
        {
            if(a[i]==key)
            {
                return i;
            }
        }
        return -1;
    }

    int BinarySearch(int a[], int n,int key)
    {
        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = low + (high - low)/2;

            if(a[mid]==key)
            {
                return mid;
            }
            else if(a[mid]>key)
            {
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }

    int BinarySearch(int a[],int low, int high, int key)
    {
        if(low<=high)
        {
            int mid = low + (high - low)/2;

            if(a[mid] == key)
            {
                return mid;
            }
            else if(a[mid]>key)
            {
                BinarySearch(a,low,mid-1,key);
            }
            else
            {
                BinarySearch(a,mid+1,high,key);
            }
        }

        return -1;
    }


    int Exponential_Search(int a[], int n, int key)
    {
        int exp = 1;

        while(exp<n)
        {
            if(a[exp] == key)
            {
                return exp;
            }
            else if(a[exp]>key)
            {
                return BinarySearch(a,exp/2,exp,key);
            }
            exp*=2;
            
        }
    }

    int JumpSearch(int a[], int n, int key)
    {
        int jump = sqrt(n);
        int multiplier = 1;
        while(multiplier*jump < n)
        {
            if(a[jump]==key)
            {
                return jump;
            }
            else if(a[jump]>key)
            {
                for(int i=jump*multiplier-jump;i<jump*multiplier;i++)
                {
                    if(a[i] == key)
                    return i;
                }
            }
        
            multiplier++;
        }

        return -1;
    }

    void FoundAt(int index)
    {
        if(index==-1)
        {
            cout<<"Element is not found";
        }
        else
        {
            cout<<"Element found at : "<<index<<endl;
        }
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

    int key;
    cout<<"Enter key you want to find: ";
    cin>>key;

    Searching s;

    s.FoundAt(s.LinearSearch(a,n,key));
    s.FoundAt(s.BinarySearch(a,n,key));
    s.FoundAt(s.BinarySearch(a,0,n-1,key));
    s.FoundAt(s.Exponential_Search(a,n,key));
    s.FoundAt(s.JumpSearch(a,n,key));




}