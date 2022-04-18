/* Given a sorted array of positive integers, design an algorithm and implement it using a program 
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/

#include<iostream>
using namespace std;

int find_sequence(int *a,int n)
{   
   
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[j]==(a[k]-a[i]))
                {   
    
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                    return;
                }
            }

        }

    }
        cout<<"No sequence";
    
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
        {cin>>a[i];}

        find_sequence(a,n);

    }
}