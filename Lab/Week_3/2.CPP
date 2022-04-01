#include<iostream>
using namespace std;
void print_array(int *a, int n);
void selection_sort(int *a, int n)

{   int min_idx = 0,comp=0,shift = 0;;
    for(int i=0;i<n;i++)
    {
        min_idx = i;
        for (int j=i+1;j<n;j++)
        {
            comp++;
            if(a[j]<a[min_idx])
                min_idx = j;
        }

        int temp = a[min_idx];
        a[min_idx]= a[i];
        a[i] = temp;
        shift++;
    }
    print_array(a,n);
    cout<<"comparsion:"<<comp;
    cout<<"Shift: "<<shift;
}

void print_array(int *a, int n)
{

    for(int i=0;i<n;i++)
    {

        cout<<a[i]<<" ";
    }
    cout<<endl;
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
        {

            cin>>a[i];
        }
        selection_sort(a,n);
    }
}
