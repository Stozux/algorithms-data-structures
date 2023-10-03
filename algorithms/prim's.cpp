#include <bits/stdc++.h>
#define inf 1000000000
#define ii pair<int, int>
using namespace std;

typedef pair <long long,pair<int,int>> pli;
const int MAX_VERTICES = 1e6+15;


vector<int> Prim(vector< vector<ii>> adj,int s, int n)
{
    vector<int> dist;
    dist.resize(n);
    for(int i = 0; i<n; i++) dist[i] = inf;
    dist[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(dist[s], 0));
    ii p;
    int t, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        t = p.first; u = p.second;
        if(t > dist[u] ) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(dist[adj[u][i].first] >  adj[u][i].second){
                dist[adj[u][i].first] = adj[u][i].second;
                pq.push( ii(dist[adj[u][i].first], adj[u][i].first) );
            }
        }
    }
    return dist;
}



void setEdge(vector<pli>& edges, int a, int b, long long w)
{
    pli newElement;
    newElement.first = w;
    newElement.second.first = a;
    newElement.second.second = b;
    edges.push_back(newElement);
    // newElement.second.first = b;
    // newElement.second.second = a;
    // edges.push_back(newElement);
}
