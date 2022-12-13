#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex, weight, dist;
    struct Gnode *next;
}Gnode;

typedef struct minHeapNode{
    int vertex, dist;
}minNode;

void swap(minNode *a, minNode *b){
    minNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(minNode arr[], int size, int node){
    int smallest = node;
    if(2*node <= size && arr[2*node].dist < arr[smallest].dist)
        smallest = 2*node;
    if(2*node+1 <= size && arr[2*node+1].dist < arr[smallest].dist)
        smallest = 2*node+1;
    if(smallest!=node){
        swap(&arr[smallest], &arr[node]);
        minHeapify(arr, size, smallest);
    }
}

minNode extractMin(minNode arr[], int *size){
    minNode res = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    minHeapify(arr, *size, 1);
    return res;
}

void decreaseKey(minNode arr[], int size, int node, int dist){
    while(node>1 && arr[node].dist < arr[node/2].dist){
        swap(&arr[node], &arr[node/2]);
        node = node/2;
    }
}

void insert(minNode arr[], int *size, minNode new){
    (*size)++;
    arr[*size] = new;
    decreaseKey(arr, *size, *size, new.dist);
}

Gnode **createGraph(int vertices){
    Gnode **graph = (Gnode **)malloc(sizeof(Gnode *)*vertices);
    for(int i=0; i<vertices; i++)
        graph[i] = NULL;
    return graph;
}

void addEdge(Gnode **graph, int src, int target, int weight){
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

void displayQueue(minNode pq[], int size){
    printf("Queue: ");
    for(int i=1; i<=size; i++)
        printf("%d(%d)  ", pq[i].vertex, pq[i].dist);
    printf("\n");
}

int *Dijkstra(Gnode **graph, int vertices, int src){
    int *minDist = (int *)malloc(sizeof(int)*vertices);
    for(int i=0; i<vertices; i++)
        minDist[i] = 100000000;
    minDist[src] = 0;
    minNode pqueue[100000];
    int size=0;

    minNode new;
    new.dist = 0;
    new.vertex = src;
    insert(pqueue, &size, new);
    while(size>0){
        displayQueue(pqueue, size);
        minNode temp = extractMin(pqueue, &size);
        Gnode *ptr = graph[temp.vertex];
        while(ptr){
            if(ptr->weight + minDist[temp.vertex] < ptr->dist){
                ptr->dist = ptr->weight + minDist[temp.vertex];
                new.dist = ptr->dist;
                new.vertex = ptr->vertex;
                insert(pqueue, &size, new);
                if(ptr->dist < minDist[ptr->vertex])
                    minDist[ptr->vertex] = ptr->dist;
            }
            ptr = ptr->next;
        }
    }
    return minDist;
}

void main(){
    Gnode **graph = createGraph(9);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    
    display(graph, 9);
    int *minDist = Dijkstra(graph, 9, 1);
    for(int i=0; i<9; i++)
        printf("%d - %d\n", i, minDist[i]);
}