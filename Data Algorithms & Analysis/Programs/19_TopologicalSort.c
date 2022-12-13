#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Gnode{
    int vertex;
    struct Gnode *next;
}Gnode;

typedef struct Stack{
    int size, top, *ptr;
}Stack;

void push(Stack *st, int data){
    if(st->top!=st->size)
        st->ptr[++st->top] = data;
    else
        printf("Stack is Full\n");
}

int pop(Stack *st){
    int x = 0;
    if(st->top!=-1)
        x = st->ptr[st->top--];
    else
        printf("Stack is Empty\n");
    return x;
}

void insert(Gnode **ptr, int vertex){
    Gnode *new = (Gnode *)malloc(sizeof(Gnode));
    new->vertex = vertex;
    new->next = (*ptr);
    (*ptr) = new;
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

void DFSvisit(Gnode **graph, int vertices, int visited[], int parent[], Stack *st, int node){
    Gnode *temp = graph[node];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            visited[temp->vertex]=1;
            parent[temp->vertex]=node;
            DFSvisit(graph, vertices, visited, parent, st, temp->vertex);
        }
        temp = temp->next;
    }
    push(st, node);
}

void DFSMain(Gnode **graph, int vertices){
    Stack st;
    st.top = -1;
    st.size = vertices;
    st.ptr = (int *)malloc(sizeof(int)*vertices);

    int visited[vertices], parent[vertices];
    for(int i=0; i<vertices; i++){
        visited[i]=0;
        parent[i]=-1;
    }
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            visited[i]=1;
            DFSvisit(graph, vertices, visited, parent, &st, i);
        }
    }

    while(st.top!=-1){
        printf("%d ", pop(&st));
    }
}

void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    Gnode **graph = createGraph(n);
    display(graph, n);
    DFSMain(graph, n);
    printf("\n");
}
// Sample Input :-
// 0 --> 
// 1 --> 
// 2 --> 3 
// 3 --> 1 
// 4 --> 1 0
// 5 --> 0 2