#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Graph.h"
#include "PrioQueue.h"
#include <algorithm>

struct Edge {
    int source, destination, weight;
};


int findParent(int parent[], int v);
void unionSets(int parent[], int rank[], int x, int y);
void Kruskal_list(Graph_list *G,bool display);
void Kruskal_mat(Graph_mat *G,bool display);


#include "Kruskal.cpp"

#endif