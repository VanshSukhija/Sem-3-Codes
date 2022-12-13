#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct process{
    int id, key;
}process;

void swap(process *a, process *b){
    process temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(process arr[], int size, int node){ // compares 3 nodes (root, left child, right child) and swaps maximum among them with the root
    int max = node;
    if(2*node <= size && arr[2*node].key > arr[max].key)
        max = 2*node;
    if(2*node+1 <= size && arr[2*node+1].key > arr[max].key)
        max = 2*node+1;
    if(max != node){
        swap(&arr[node], &arr[max]);
        heapify(arr, size, max);
    }
}

process find_max(process arr[], int size){
    return arr[1];
}

process extract_max(process arr[], int *size){
    process temp = arr[1];
    arr[1] = arr[(*size)];
    (*size)--;
    heapify(arr, (*size), 1);
    return temp;
}

void increase_key(process arr[], int size, int id, int key){
    int i;
    for(i=1; i<=size; i++){
        if(arr[i].id == id)
            break;
    }
    if(arr[i].key >= key)
        return;
    else{
        arr[i].key = key;
        while(i>1 && arr[i/2].key<key){
            swap(&arr[i], &arr[i/2]);
            i /= 2;
        }
    }
}

void insert(process arr[], int *size, process newp){
    (*size)++;
    arr[(*size)] = newp;
    arr[(*size)].key = -2147483648;
    increase_key(arr, *size, *size, newp.key);
}

void display(process arr[], int size){
    printf("Processes:\n");
    for(int i=1; i<=size; i++)
        printf("%d %d\n", arr[i].id, arr[i].key);
}

void main(){
    int size=1;
    process arr[size+1];
    arr[1].id = 1, arr[1].key = -21474836;
    int choice;
    do{
        printf("Enter '1' to insert process\n");
        printf("Enter '2' to find max\n");
        printf("Enter '3' to extract max\n");
        printf("Enter '4' to increase key\n");
        printf("Enter '5' to display processes\n");
        int num;
        scanf("%d", &num);
        switch(num){
            case 1:
                process newp;
                printf("Enter id: ");
                scanf("%d", &newp.id);
                printf("Enter key: ");
                scanf("%d", &newp.key);
                insert(arr, &size, newp);
                break;
            case 2:
                printf("%d", find_max(arr, size));
                break;
            case 3:
                process max = extract_max(arr, &size);
                printf("%d %d\n", max.id, max.key);
                break;
            case 4:
                int id, key;
                printf("Enter id to increase: ");
                scanf("%d", &id);
                printf("Enter new key: ");
                scanf("%d", &key);
                increase_key(arr, size, id, key);
                break;
            case 5:
                display(arr, size);
                break;
            default:
                printf("Input is invalid\n");
                break;
        }
        printf("Enter '1' to do another operation or '0' to exit: ");
        scanf("%d", choice);
    }while(choice==1);
}