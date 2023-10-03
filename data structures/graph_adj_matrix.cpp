#include <bits/stdc++.h>
using namespace std;

typedef struct Graph
{
    int **matrix;
    int numEdge;
    int size;
    int *Mark;
}graph;


graph* create_graph(int n)
{
    graph* g = (graph*) malloc (sizeof(graph));
    g->Mark = (int*) calloc (sizeof(int),n);
    g->matrix = (int**) malloc(sizeof(int*)*n);
    g->size = n;
    for (int i = 0; i < n; i++)
    {
        g->matrix[i] = (int*) calloc (sizeof(int),n); 
    }
    g->numEdge = 0;
    return g;
}


int first (graph* g, int v)
{
    for (int i = 0; i < g->size; i++)
    {
        if (g->matrix[v][i] != 0)
        {
            return i;
        }
    }
    return g->size;
}

int next (graph* g, int v, int w)
{
    for (int i = w+1; i < g->size;i++)
    {
        if (g->matrix[v][i] != 0)
        {
            return i;
        }
    }
    return g->size;
}

void setEdge(graph* g, int i, int j, int wt = 1)
{
    if (wt == 0)
    {
        return;
    }
    if (g->matrix[i][j] == 0)
    {
        g->numEdge++;
    }
    g->matrix[i][j] = wt;
}

void delEdge(graph* g, int i, int j)
{
    if(g->matrix[i][j] != 0)
    {
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}