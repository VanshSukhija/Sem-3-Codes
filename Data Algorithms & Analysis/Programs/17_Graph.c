#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex;
    struct Gnode *next;
}Gnode;

typedef struct Queue{
    int size, front, rear;
    int *ptr;
}Queue;

void enqueue(Queue *q, int data){
    if(q->rear!=-1 && q->front>q->rear)
        printf("Queue is full\n");
    else{
        q->rear = (q->rear+1)%(q->size);
        q->ptr[q->rear] = data;
    }
}

int dequeue(Queue *q){
    int res = -1;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else{
        q->front = (q->front+1)%(q->size);
        res = q->ptr[q->front];
    }
    return res;
}

int isEmpty(Queue q){
    if(q.front==q.rear)
        return 1;
    else
        return 0;
}

void insert(Gnode **ptr, int vertex){
    Gnode *new = (Gnode *)malloc(sizeof(Gnode));
    new->vertex = vertex;
    new->next = NULL;
    if(*ptr == NULL)
        (*ptr) = new;
    else{
        Gnode *temp = (*ptr);
        while(temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

Gnode **createGraph(int num){
    Gnode **ptr = (Gnode **)malloc(num*sizeof(Gnode *));
    for(int i=0; i<num; i++)
        ptr[i] = NULL;
    for(int i=0; i<num; i++){
        printf("Enter -1 to stop\n");
        printf("Enter vertices connected to vertex %d: ", i);
        int temp;
        scanf("%d", &temp);
        while(temp!=-1){
            insert(&ptr[i], temp);
            scanf("%d", &temp);
        }
    }
    return ptr;
}

void display(Gnode **graph, int vertices){
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        printf("%d --> ", i);
        while(temp!=NULL){
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int highestOutEdges(Gnode **graph, int vertices){
    int max=0, edges=0;
    for(int i=0; i<vertices; i++){
        int count=0;
        Gnode *temp = graph[i];
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count > edges){
            max = i;
            edges = count;
        }
    }
    return max;
}

int highestInEdges(Gnode **graph, int vertices){
    int count[vertices];
    for(int i=0; i<vertices; i++)
        count[i] = 0;
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        while(temp!=NULL){
            count[temp->vertex]++;
            temp = temp->next;
        }
    }
    int max=0, edges=0;
    for(int i=0; i<vertices; i++){
        if(count[i] > edges){
            edges = count[i];
            max = i;
        }
    }
    return max;
}

void DFSvisit(Gnode **graph, int vertices, int visited[], int parent[], int node){
    visited[node] = 1;
    printf("%d ", node);
    Gnode *temp = graph[node];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            parent[temp->vertex]=node;
            DFSvisit(graph, vertices, visited, parent, temp->vertex);
        }
        temp = temp->next;
    }
}

void DFS(Gnode **graph, int vertices){
    int visited[vertices], parent[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
        parent[i]=-1;
    }
    for(int i=0; i<vertices; i++){
        if(!visited[i])
            DFSvisit(graph, vertices, visited, parent, i);
    }
}

void BFS(Gnode **graph, int vertices, int start){
    Queue qu;
    qu.size = vertices;
    qu.front = qu.rear = -1;
    qu.ptr = (int *)malloc(sizeof(int)*qu.size);
    int visited[vertices];
    for(int i=0; i<vertices; i++)
        visited[i] = 0;
    enqueue(&qu, start);
    visited[start] = 1;
    while(!isEmpty(qu)){
        int index = dequeue(&qu);
        Gnode *temp = graph[index];
        printf("%d ", index);
        while(temp!=NULL){
            if(!visited[temp->vertex]){
                enqueue(&qu, temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    Gnode **graph = createGraph(n);
    display(graph, n);
    printf("Node with highest number of outgoing edges: %d\n", highestOutEdges(graph, n));
    printf("Node with highest number of incoming edges: %d\n", highestInEdges(graph, n));
    DFS(graph, n);
    printf("\n");
    BFS(graph, n, 0);
}
// Graph g(4);
// g.addEdge(0, 1);
// g.addEdge(0, 2);
// g.addEdge(1, 2);
// g.addEdge(2, 0);
// g.addEdge(2, 3);
// g.addEdge(3, 3);

// 4
// 1 2 -1
// 2 -1
// 0 3 -1
// 3 -1