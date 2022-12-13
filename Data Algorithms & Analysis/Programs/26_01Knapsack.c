#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Item{
    int weight, value;
    float ratio;
}Item;

int dp[100][1000];

int Knapsack(Item arr[], int index, int bagSize){
    if(index==0){
        if(arr[0].weight <= bagSize)
            return arr[0].value;
        else
            return 0;
    }

    int take = -1, nontake = -1;
    nontake = Knapsack(arr, index-1, bagSize);
    if(bagSize >= arr[index].weight)
        take = arr[index].value + Knapsack(arr, index-1, bagSize-arr[index].weight);
    
    if(take>nontake)
        return take;
    else
        return nontake;
}

int KnapsackMemo(Item arr[], int index, int bagSize){
    if(index==0){
        if(arr[0].weight <= bagSize)
            return dp[index][bagSize] = arr[0].value;
        else
            return dp[index][bagSize] = 0;
    }
    if(dp[index][bagSize] != -1)
        return dp[index][bagSize];

    int nontake = KnapsackMemo(arr, index-1, bagSize), take = -1;
    if(bagSize >= arr[index].weight)
        take = arr[index].value + KnapsackMemo(arr, index-1, bagSize-arr[index].weight);
    
    if(take>nontake)
        return dp[index][bagSize] = take;
    else
        return dp[index][bagSize] = nontake;
}

int KnapsackTab(Item arr[], int size, int bagSize){
    for(int i=0; i<=bagSize; i++){
        if(arr[0].weight <= bagSize)
            dp[0][i] = arr[0].value;
        else
            dp[0][i] = 0;
    }

    for(int i=1; i<=size; i++){
        for(int j=0; j<bagSize; j++){
            int nontake = dp[i-1][j], take = -1;
            if(j >= arr[i].weight)
                take = arr[i].value + dp[i-1][j-arr[i].weight];
            if(take>nontake)
                dp[i][j] = take;
            else
                dp[i][j] = nontake;
        }
    }
    return dp[size][bagSize];
}

void main(){
    int size;
    printf("Enter number of items: ");
    scanf("%d", &size);
    Item arr[size];
    printf("Enter value and weight of each item:\n");
    for(int i=0; i<size; i++){
        scanf("%d%d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value/arr[i].weight;
    }
    int bagSize;
    printf("Enter the size of bag: ");
    scanf("%d", &bagSize);

    for(int i=0; i<=size; i++)
        for(int j=0; j<=bagSize; j++)
            dp[i][j] = -1;
    printf("Maximum value the thief can fetch: %d\n", Knapsack(arr, size-1, bagSize));
    printf("Maximum value the thief can fetch: %d\n", KnapsackMemo(arr, size-1, bagSize));
    printf("Maximum value the thief can fetch: %d\n", KnapsackTab(arr, size-1, bagSize));
}

/* 
3
60 10
100 20
120 30
50 
*/

/*
3
30 3
50 4
60 5
8
*/