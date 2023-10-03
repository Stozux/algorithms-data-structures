#include <iostream>
using namespace std;

int bsearch(string A[], int l, int r, string K){
    if (r >= l){
        int m = (l+r)/2;
        if (K == A[m]){
            return m;
        } else if (K < A[m])
        {
            return bsearch(A,l,m-1,K);
        } else
        {
            return bsearch(A, m+1, r, K);
        }
    } else
    {
        return -1;
    }
    
}