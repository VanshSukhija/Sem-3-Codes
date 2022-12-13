#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex;
    struct Gnode *next;
}Gnode;

typedef struct Stack{
    int top, size, *ptr;
}Stack;

Stack createStack(int size){
    Stack s;
    s.top = -1;
    s.ptr = (int *)malloc(sizeof(int)*size);
    s.size = size;
    return s;
}

Stack st;

void push(Stack *st, int data){
    if(st->top<st->size)
        st->ptr[++st->top] = data;
}

int pop(Stack *st){
    int data = -1;
    if(st->top>=0)
        data = st->ptr[st->top--];
    return data;
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

void DFSvisit(Gnode **graph, int vertices, int visited[], int parent[], int node){
    visited[node] = 1;
    Gnode *temp = graph[node];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            parent[temp->vertex]=node;
            DFSvisit(graph, vertices, visited, parent, temp->vertex);
        }
        temp = temp->next;
    }
    push(&st, node);
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

void DFSvisit2(Gnode **graph, int vertices, int visited[], int parent[], int node){
    visited[node] = 1;
    Gnode *temp = graph[node];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            parent[temp->vertex]=node;
            DFSvisit2(graph, vertices, visited, parent, temp->vertex);
        }
        temp = temp->next;
    }
    printf("%d ", node);
}

Gnode **transpose(Gnode **graph, int vertices){
    Gnode **tgraph = (Gnode **)malloc(vertices*sizeof(Gnode *));
    for(int i=0; i<vertices; i++)
        tgraph[i] = NULL;
    for(int i=0; i<vertices; i++){
        Gnode *temp = graph[i];
        while(temp){
            insert(&tgraph[temp->vertex], i);
            temp = temp->next;
        }
    }
    return tgraph;
}

void SCC(Gnode **graph, int vertices){
    DFS(graph, vertices);
    Gnode **tgraph = transpose(graph, vertices);
    int visited[vertices], parent[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
        parent[i]=-1;
    }

    printf("Stack: ");
    for(int i=st.top; i>=0; i--)
        printf("%d ", st.ptr[i]);
    printf("\n");

    while(st.top>=0){
        int i = pop(&st);
        if(!visited[i]){
            DFSvisit2(tgraph, vertices, visited, parent, i);
            printf("\n");
        }
    }
}

void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    st = createStack(n);
    Gnode **graph = createGraph(n);
    display(graph, n);
    printf("\n");
    Gnode **trans = transpose(graph, n);
    display(trans, n);
    printf("\n");
    SCC(graph, n);
}

// 8
// 1 -1
// 2 -1
// 3 4 -1
// 0 -1
// 5 -1
// 6 -1
// 4 7 -1
// -1