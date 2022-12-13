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

void countingsort(int arr[], int n, int pwr){
    int freq[10], sorted[n];
    for(int i=0; i<10; i++)
        freq[i]=0;
    for(int i=0; i<n; i++)
        freq[(arr[i]/pwr)%10]++;
    for(int i=1; i<10; i++)
        freq[i] += freq[i-1];
    for(int i=0; i<10; i++)
        freq[i]--;
    for(int i=n-1; i>=0; i--)
        sorted[freq[(arr[i]/pwr)%10]--] = arr[i];
    for(int i=0; i<n; i++)
        arr[i] = sorted[i];
}

void radixsort(int arr[], int n){
    int pos_size=0, neg_size=0;
    for(int i=0; i<n; i++){
        if(arr[i]>=0)
            pos_size++;
        else
            neg_size++;
    }
    int pos[pos_size], neg[neg_size];
    for(int i=0, j=0, k=0; i<n; i++){
        if(arr[i]>=0)
            pos[j++] = arr[i];
        else
            neg[k++] = -1*arr[i];
    }
    int maxpos = pos[0], maxneg = neg[0];
    for(int i=0; i<pos_size; i++)
        if(pos[i]>maxpos)
            maxpos = pos[i];
    for(int i=0; i<neg_size; i++)
        if(neg[i]>maxneg)
            maxneg = neg[i];
    for(int i=1; maxpos/i > 0; i*=10)
        countingsort(pos, pos_size, i);
    for(int i=1; maxneg/i > 0; i*=10)
        countingsort(neg, neg_size, i);
    int i=0;
    for(int j=neg_size-1; j>=0; j--)
        arr[i++] = -1*neg[j];
    for(int j=0; j<pos_size; j++)
        arr[i++] = pos[j];
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    display(arr, n);
    radixsort(arr, n);
    display(arr, n);
}