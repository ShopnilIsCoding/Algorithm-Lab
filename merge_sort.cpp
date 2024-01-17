#include<bits/stdc++.h>
using namespace std;
#define Loop_chala_beda(i,n) for(int i=0;i<n;i++)
long long merge_koro(int a[],int start,int mid,int end)
{
     int i,j ,k;
     long long inversions = 0;
     int n1=mid-start+1;
     int n2=end-mid;
     int leftA[n1],rightA[n2];
     Loop_chala_beda(i,n1)
     leftA[i]=a[start+i];
     Loop_chala_beda(j,n2)
     rightA[j]=a[mid+1+j];

     i=0;
     j=0;
     k=start;

     while(i<n1 && j<n2)
    {
        if(leftA[i]<=rightA[j])
        {
            a[k]=leftA[i];
            i++;
        }
        else
        {
            a[k]=rightA[j];
            j++;
            inversions += (n1 - i);
        }
        k++;
    }

    while (i<n1)
    {
        /* code */
        a[k]=leftA[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=rightA[j];
        j++;
        k++;
    }
    return inversions;
    
}

long long  sort_koro(int a[], int start ,int end)
{
    long long inversions=0;
if(start<end)
{
    
    int mid=(start+end)/2;
        inversions += sort_koro(a, start, mid);
        inversions += sort_koro(a, mid + 1, end);
        inversions += merge_koro(a, start, mid, end);
}
return inversions;
}

void print_koro(int a[],int n)
{
    Loop_chala_beda(i,n)
    cout<<a[i]<<" ";

}

signed main()
{
     int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    Loop_chala_beda(l, n)
        cin >> a[l];

    long long inversions = sort_koro(a, 0, n - 1);
    cout << "Inversion Count: " << inversions << endl;

    cout << "Sorted Data: ";
    print_koro(a, n);

    return 0;
}