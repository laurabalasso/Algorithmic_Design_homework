#ifndef dijkstra_utility_hpp
#define dijkstra_utility_hpp

#include <iostream>
#include <climits>
#include <cstdlib>

struct Node {
    int label;
    int distance;
    int position;
    Node * pred;
};

struct Graph{
    
    Node * nodes;
    int ** adjacency_matrix;
    int N_nodes;
    
    void init_graph(int ** adj_matrix, int size);
    void print_graph();
};



inline void Graph::init_graph(int ** adj_matrix, int size){
    this->N_nodes = size;
    this->adjacency_matrix = adj_matrix;
    this->nodes = new Node[size];
    
    for(int i = 0; i < this-> N_nodes; i++){
        this->nodes[i].label = i;
        this->nodes[i].distance  = INT_MAX;
        this->nodes[i].pred = NULL;
    }
}

inline void Graph::print_graph(){
    int size = this->N_nodes;
    for(int i=0; i<size; i++)
    {
        std::cout << "\nnode: " << this->nodes[i].label << " , distance: " << this->nodes[i].distance ;
        if((this->nodes[i].pred)!=NULL)
            std::cout << ", predecessor: " << this->nodes[i].pred->label;
        else
            std::cout << ", /";
    }
    std::cout << "\n";
}


Node * get_node(Graph * g, int label);

void swap_nodes(Node ** a, Node **b) ;

int get_weight(Graph * g, Node * start, Node* end);

int N_adjacent(Graph *g, Node *u);

Node** adjacent_nodes(Graph* g, Node* u, int n);

void init_adjacency_matrix(int ** adj_mat, int  size);

void print_matrix(int** matrix, int size);

#endif /* dijkstra_utility_hpp */
