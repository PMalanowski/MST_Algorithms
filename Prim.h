#ifndef PRIM_H
#define PRIM_H

#include "Graph.h"
#include "PrioQueue.h"
#include "Heap.h"



void Prim_list(Graph_list *G,bool display); // Prim's algorithm implemented on a priority queue. Display variable to tell if we want to display the MST.

void Prim_mat(Graph_mat *G, bool display);

#include "Prim.cpp"
#endif