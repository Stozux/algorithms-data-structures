#include <iostream>
using namespace std;

void merge(long int A[], long int l, long int r){
    long int temp[r+1];
    for(long int i = l; i < r+1; i++)
    {
        temp[i] = A[i];
    }
    long int m = (l+r)/2;
    long int i1 = l, i2 = m+1;
    for (long int curr = l; curr < r+1; curr++)
    {
        if (i1 == m+1)
        {
            A[curr] = temp[i2];
            i2++;
        } else if (i2 > r)
        {
            A[curr] = temp[i1];
            i1++;
        } else if (temp[i1] <= temp[i2])
        {
            A[curr] = temp[i1];
            i1++;
        } else
        {
            A[curr] = temp[i2];
            i2++;
        }
    }
}

void mergesort(long int A[], long int l, long int r){
    if (l<r)
    {
        long int m = (l+r)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,r);
    }
}