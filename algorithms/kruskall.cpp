#include <bits/stdc++.h>
using namespace std;

typedef pair <long long,pair<int,int>> pli;
long long inf = 1000000000;
const int MAX_VERTICES = 1e6+15;


vector<pli> grafo[MAX_VERTICES]; //grafo
int par[MAX_VERTICES];


int find(int x)
{
    if (par[x]==x) return x;
    return find(par[par[x]]);
}

int unite(int x, int y)
{
    int pai_x = find(x);
    int pai_y = find(y);
    par[pai_y] = pai_x;
}

void init()
{
    for(int i = 0; i < MAX_VERTICES; i++)
    {
        par[i] = i;
    }
}

int kruskal(vector<pli>& edges, int n)
{
    init();
    sort(edges.begin(), edges.end());
    int maiorpeso = 0;
    for (auto aresta:edges)
    {
        long long peso = aresta.first;
        long long u = aresta.second.first;
        long long v = aresta.second.second;
        int pai_u = find(u);
        int pai_v = find(v);
        if (pai_u != pai_v)
        {
            if (peso > maiorpeso) maiorpeso = peso;
            unite(u,v);
        }
    }
    // sort(distancias.begin(), distancias.end(), greater<int>());
    return maiorpeso;
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
