#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define INF 100000000

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

void FloydWarshall(Gnode **graph, int vertices){
    int adj[vertices][vertices];
    for(int i=0; i<vertices; i++)
        for(int j=0; j<vertices; j++)
            adj[i][j] = INF;
    
    for(int i=0; i<vertices; i++)
        adj[i][i] = 0;
    
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        while(temp){
            adj[i][temp->vertex] = temp->weight;
            temp = temp->next;
        }
    }

    for(int k=0; k<vertices; k++){
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                if(adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            if(adj[i][j]==INF)
                printf("INF ");
            else
                printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void main(){
    Gnode **graph = createGraph(4);
    addDirectedEdge(graph, 0, 1, 5);
    addDirectedEdge(graph, 0, 3, 10);
    addDirectedEdge(graph, 1, 2, 3);
    addDirectedEdge(graph, 2, 3, 1);
    
    display(graph, 4);
    printf("\nFloyd Warshall:\n");
    FloydWarshall(graph, 4);
}