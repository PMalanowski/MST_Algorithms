#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <ctime>

using namespace std;



struct adjNode
{
    int val, cost;
    adjNode* next;
    adjNode(int v, adjNode* n, int c){val=v;next=n;cost = c;};
    adjNode(){val=-1;next=nullptr;cost = __INT_MAX__;};
};


class Graph_list // graph implemented using adjacency list
{
private:
    
public:
    int N; // number of vertices
    int max_e; // maximum number of edges with given number of vertices
    adjNode **adjList;
    int nr_e; // current number of edges
    Graph_list(int nr_V);
    ~Graph_list();
    void addEdge(int start, int end, int weight);
    void display();
    void randomize(int density); // density in %
};

class Graph_mat
{
private:
    int V; // number of vertices
    int E; // number of edges
public:
    int **adjMat;
    Graph_mat(int nr_V);
    ~Graph_mat();
    int getV(){return V;};
    int getE(){return E;};
    int getEdge(int s,int e);
    void addEdge(int start, int end, int weight);
    void display();
    void randomize(int density);
};




#include "Graph.cpp"
#endif