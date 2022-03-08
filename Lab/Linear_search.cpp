#include<iostream>
using namespace std;
class Linear_search
{
    int n;
    int *A;;
    public:

    void get_data()
    {
        cout<<"Enter number of elements: ";
        cin>>n;
        cout<<"Enter elements into array: ";

        A = (int*)calloc(sizeof(int),n);

        for (int i=0;i<n;i++)
        {
            cin>>A[i];
        }
    }

    int L_search(int key)
    {
        for(int i=0;i<n;i++)
        {
            if(A[i]==key)
            return i;
        }

        return -1;
    }
};
int main()
{
    Linear_search l;
    l.get_data();

    int key ;
    cout<<"Enter the key you want to search: ";
    cin>>key;

    if( l.L_search(key) ==-1)
    {
        cout<<"Key is not found.";
    }
    else
    {
        cout<<"Key is found at "<<l.L_search(key)<<" position.";
    }
}