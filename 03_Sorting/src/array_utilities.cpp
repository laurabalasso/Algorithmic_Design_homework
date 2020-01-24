#include <iostream>
#include <climits>
#include "../include/array_utilities.hpp"


void swap(int * A, const int& i ,const int& j){
    int temp{A[i]};
    A[i] = A[j];
    A[j] = temp;
}

void Array_Print(int * A, int N){

    for(int i{0}; i < N; i++){
            std::cout<< A[i] << "   ";
        }

    std::cout<< "\n";
}

void Array_Print(double * A, int N){
    
    for(int i{0}; i < N; i++){
        std::cout<< A[i] << "   ";
    }
    
    std::cout<< "\n";
}


int * Array_Alloc(int size){
    int * A = new int[size];
    for(int i = 0; i < size; i++){
        A[i] = 0;
    }
    return A;
}


int Min(int * A, int size){
    int min = A[0];
    for(int i = 1; i < size; i++ ){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Max(int * A, int size){
    int max = A[0];
    for(int i = 1; i<size; i++){
        if(A[i] > max){
            max = A[i]; 
        }
    }
    return max;
}

void Random_Fill(int * A, int size, int rand_max ){
    
    for(int i = 0; i < size; i++){
        A[i] = (rand() % rand_max) + 1;
    }
    
}

void Random_Fill_Double(double * A, int size){
    
    for(int i = 0; i < size; i++){
        A[i] = ((double) rand()/(RAND_MAX));
    }
    
}

void Swap_Node( Node * a, Node * b){
    double tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}


void Bucket_Print(Node * const head){
    if(!head) return;
    Node *aux = head;
    while (aux->next){
        std::cout <<  aux->value << std::endl;
        aux = aux->next;
    }
    std::cout <<  aux->value << std::endl;
    }

int List_Size(Node * const head){
    int size = 0;
    if(!head) return size;
    Node *aux = head;
    while (aux->next) {
        aux=aux->next;
        size++;
    }
    size++;
    return size;
}

Node * append(Node *head, const double value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    if (head){
        Node *aux = head;
        while (aux->next) aux = aux->next;
        aux->next = newNode;
    }
    else head = newNode;
    
    return head;
}


double Get_Value_List(Node * head, int i){
    Node *aux = head;
    int idx = 0;
    while (idx++ < i )
        aux = aux->next;
    
    return aux-> value;
    }
