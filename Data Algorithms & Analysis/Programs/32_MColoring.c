#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int **createGraph(int n){
    int **graph = (int **)malloc(sizeof(int *)*n);
    for(int i=0; i<n; i++){
        graph[i] = (int *)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++)
            graph[i][j] = 0;
    }

    for(int i=0; i<n; i++){
        printf("Enter vertices of Node %d: ", i);
        int tar;
        while(1){
            scanf("%d", &tar);
            if(tar==-1)
                break;
            graph[i][tar] = graph[tar][i] = 1;
        }
    }
    return graph;
}

int isSafe(int **graph, int vertices, int m, int colors[], int index){
    for(int i=0; i<vertices; i++){
        if(i!=index && graph[index][i]==1){
            if(colors[i]==colors[index])
                return 0;
        }
    }
    return 1;
}

int MColor(int **graph, int vertices, int m, int colors[], int index){
    if(index==vertices)
        return 1;
    for(int i=1; i<=m; i++){
        colors[index] = i;
        if(isSafe(graph, vertices, m, colors, index)){
            if(MColor(graph, vertices, m, colors, index+1))
                return 1;
        }
    }
    return 0;
}

void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int **graph = createGraph(n);
    int colors[n];
    for(int i=0; i<n; i++)
        colors[i] = -1;
    int m;
    printf("Enter the value of M: ");
    scanf("%d", &m);
    if(MColor(graph, n, m, colors, 0)){
        for(int i=0; i<n; i++)
            printf("%d - %d\n", i, colors[i]);
    }
    else{
        printf("Solution not found :(\n");
    }
}

/*
4
1 2 3 -1
2 -1
3 -1
-1
3
*/

/*
10
1 2 3 -1
4 8 -1
6 7 -1
5 9 -1
5 7 -1
6 -1
8 -1
9 -1
9 -1
-1
3
*/