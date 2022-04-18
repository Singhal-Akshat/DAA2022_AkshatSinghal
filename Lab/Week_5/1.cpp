/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/
#include<iostream>
using namespace std;

int max_occurence(char *a,int n )
{
    int freq[26] = {0};
    for(int i=0;i<n;i++)
    {
        freq[a[i]-'a']++;
    }

    int max=1,index=0;

    for(int i=0;i<26;i++)
    {
        if(max<freq[i])
        {
            max = freq[i];
            index = i;
        }
    }

    if(max!=1)
    {   
        char ch = 'a' + index;
        cout<<ch<<"-"<<max<<endl;
    }
    else
    {
        cout<<"No Duplicates present"<<endl;
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        char *a =  (char*)new int[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        max_occurence(a,n);
    }

}