#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "Graph.h"

class PrioQueue // elements from low to high priority (we reuse adjNode struct used in adjacency lists in graphs)
{
private:
    adjNode* front;
public:
    PrioQueue(){front=nullptr;};
    ~PrioQueue();
    void enqueue(int v,int prio);
    adjNode* dequeue();
    void display();
    bool isEmpty();
};

#include "PrioQueue.cpp"
#endif