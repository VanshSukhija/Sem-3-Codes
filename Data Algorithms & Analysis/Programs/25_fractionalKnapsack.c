#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Item{
    int weight, value;
    float ratio;
}Item;

void insertionsort(Item arr[], int start, int end){
    for(int i=start+1; i<end; i++){
        Item key = arr[i];
        int j = i-1;
        while(j>=start && arr[j].ratio>key.ratio){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int FracKnapsack(Item arr[], int size, int bagSize){
    insertionsort(arr, 0, size);
    int sum=0, ptr=size-1;
    while(ptr>=0 && bagSize>0){
        if(arr[ptr].weight <= bagSize){
            sum += arr[ptr].value;
            bagSize -= arr[ptr].weight;
            ptr--;
        }
        else{
            sum += bagSize*arr[ptr].ratio;
            bagSize = 0;
        }
    }
    return sum;
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
    printf("Maximum value the theif can fetch: %d\n", FracKnapsack(arr, size, bagSize));
}

/* 
3
60 10
100 20
120 30
50 
*/