#include<iostream>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int linear()
{
    int n,target;
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
   f(i,n)
   {
    if(a[i]==target)
    {
        return i;
    }
    
   }
   return -1;
}
int main()
{
    int index=linear();
    if(index!=-1)
    {
        cout<<"Item Found at : "<<index+1<<" Index";
    }
    else
    cout<<"Item not Found";
    return 0;
}