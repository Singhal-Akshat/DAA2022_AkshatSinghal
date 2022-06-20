#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);
    int sum = 0;
 
    for(int i=1;i<n;i++)
    {
        a[i] += a[i-1];
        sum+=a[i];
    }

   
    cout<<sum;
   
}