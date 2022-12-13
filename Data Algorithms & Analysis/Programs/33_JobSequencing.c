#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Job{
    int id, profit, dead;
}Job;

int min(int a, int b){
    return (a < b) ? a : b;
}

void JobSequencing(Job arr[], int n){
    for(int i=1; i<n; i++){
        Job key = arr[i];
        int j = i-1;
        while(j>=0 && key.profit > arr[j].profit){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    // for(int i=0; i<n; i++)
    //     printf("%d - %d - %d\n", arr[i].id, arr[i].dead, arr[i].profit);
    int result[n], slot[n];
    for(int i=0; i<n; i++)
        slot[i] = 1;
    for(int i=0; i<n; i++){
        for(int j=min(n, arr[i].dead)-1; j>=0; j--){
            if(slot[j]){
                slot[j] = 0;
                result[j] = i;
                break;
            }
        }
    }
    printf("\nJobs are scheduled as: ");
    for(int i=0; i<n; i++)
        if(!slot[i])
            printf("\n%d - %d", arr[result[i]].id, arr[result[i]].profit);
    printf("\n");
}

void main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job arr[n];
    printf("Enter the Deadline and profit of the jobs:\n");
    for(int i=0; i<n; i++){
        scanf("%d%d", &arr[i].dead, &arr[i].profit);
        arr[i].id = i;
    }
    JobSequencing(arr, n);
}
/* 
5
2 100
1 19
2 27
1 25
3 15
 */