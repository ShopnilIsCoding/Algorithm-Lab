#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int  main()
{
    int n;
    cout<<"Enter size of an array : ";
    cin>>n;
    int a[n];
    f(i,n)
    {
        cin>>a[i];
    }

    f(i,n-1)
    {
        int index=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<index)
            {
                int temp=a[j];
                a[j]=index;
                a[i]=temp;
            }
        }
    }
    f(i,n)
    {
        cout<<a[i];
    }
}
