#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(int arr[], int size){
    printf("Array: ");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){ // Time Complexity: O(N)
    int pivot = arr[end-1];
    int i = start-1, j = start;
    while(j<end){
        if(arr[j]<=pivot) // equality for stability
            swap(&arr[++i], &arr[j]);
        j++;
    }
    swap(&arr[++i], &arr[j-1]);
    return i;
}

void quicksort(int arr[], int start, int end){ // Time Complexity: O(Nlog(N))
    if(start<end){
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot);
        quicksort(arr, pivot+1, end);
    }
} // Recurrence: T(n) = T(k) + T(n-k) + n  ~ T(n) = 2T(n/2) + n

void main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements in the array: ");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);
    display(arr, size);
    quicksort(arr, 0, size);
    display(arr, size);
}