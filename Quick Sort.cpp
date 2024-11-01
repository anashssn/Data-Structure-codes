#include <iostream>

using namespace std;

int Partition(int *A, int start, int e)
{
    int pivot = A[e];
    int partitionIndex = start;
    for(int i = start ; i < e; i++)
    {
        if(A[i] <= pivot)
        {
            swap(A[i],A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[e]);
    return partitionIndex;
}

void QuickSort(int *A, int start, int e)
{
    if(start < e)
    {
        int partitionIndex  = Partition(A,start, e);
        QuickSort(A, start, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, e);
    }
}

int main()
{
    int A[] = {7,6,4,9,8,3,2,0,1};
    cout<<"Quick Sort: ";
    QuickSort(A, 0, 8);
    for(int i = 0; i<9; i++)
    {cout<<A[i]<<" ";}
}
