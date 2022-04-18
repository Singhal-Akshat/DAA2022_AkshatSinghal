/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array 
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k]
 and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element 
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): 
*/

#include<iostream>
using namespace std;

int Jump_Search(int *a,int n, int key)
{
    int jmp = 1,flag = 0,comp=0;

    while(jmp<n)
    {   
        if(a[jmp]==key)
        {   
            comp++;
            flag = 1;
        }
        else if(a[jmp]>key)
        {   
             
            for(int i=jmp/2;i<jmp;i++)
            {
                if(a[i]==key)
                    flag = 1;
            }
        }

        jmp = jmp*2;
    }

    if(flag == 1)
    {
        cout<<"Present"<<endl;
    }
    else
    cout<<"Not Present"<<endl;


    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int *a =  new int [n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int key;
        cin>>key;

        Jump_Search(a,n,key);
    }
}
