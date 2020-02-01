#include "../include/dijkstra_utility.hpp"


Node * get_node(Graph * g, int label){
    if(label <= g->N_nodes )
        return &(g->nodes[label]);
    
    return NULL;
}


void swap_nodes(Node ** a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

int get_weight(Graph * g, Node * start, Node* end){
    return g->adjacency_matrix[start->label][end->label];
}

int N_adjacent(Graph *g, Node *u){
    int n = 0;
    for(int i=0; i < g->N_nodes; i++){
        if((g->nodes)[i].label == u->label) continue;
        n+=(get_weight(g, u, &(g->nodes)[i]))< INT_MAX;
    }
    return n;
}



Node** adjacent_nodes(Graph* g, Node* u, int n)
{
    Node** adjacents = new Node*[n];
    int a = 0;
    for(int i=0; i<g->N_nodes; i++)
    {
        int w = get_weight(g,u,&(g->nodes)[i]);
        if(w < INT_MAX && (g->nodes)[i].label != u->label)
            adjacents[a++] = &(g->nodes)[i];
    }
    
    return adjacents;
}


void init_adjacency_matrix(int ** adj_mat, int  size){
    for(int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            adj_mat[i][j]=INT_MAX;
        }
    }
}

void print_matrix(int** matrix, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == INT_MAX) std::cout <<"INF\t";
            else std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

