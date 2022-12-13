#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Activity{
    int start, finish;
}Activity;

void InsertionSort(Activity arr[], int start, int end){
    for(int i=start+1; i<end; i++){
        Activity key = arr[i];
        int j = i-1;
        while(j>=start && arr[j].finish>key.finish){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int ActivitySelection(Activity arr[], int size){
    InsertionSort(arr, 0, size);
    int i=0, count=1;
    printf("\nAfter sorting\n");
    for(int i=0; i<size; i++)
        printf("%d - %d\n", arr[i].start, arr[i].finish);
    
    printf("\nActivity Selection\n");
    printf("%d - %d\n", arr[0].start, arr[0].finish);
    for(int j=1; j<size; j++){
        if(arr[j].start>=arr[i].finish){
            printf("%d - %d\n", arr[j].start, arr[j].finish);
            count++;
            i = j;
        }
    }
    return count;
}

void main(){
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    Activity arr[n];
    printf("Enter start and finish time of activities:\n");
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].start, &arr[i].finish);
    printf("Maximum number of tasks that can be done: %d\n", ActivitySelection(arr, n));
}

/*
6
3 4
1 2
5 9
5 7
8 9
0 6
*/