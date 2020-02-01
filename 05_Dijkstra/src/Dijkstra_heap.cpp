/*
 
 Implementation of heap-based Dijkstra algorithm
 
 */

#include <climits>
#include <cstdlib>
#include <iostream>

#include "../include/heap.hpp"
#include "../include/Dijkstra_heap.hpp"
#include "../include/dijkstra_utility.hpp"


void relax(heap * q, Node* u, Node* v, int w)
{
    if(u->distance + w < v->distance)
    {
        update_distance(q, v, u->distance + w);
        v->pred = u;
    }
}

void dijkstra_heap(Graph *g, int start){
    Node * s = get_node(g,start);
    s->distance = 0;
    heap * Q = build_min_heap(g->nodes, g->N_nodes);
    while(!is_empty(Q)){
        Node* u = extract_minimum(Q);
        int n =  N_adjacent(g, u);
        Node** u_adj = adjacent_nodes(g, u, n);
        
        for(int i=0; i<n; i++)
            relax(Q, u, u_adj[i], get_weight(g, u, u_adj[i]));
    }
}





