/*
 
 Implementation of array-based Dijkstra algorithm
 
 */

#include <climits>
#include <cstdlib>
#include <iostream>

#include "../include/Dijkstra_array.hpp"
#include "../include/dijkstra_utility.hpp"



/* function that creates a Queue from an array of nodes */
Queue * create_queue(Node * nodes, int N){
    Node ** queue = new Node*[N];
    
    for (int i = 0; i < N; i++) {
        queue[i] = new Node;
        queue[i] = &(nodes[i]);
    }
    
    Queue * q = new Queue;
    q->array = queue;
    q->N = N;
    return q;
}

bool is_q_empty(Queue * q){
    return (q->N == 0);
}


/* function that removes the i-th node from the queue */
void dequeue_node(Queue * q, int i){
    swap_nodes(&q->array[i], &q->array[q->N - 1]);
    q->N--;
}

/* function that extracts the minimum from the queue */
Node * extract_min(Queue * q){
    
    int min_distance = q->array[0]->distance;
    int min_index = 0;
    
    for (int i = 1; i < q->N; i++) {
        if (q->array[i]->distance < min_distance) {
            min_distance = q->array[i]->label;
            min_index = i;
        }
    }
    
    Node * u = q->array[min_index];
    
    dequeue_node(q, min_index);
    return u;
    
}




void relax(Node* u, Node* v, int weight){
    if(u->distance + weight < v->distance){
        v->distance = u->distance + weight;
        v->pred = u;
    }
}


void dijkstra_array(Graph *g, int start){

    Node * s = get_node(g,start);
    s->distance = 0;
    Queue * Q = create_queue(g->nodes, g->N_nodes);
 
    while(!is_q_empty(Q)){

        Node* u = extract_min(Q);
        int n =  N_adjacent(g, u);
        Node** u_adj = adjacent_nodes(g, u, n);
        
        for(int i=0; i<n; i++)
            relax(u, u_adj[i], get_weight(g, u, u_adj[i]));
    }
}











