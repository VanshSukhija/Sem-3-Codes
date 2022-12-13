#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define tab printf("\t")
#define enter printf("\n")

struct node{
    int leaf;
    int size;
    int arr[20];
    struct node * child[21];
};

struct pair{
    struct node * ptr;
    int index;
};

struct queue{
    struct node *ptr[100];
    int front;
    int end;
};

void create(struct queue *q) {
    for(int i=0; i<100;i++){
        q->ptr[i]=NULL;
    }
    q->front=q->end=0;
}

void insertqueue(struct queue *q, struct node * temp){
    q->ptr[q->end++]=temp;
}

struct node * popqueue(struct queue *q) {
    if(q->front>q->end){
        return NULL;
    }
    return q->ptr[q->front++];
}

struct node * frontqueue(struct queue *q) {
    if(q->front>q->end){
        return NULL;
    }
    return q->ptr[q->front];
}

void nullthem(struct node *temp){
    for(int i=0;i<=temp->size;i++){
        temp->child[i]=NULL;
    }
}

struct pair * searchbtree(struct node * root, int key) {
    struct pair * p = (struct pair*)malloc(sizeof(struct pair));
    if(root==NULL){
        return NULL;
    }
    else{
        int i;
        for(i=0; i<root->size; i++ ) {
            if(root->arr[i]==key){
                p->index=i;
                p->ptr=root;
                return p;
            }
            else if(root->arr[i]>key){
                break;
            }
        }
        return searchbtree(root->child[i],key);
    }
}

void levelorder(struct node *root) {
    struct queue q;
    create(&q);
    insertqueue(&q,root);
    while(q.front<q.end){
        int front=q.front, end=q.end;
        for(int j=front; j<end;j++){
            struct node * temp = popqueue(&q);
            for(int i=0; i<temp->size; i++ ){
                printf("%d ",temp->arr[i]);
            }
            tab;
            if(temp->leaf==0){
               for(int i=0; i<=temp->size; i++ ){
                   insertqueue(&q,temp->child[i]);
                } 
            }
        } 
        enter;
    }
}

int main() {
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root->leaf=0;
    root->size=2;
    root->arr[0]=500;
    root->arr[1]=1000;
    root->child[0]=(struct node *)malloc(sizeof(struct node));
    root->child[1]=(struct node *)malloc(sizeof(struct node));
    root->child[2]=(struct node *)malloc(sizeof(struct node));
    root->child[0]->leaf=1;
    root->child[0]->size=2;
    root->child[0]->arr[0]=100;
    root->child[0]->arr[1]=300;
    nullthem(root->child[0]);
    root->child[1]->leaf=1;
    root->child[1]->size=3;
    root->child[1]->arr[0]=600;
    root->child[1]->arr[1]=700;
    root->child[1]->arr[2]=900;
    nullthem(root->child[1]);
    root->child[2]->leaf=1;
    root->child[2]->size=1;
    root->child[2]->arr[0]=1500;
    nullthem(root->child[2]);

    levelorder(root);

    int a;
    do{
        scanf("%d",&a);
        struct pair *ptr = searchbtree(root,a);
        if(ptr==NULL){
            printf("NO key found\n");
        }
        else {
            printf("key found at index %d",ptr->index);
        }
    } while (a!=(-1));
    
    return 0;
}