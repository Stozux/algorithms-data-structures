#include <iostream>
using namespace std;



int partition(int A[], int l, int r)
{
    int p = A[l], i = l, j = r+1;
    do
    {
        do
        {
            i++;
        } while (A[i] < p && i < r);
        do
        {
            j--;
        } while (A[j] > p);
        swap (A[i], A[j]);
    } while (i < j);
    swap (A[i], A[j]);
    swap (A[l], A[j]);
    return j;
}

void quicksort(int A[], int l, int r)
{
if (l < r)
    {
        int s;
        s = partition(A,l,r);
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);
    }
}
