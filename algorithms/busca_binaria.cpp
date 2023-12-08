#include <bits/stdc++.h>
using namespace std;


int busca(int arr[],int n ,int c, int f)
{
    int m = (c + f)/2;
    if(arr[m] == n) return 1;
    else if(c >= f) return -1;
    else if (arr[m] < n) busca(arr, n, m+1, f);
    else if (arr[m] > n) busca(arr, n, c, m-1);
    


}


int main()
{
    int n,k,j,q;
    cin >> n >> k;
    int lis[n];
    for(int i = 0; i < n; i++)
    {
        cin >> j;
        lis[i] = j;
    }
    for(int i = 0; i < k;i++)
    {   
        cin >> q;
        int res = busca(lis,q,0,n-1);
        if (res == 1) cout << "YES\n";
        else if(res == -1) cout << "NO\n";
    }
  
}