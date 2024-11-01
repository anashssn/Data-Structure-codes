#include <iostream>
using namespace std;

void MaxHeap(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while(j<=n)
    {
        if(j<n && a[j+1]>a[j])
            j = j +1;
        if(temp>a[j])
            break;
        else if(temp<=a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}

void BuildMaxHeap(int *a, int n)
{
    int i;
    for(i=n/2 ; i>=1 ; i--)
    {
        MaxHeap(a, i, n);
    }
}
int main()
{
    int n, i, x;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int a[20];
    cout<<"Enter the elements of the array: " <<endl;
    for(i = 1 ; i<=n ; i++)
    {
        cin>>a[i];
    }
    BuildMaxHeap(a,n);
    cout<<"Max Heap"<<endl;
    for(i = 1 ; i <= n ; i++)
        cout<<a[i]<<endl;
    return 0;
}
