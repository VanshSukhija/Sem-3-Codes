#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int isSafe(int **graph, int v, int path[], int i, int pos){
    if(graph[path[pos-1]][i]==0)
        return 0;

    for(int j=0; j<pos; j++)
        if(path[j]==i)
            return 0;
    return 1;
}

int Hamiltonian(int **graph, int v, int path[], int pos){
    if(pos==v){
        if(graph[path[pos-1]][path[0]])
            return 1;
        else
            return 0;
    }

    for(int i=1; i<v; i++){
        if(isSafe(graph, v, path, i, pos)){
            path[pos] = i;
            if(Hamiltonian(graph, v, path, pos+1))
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void main(){
    int v=5;
    int **graph = (int **)malloc(sizeof(int *)*v);
    for(int i=0; i<v; i++){
        graph[i] = (int *)malloc(sizeof(int)*v);
        for(int j=0; j<v; j++)
            graph[i][j] = 0;
    }
    graph[0][1] = graph[1][0] = 1;
    graph[0][3] = graph[3][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    int path[v], pos=1;
    for(int i=0; i<v; i++)
        path[i] = -1;
    path[0] = 0;

    if(Hamiltonian(graph, v, path, pos)){
        printf("Hamiltonian Path: ");
        for(int i=0; i<v; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    else
        printf("Solution does not exists :(");
}