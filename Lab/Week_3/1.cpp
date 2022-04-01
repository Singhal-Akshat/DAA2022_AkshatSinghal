#include<iostream>
using namespace std;
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
        {

            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        int comparison=0,shifting = 0;
        for(int i=1;i<n;i++)
        {
            int j = i-1;

            int current =  a[i];

            while( comparison ++ && j>=0 && a[j]>current )
            {
                a[j+1] = a[j];
                j--;
                shifting ++;
            }
                    a[j+1] = current;

        }

        for(int i=0;i<n;i++)
        {

            cout<<a[i]<<" ";
        }
        cout<<endl<<"Number of comaprison: "<<comparison<<endl;
        cout<<"Number of shifts = "<<shifting;

    }
}
