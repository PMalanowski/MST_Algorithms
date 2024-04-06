#include "Prim.h"

void Prim_list(Graph_list *G,bool display){
    int size = G->N;
    PrioQueue pq;
    int src = 0;
    int sum = 0;
    int key[size];
    int parent[size];
    bool inMST[size];
    for(int i = 0; i < size; i++){
        key[i] = __INT_MAX__;
        parent[i] = -1;
        inMST[i] = false;
    }
    pq.enqueue(src,0);
    key[src] = 0;
    
    while (!pq.isEmpty())
    {
        adjNode* front = pq.dequeue();
        int u = front->val;

        if(inMST[u]){
            continue;
        }
        inMST[u] = true;


        adjNode* temp = G->adjList[u];
        while (temp != nullptr)
        {
            
            int v = temp->val;
            int weight = temp->cost;
            if(inMST[v] == false && key[v] > weight){
                key[v] = weight;
                pq.enqueue(v,key[v]);
                parent[v] = u;
            }
            temp = temp->next;
        }
        
    }
    
    if(display){
        cout << "-MST using Prim_list--" << endl;
        for(int i = 1; i < size; i++){
            cout << parent[i] << "->" << i  << " (" << key[i] << ")" << endl;
            sum += key[i];
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
};


void Prim_mat(Graph_mat *G, bool display){
    int size = G->getV();
    PrioQueue pq;
    int src = 0;
    int key[size];
    int parent[size];
    bool inMST[size];
    for(int i = 0; i < size; i++){
        key[i] = __INT_MAX__;
        parent[i] = -1;
        inMST[i] = false;
    }
    pq.enqueue(src,0);
    key[src] = 0;
    
    while (!pq.isEmpty())
    {
        adjNode* front = pq.dequeue();
        int u = front->val;

        if(inMST[u]){
            continue;
        }
        inMST[u] = true;


        
        for(int i = 0; i < G->getV(); i++)
        {
            if(i != 0 && G->getEdge(u,i) != 0){
            if(inMST[i] == false && key[i] > G->getEdge(u,i)){
                key[i] = G->getEdge(u,i);
                pq.enqueue(i,key[i]);
                parent[i] = u;
            }
            }
        }
        
    }
    
    if(display){
        int sum = 0;
        cout << "--MST using Prim_mat--" << endl;
        for(int i = 1; i < size; i++){
            cout << parent[i] << "->" << i  << " (" << key[i] << ")" << endl;
            sum += key[i];
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
}

/*

    */