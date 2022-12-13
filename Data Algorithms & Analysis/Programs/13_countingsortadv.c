#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(int arr[], int n){
    printf("Array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void countingsort(int arr[], int n){ // for elements ranging in [x, y]
    int min=0, max=0, size;
    for(int i=0; i<n; i++){
        if(arr[i]<arr[min])
            min = i;
        if(arr[i]>arr[max])
            max = i;
    }
    size = arr[max] - arr[min];
    int freq[size+1], sorted[n];
    for(int i=0; i<=size; i++)
        freq[i]=0;
    for(int i=0; i<n; i++)
        freq[arr[i]-arr[min]]++;
    for(int i=1; i<=size; i++)
        freq[i] += freq[i-1];
    for(int i=0; i<=size; i++)
        freq[i]--;
    for(int i=n-1; i>=0; i--)
        sorted[freq[arr[i]-arr[min]]--] = arr[i];
    for(int i=0; i<n; i++)
        arr[i] = sorted[i];
} // Time Complexity: O(N+k)... k = max-min+1 // Space Complexity: Theta(max-min+1)

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    display(arr, n);
    countingsort(arr, n);
    display(arr, n);
}