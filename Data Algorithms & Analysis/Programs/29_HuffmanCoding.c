#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Node{
    struct Node *left, *right;
    int freq;
    char sym, code[100];
}Node;

void swap(Node **a, Node **b){
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node *arr[], int size, int node){
    int smallest = node;
    if(2*node <= size && (*arr[2*node]).freq < (*arr[smallest]).freq)
        smallest = 2*node;
    if(2*node+1 <= size && (*arr[2*node+1]).freq < (*arr[smallest]).freq)
        smallest = 2*node+1;
    if(smallest!=node){
        swap(&arr[smallest], &arr[node]);
        minHeapify(arr, size, smallest);
    }
}

Node *extractMin(Node *arr[], int *size){
    Node *res = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    minHeapify(arr, *size, 1);
    return res;
}

void decreaseKey(Node *arr[], int size, int node){
    while(node>1 && (*arr[node]).freq < (*arr[node/2]).freq){
        swap(&arr[node], &arr[node/2]);
        node = node/2;
    }
}

void insert(Node *arr[], int *size, Node *new){
    (*size)++;
    arr[*size] = new;
    decreaseKey(arr, *size, *size);
}

void storeCodes(Node *root, Node *arr[], int size){
    if(root->left==NULL && root->right==NULL){
        for(int i=0; i<size; i++){
            if(arr[i]->sym == root->sym){
                strcpy(arr[i]->code, root->code);
                return;
            }
        }
    }
    if(root->left){
        char temp[100];
        strcpy(temp, root->code);
        strcat(temp, "0");
        strcpy(root->left->code, temp);
        storeCodes(root->left, arr, size);
    }
    if(root->right){
        char temp[100];
        strcpy(temp, root->code);
        strcat(temp, "1");
        strcpy(root->right->code, temp);
        storeCodes(root->right, arr, size);
    }
}

void displayQueue(Node *pq[], int size, int pqsize){
    printf("Priority Queue: ");
    for(int i=pqsize; i>0; i--)
        printf("%d ", pq[i]->freq);
    printf("\n");
}

void Huffman(Node *arr[], int size){
    Node *pqueue[size+1];
    int pqsize=0;
    for(int i=0; i<size; i++){
        Node *new = (Node *)malloc(sizeof(Node));
        new->freq = arr[i]->freq;
        new->left = new->right = NULL;
        new->sym = arr[i]->sym;
        insert(pqueue, &pqsize, new);
    }
    for(int i=0; i<size-1; i++){
        Node *min1 = extractMin(pqueue, &pqsize);
        Node *min2 = extractMin(pqueue, &pqsize);
        Node *new = (Node *)malloc(sizeof(Node));
        new->freq = min1->freq + min2->freq;
        new->left = min1;
        new->right = min2;
        new->sym = 0;
        insert(pqueue, &pqsize, new);
    }
    Node *root = extractMin(pqueue, &pqsize);
    strcpy(root->code, "");
    storeCodes(root, arr, size);
}

void printCodes(Node *arr[], int size){
    printf("Codes:\n");
    for(int i=0; i<size; i++)
        printf("%c: %s\n", arr[i]->sym, arr[i]->code);
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        printf("%c - %d\n", root->sym, root->freq);
        inorder(root->right);
    }
}

void main(){
    int n;
    printf("Enter number of symbols: ");
    scanf("%d", &n);
    Node *arr[n];
    printf("Enter symbol and frequency:\n");
    for(int i=0; i<n; i++){
        fflush(stdin);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->left = newNode->right = NULL;
        scanf("%c%d", &newNode->sym, &newNode->freq);
        arr[i] = newNode;
    }
    Huffman(arr, n);
    printCodes(arr, n);
}

/* 
6
a 5
b 9
c 12
d 13
e 16
f 45
*/