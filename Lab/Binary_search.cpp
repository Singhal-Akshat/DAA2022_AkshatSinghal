#include<iostream>
using namespace std;
class Binary_Search
{   int n;
    int *A;;
    public:

    void get_data(int n)
    {
        this->n = n;
        cout<<"Enter elements into array: ";

        A = (int*)calloc(sizeof(int),n);

        for (int i=0;i<n;i++)
        {
            cin>>A[i];
        }
    }

    int binary(int key, int n)
    {
        int lower = 0, higher = n-1;

        while(lower<higher)
        {   
            int mid  = lower + (higher - lower)/2;
            if(A[mid]==key)
            {
                return mid;
            }
            else if(A[mid]>key)
            {
                higher = mid-1;
            }
            else
            {
                lower = mid+1;
            }
        }

        return -1;
    }

    int binary_rec(int key,int lower, int higher)
    {
        if(lower>higher)
        return -1;

        int mid = (higher+lower)/2;

        if(A[mid]==key)
        {
            return mid;
        }
        else if(A[mid]>key)
        {
            return binary_rec(key,lower,mid-1);
        }
        else
        {
            return binary_rec(key,mid+1,higher);
        }
    }
};

int main()
{
    Binary_Search b;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    b.get_data(n);

    int key;
    cout<<"Enter the key you want to Search: ";
    cin>>key;

    if (b.binary(key,n)==-1)
    {
        cout<<"Key is not found."<<endl;
    }
    else
    {
        cout<<"Key is found at "<<b.binary(key,n)<<" position"<<endl;
    }
    if (b.binary_rec(key,0,n-1)==-1)
    {
        cout<<"Key is not found.";
    }
    else
    {
        cout<<"Key is found at "<<b.binary_rec(key,0,n-1)<<" position"<<endl;
    }
    
}
