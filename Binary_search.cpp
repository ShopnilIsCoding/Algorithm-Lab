#include<iostream>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int binary()
{
    int n,target,low,mid,high;
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the Array : ";
    f(i,n)
    {
        cin>>a[i];
    }
     cout<<"Enter the target  value : ";
    cin>>target;
    low=0;
    high=n-1;
    
    while (low<=high)
    {
        mid=low+(high-low)/2;
        if(a[mid]==target)
        return mid;
        if(a[mid]<target)
        low=mid+1;
        else
        {high=mid-1;
        }
    }
    
    return -1;
}
int main()
{
    int index=binary();
    if(index!=-1)
    {
        cout<<"Item Found at : "<<index+1<<" Index";
    }
    else
    cout<<"Item not Found";
    return 0;
}