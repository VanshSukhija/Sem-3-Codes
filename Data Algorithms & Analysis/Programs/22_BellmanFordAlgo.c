#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex, weight, dist;
    struct Gnode *next;
}Gnode;

Gnode **createGraph(int vertices){
    Gnode **graph = (Gnode **)malloc(sizeof(Gnode *)*vertices);
    for(int i=0; i<vertices; i++)
        graph[i] = NULL;
    return graph;
}

void addDirectedEdge(Gnode **graph, int src, int target, int weight){
    Gnode *new = (Gnode *)malloc(sizeof(Gnode));
    new->vertex = target;
    new->weight = weight;
    new->dist = 100000000;
    new->next = NULL;
    Gnode *temp = graph[src];
    if(temp==NULL)
        graph[src] = new;
    else{
        while(temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

void addUndirectedEdge(Gnode **graph, int src, int target, int weight){
    Gnode *new = (Gnode *)malloc(sizeof(Gnode));
    new->vertex = target;
    new->weight = weight;
    new->dist = 100000000;
    new->next = NULL;
    Gnode *temp = graph[src];
    if(temp==NULL)
        graph[src] = new;
    else{
        while(temp->next)
            temp = temp->next;
        temp->next = new;
    }
    Gnode *new1 = (Gnode *)malloc(sizeof(Gnode));
    new1->vertex = src;
    new1->weight = weight;
    new1->dist = 100000000;
    new1->next = NULL;
    temp = graph[target];
    if(temp==NULL)
        graph[target] = new1;
    else{
        while(temp->next)
            temp = temp->next;
        temp->next = new1;
    }
}

void display(Gnode **graph, int vertices){
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        printf("%d --> ", i);
        while(temp!=NULL){
            printf("%d(%d)  ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void BellmanFord(Gnode **graph, int vertices, int src){
    int minDist[vertices];
    for(int i=0; i<vertices; i++)
        minDist[i] = 100000000;
    minDist[src] = 0;

    for(int i=0; i<vertices-1; i++){
        for(int j=0; j<vertices; j++){
            Gnode *ptr = graph[j];
            while(ptr){
                if(ptr->weight + minDist[j] < minDist[ptr->vertex])
                    minDist[ptr->vertex] = ptr->weight + minDist[j];
                ptr = ptr->next;
            }
        }
    }

    for(int j=0; j<vertices; j++){
        Gnode *ptr = graph[j];
        while(ptr){
                if(ptr->weight + minDist[j] < minDist[ptr->vertex]){
                    printf("Cycle with negative weight detected :(\n");
                    return;
                }
                ptr = ptr->next;
            }
    }

    for(int i=0; i<vertices; i++)
        printf("%d - %d\n", i, minDist[i]);
}

void main(){
    Gnode **graph = createGraph(5);
    addDirectedEdge(graph, 0, 1, -1);
    addDirectedEdge(graph, 0, 2, 4);
    addDirectedEdge(graph, 1, 2, 3);
    addDirectedEdge(graph, 1, 3, 2);
    addDirectedEdge(graph, 1, 4, 2);
    addDirectedEdge(graph, 3, 1, 1);
    addDirectedEdge(graph, 3, 2, 5);
    addDirectedEdge(graph, 4, 3, -3);
    
    display(graph, 5);
    printf("\nBellman Ford:\n");
    BellmanFord(graph, 5, 0);
}