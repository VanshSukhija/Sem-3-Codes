#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex, weight;
    struct Gnode *next;
}Gnode;

typedef struct minHeapNode{
    int src, target, weight;
}HeapNode;

Gnode **createGraph(int vertices){
    Gnode **graph = (Gnode **)malloc(sizeof(Gnode *)*vertices);
    for(int i=0; i<vertices; i++)
        graph[i] = NULL;
    return graph;
}

void addUndirectedEdge(Gnode **graph, int src, int target, int weight){
    Gnode *new = (Gnode *)malloc(sizeof(Gnode));
    new->vertex = target;
    new->weight = weight;
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

void swap(HeapNode *a, HeapNode *b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode arr[], int size, int node){
    int smallest = node;
    if(2*node <= size && arr[2*node].weight < arr[smallest].weight)
        smallest = 2*node;
    if(2*node+1 <= size && arr[2*node+1].weight < arr[smallest].weight)
        smallest = 2*node+1;
    if(smallest!=node){
        swap(&arr[smallest], &arr[node]);
        minHeapify(arr, size, smallest);
    }
}

HeapNode extractMin(HeapNode arr[], int *size){
    HeapNode res = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    minHeapify(arr, *size, 1);
    return res;
}

void decreaseKey(HeapNode arr[], int size, int node, int weight){
    while(node>1 && arr[node].weight < arr[node/2].weight){
        swap(&arr[node], &arr[node/2]);
        node = node/2;
    }
}

void insert(HeapNode arr[], int *size, HeapNode new){
    (*size)++;
    arr[*size] = new;
    decreaseKey(arr, *size, *size, new.weight);
}

Gnode **PrimsMST(Gnode **graph, int vertices, int start){
    Gnode **prims = createGraph(vertices);
    HeapNode pqueue[100000];
    int size=0;
    int visited[vertices];
    for(int i=0; i<vertices; i++)
        visited[i] = 0;
    visited[start] = 1;
    Gnode *temp;
    for(int i=0; i<vertices; i++){
        temp = graph[start];
        while(temp){
            if(!visited[temp->vertex]){
                HeapNode new;
                new.src = start;
                new.target = temp->vertex;
                new.weight = temp->weight;
                insert(pqueue, &size, new);
            }
            temp = temp->next;
        }
        HeapNode min;
        while(size>0){
            min = extractMin(pqueue, &size);
            if(!visited[min.target]){
                visited[min.target] = 1;
                break;
            }
        }
        if(size)
            addUndirectedEdge(prims, min.src, min.target, min.weight);
        start = min.target;
    }
    return prims;
}

void display(Gnode **graph, int vertices){
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        printf("%d --> ", i);
        while(temp!=NULL){
            printf("%d(%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    Gnode **graph = createGraph(6);
    addUndirectedEdge(graph, 0, 1, 2);
    addUndirectedEdge(graph, 0, 3, 1);
    addUndirectedEdge(graph, 0, 4, 4);
    addUndirectedEdge(graph, 1, 3, 3);
    addUndirectedEdge(graph, 1, 2, 3);
    addUndirectedEdge(graph, 1, 5, 7);
    addUndirectedEdge(graph, 2, 3, 5);
    addUndirectedEdge(graph, 2, 5, 8);
    addUndirectedEdge(graph, 3, 4, 9);
    display(graph, 6);
    
    printf("\nPrims\n");
    Gnode **prims = PrimsMST(graph, 6, 0);
    display(prims, 6);
}