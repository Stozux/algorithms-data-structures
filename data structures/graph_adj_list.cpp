#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> ii;
vector<vector<ii>> g2;
vector<vector<int>>g;
vector<bool> visit;


void setEdgeW(vector<vector<ii>> g, int v, int w, int p=1)
{
    g[v].push_back((make_pair(w,p)));
}

void setEdge(vector<vector<int>> g, int v, int w)
{
    g[v].push_back(w);
}


int main()
{

}