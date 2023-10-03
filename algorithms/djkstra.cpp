#include <bits/stdc++.h>
#define inf 1000000000
#define ii pair<int, int>
using namespace std;

//adj.assign(n, vector<ii>(0));
//adj[a].push_back( ii(b, w) );
vector<int> Dijkstra(vector< vector<ii>> adj,int s, int n)
{
    vector<int> dist;
    dist.resize(n);
    for(int i = 0; i<n; i++) dist[i] = inf;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push( ii(dist[s], s) );
    ii p;
    int t, u;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        t = p.first; u = p.second;
        if(t > dist[u] ) continue;
        for(int i = 0; i<adj[u].size(); i++){
            if(dist[adj[u][i].first] > dist[u] + adj[u][i].second){
                dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                pq.push( ii(dist[adj[u][i].first], adj[u][i].first) );
            }
        }
    }
    return dist;
}