#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int isSafe(int **arr, int row, int col, int n){
    for(int i=0; i<n; i++)
        if(arr[row][i]==1 || arr[i][col]==1)
            return 0;

    int i=row, j=col;
    while(i>=0 && j>=0){
        if(arr[i][j]==1)
            return 0;
        i--, j--;
    }

    i=row, j=col;
    while(i>=0 && j<n){
        if(arr[i][j]==1)
            return 0;
        i--, j++;
    }
    return 1;
}

int NQueen(int **arr, int row, int n){
    if(row==n)
        return 1;
    
    for(int i=0; i<n; i++){
        if(isSafe(arr, row, i, n)){
            arr[row][i] = 1;
            if(NQueen(arr, row+1, n))
                return 1;
            arr[row][i] = 0;
        }
    }
    return 0;
}

void main(){
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    int **arr = (int **)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        arr[i] = (int *)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++)
            arr[i][j] = 0;
    }
    if(NQueen(arr, 0, n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
    }
    else
        printf("No Solution found :(\n");
}