int findParent(int parent[], int v) {
    if (parent[v] != v)
        parent[v] = findParent(parent, parent[v]);
    return parent[v];
};

void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
};

void Kruskal_list(Graph_list *G, bool display){
    int size = G->N;
    int numEdges = 0;
    Edge* edges = new Edge[G->max_e]; // max_e - maximum number of edges

    for (int v = 0; v < size; v++) { // creating a list of edges
        adjNode* current = G->adjList[v];
        while (current) {
            if (v < current->val) {
                edges[numEdges].source = v;
                edges[numEdges].destination = current->val;
                edges[numEdges].weight = current->cost;
                numEdges++;
            }
            current = current->next;
        }
    }

    // Sorting edges
    sort(edges, edges + numEdges, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int* parent = new int[size];
    int* rank = new int[size]; 

    for (int v = 0; v < size; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    int treeIndex = 0;

    Edge* minimumSpanningTree = new Edge[size - 1];

    for (int i = 0; i < numEdges; i++) {
        int sourceParent = findParent(parent, edges[i].source);
        int destinationParent = findParent(parent, edges[i].destination);

        if (sourceParent != destinationParent) { // check if edge doesn't create a cycle
            minimumSpanningTree[treeIndex] = edges[i];
            treeIndex++;

            unionSets(parent, rank, sourceParent, destinationParent);

            if (treeIndex == size - 1) // end loop if we found all required edges
                break;
        }
    }
    int sum = 0;
    if(display){
        cout << "---MST using Kruskal--" << endl;
        for (int i = 0; i < size - 1; i++) {
            cout << minimumSpanningTree[i].source << "->" << minimumSpanningTree[i].destination << " (" << minimumSpanningTree[i].weight << ")" << endl;
            sum += minimumSpanningTree[i].weight;
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
    delete[] edges;
    delete[] parent;
    delete[] rank;
    delete[] minimumSpanningTree;
};


void Kruskal_mat(Graph_mat *G,bool display){
    int size = G->getV();
    int numEdges = 0;
    Edge* edges = new Edge[G->getE()]; // max_e - maximum number of edges

    for (int v = 0; v < size; v++) { // creating a list of edges
        for(int j = v+1; j < size; j++) { // j = v+1 so we avoid adding the same edge twice
            if (G->getEdge(v,j) > 0) {
                edges[numEdges].source = v;
                edges[numEdges].destination = j;
                edges[numEdges].weight = G->getEdge(v,j);
                numEdges++;
            }
        }
    }

    // Sorting edges
    sort(edges, edges + numEdges, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int* parent = new int[size];
    int* rank = new int[size]; 

    for (int v = 0; v < size; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    int treeIndex = 0;

    Edge* minimumSpanningTree = new Edge[size - 1];

    for (int i = 0; i < numEdges; i++) {
        int sourceParent = findParent(parent, edges[i].source);
        int destinationParent = findParent(parent, edges[i].destination);

        if (sourceParent != destinationParent) { // check if edge doesn't create a cycle
            minimumSpanningTree[treeIndex] = edges[i];
            treeIndex++;

            unionSets(parent, rank, sourceParent, destinationParent);

            if (treeIndex == size - 1) // end loop if we found all required edges
                break;
        }
    }
    int sum = 0;
    if(display){
        cout << "-MST using Kruskal_mat-" << endl;
        for (int i = 0; i < size - 1; i++) {
            cout << minimumSpanningTree[i].source << "->" << minimumSpanningTree[i].destination << " (" << minimumSpanningTree[i].weight << ")" << endl;
            sum += minimumSpanningTree[i].weight;
        }
        cout << "----------------------" << endl;
        cout << "Final cost of MST: " << sum << endl;
        cout << "----------------------" << endl;
    }
    delete[] edges;
    delete[] parent;
    delete[] rank;
    delete[] minimumSpanningTree;
};


