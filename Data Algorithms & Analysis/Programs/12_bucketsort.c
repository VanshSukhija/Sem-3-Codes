#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
static int p=0;
void Insertsort(float arr[p][3], int n, int p){
    for (int i = 0; i < n; i++){
        float x = arr[p][i];
        int j = i - 1;
        while (j >= 0 && arr[p][j] >= x){
            arr[p][j + 1] = arr[p][j];
            j--;
        }
        arr[p][j + 1] = x;
    }
    p++;
}

void BucketSort(float arr[], int n)
{
    float bucket[n][3];
    int size[n];
    for (int i = 0; i < n; i++){
        size[i] = 0;
    }
    for (int i = 0; i < n; i++){
        bucket[(int)(arr[i] * n)][size[(int)(arr[i] * n)]] = arr[i];
        size[(int)(arr[i] * n)]++;
    }
    for (int i = 0; i < n; i++){
        Insertsort(bucket, size[i], i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < size[i]; j++){
            printf("%f ", bucket[i][j]);
        }
    }
    while (p!=0){
        p--;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++){
        scanf("%f", arr + i);
    }
    printf("Array: ");
    BucketSort(arr, n);
    return 0;
}