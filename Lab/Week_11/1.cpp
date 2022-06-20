#include<iostream>
#include<limits.h>
using namespace std;
int matrix_chain(int p[], int i,int j) // recursibe
{
    if(i==j)
    return 0;

    int min = INT_MAX;

    for(int k=i;k<j;k++)
    {
        int val = matrix_chain(p,i,k) + matrix_chain(p,k+1,j) + p[i-1]*p[k]*p[j];

        if(val<min)
        min = val;
    }

    return min;
}

void matrixchain(int p[], int n) // dynamic approach
{   
    int m[n][n];

    for(int i=1;i<n;i++)
    {   
        m[i][i] = 0;
    }

    for(int L=2;L<n;L++)
    {
        for(int i=1;i<n-L+1;i++)
        {
            int j = i+L-1;

            m[i][j] = INT_MAX;

            for(int k=i;k<j;k++)
            {
                int value = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(value<m[i][j])
                {
                    m[i][j] = value;
                }
            }
        }
    }

    cout<<m[1][n-1];
} 
int main()
{
    int n;
    cin>>n;

    int p[n+1];

    for(int i=0;i<=n;i++)
    {   

        cin>>p[i];
        
        
    }
   matrixchain(p,n+1);
}
