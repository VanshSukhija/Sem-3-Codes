#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Node{
    int data;
    struct Node *lchild, *rchild, *parent;
}Node;

Node *search(Node *root, int data){
    if(root==NULL){
        printf("Node not found\n");
    }
    else{
        if(data < root->data)
            root = search(root->lchild, data);
        else if(data > root->data)
            root = search(root->rchild, data);
    }
    return root;
}

Node *treemax(Node *root){
    if(root->rchild!=NULL)
        root = treemax(root->rchild);
    return root;
}

Node *treemin(Node *root){
    if(root->lchild!=NULL)
        root = treemin(root->lchild);
    return root;
}

Node *inSucc(Node *root){
    Node *curr = root;
    if(curr->rchild){
        curr = curr->rchild;
        while(curr->lchild!=NULL)
            curr = curr->lchild;
    }
    else{
        while(curr->parent!=NULL && curr->data > curr->parent->data)
            curr = curr->parent;
        if(curr->parent)
            curr = curr->parent;
    }
    return curr;
}

Node *inPre(Node *root){
    Node *curr = root;
    if(curr->lchild){
        curr = curr->lchild;
        while(curr->rchild!=NULL)
            curr = curr->rchild;
    }
    else{
        while(curr->parent!=NULL && curr->data < curr->parent->data)
            curr = curr->parent;
        if(curr->parent)
            curr = curr->parent;
    }
    return curr;
}

void insert(Node **root, int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->lchild = new->rchild = new->parent = NULL;
    if((*root)==NULL)
        (*root) = new;
    else{
        Node *curr = (*root), *prev = NULL;
        while(curr!=0){
            prev = curr;
            if(data > curr->data)
                curr = curr->rchild;
            else
                curr = curr->lchild;
        }
        if(data > prev->data)
            prev->rchild = new;
        else
            prev->lchild = new;
        new->parent = prev;
    }
}

void delete(Node **root, int data){
    Node *ptr = *root;
    while(ptr->data!=data){
        if(data > ptr->data)
            ptr = ptr->rchild;
        else
            ptr = ptr->lchild;
    }
    if(ptr->lchild==NULL && ptr->rchild==NULL){
        Node *temp = ptr->parent;
        if(ptr == temp->rchild)
            temp->rchild = NULL;
        else
            temp->lchild = NULL;
        free(ptr);
    }
    else if(ptr->lchild==NULL || ptr->rchild==NULL){
        if(ptr->lchild==NULL){
            Node *temp = inSucc(ptr);
            ptr->data = temp->data;
            delete(&ptr->rchild, ptr->data);
        }
        else{
            Node *temp = inPre(ptr);
            ptr->data = temp->data;
            delete(&ptr->lchild, ptr->data);
        }
    }
    else{
        Node *temp = inSucc(ptr);
        ptr->data = temp->data;
        delete(&ptr->rchild, ptr->data);
    }
}

void Inorder(Node *root){
    if(root!=NULL){
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
}

void main(){
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    Node *tree = NULL;
    printf("Enter elements in array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        insert(&tree, arr[i]);
    }
    printf("Inorder: ");
    Inorder(tree);
    printf("\n");

    printf("%d\n", search(tree, 4)->data);
    printf("%d\n", treemin(tree)->data);
    printf("%d\n", treemax(tree)->data);

    delete(&tree, 4);
    printf("Inorder: ");
    Inorder(tree);
    printf("\n");

    delete(&tree, 5);
    printf("Inorder: ");
    Inorder(tree);
    printf("\n");
}