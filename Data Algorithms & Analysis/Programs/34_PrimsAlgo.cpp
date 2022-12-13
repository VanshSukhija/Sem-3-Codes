#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct gnode
{
    int vertex;
    int weight;
    struct gnode *next;
} gnode;
typedef struct vertex_node
{
    int parent;
    int inPQ;
    int indexinPQ;
    gnode *alptr;
} vertex_node;
vertex_node vertex[51];
int n;
typedef struct PQnode
{
    int ver;
    int key;
} PQnode;
int PQsize = 0;
void swap(PQnode *a, PQnode *b)
{
    PQnode temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(vertex_node *a, vertex_node *b)
{
    vertex_node temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void minheapify(int i, PQnode prique[], int a)
{
    int lci = 2 * i;
    int rci = 2 * i + 1;
    int smallest = i;
    if (lci <= a && prique[lci].key < prique[smallest].key)
    {
        smallest = lci;
    }
    if (rci <= a && prique[rci].key < prique[smallest].key)
    {
        smallest = rci;
    }

    if (smallest != i)
    {
        PQnode temp = prique[i];
        prique[i] = prique[smallest];
        prique[smallest] = temp;

        vertex[prique[i].ver].indexinPQ = i;
        vertex[prique[smallest].ver].indexinPQ = smallest;
        minheapify(smallest, prique, a);
    }
    else
    {
        return;
    }
}
PQnode extract_min(PQnode prique[])
{
    if (PQsize < 1)
    {
        printf("underflow");
    }
    PQnode temp = prique[1];
    prique[1] = prique[PQsize];
    prique[PQsize] = temp;

    vertex[prique[1].ver].indexinPQ = 1;
    vertex[prique[PQsize].ver].indexinPQ = PQsize;
    minheapify(1, prique, --PQsize);
    return temp;
}
void decrease_key(PQnode prique[], int index, int key)
{
    if (index > PQsize)
    {
        printf("invalid index");
        return;
    }
    if (key > prique[index].key)
    {
        return;
    }
    prique[index].key = key;
    while (index > 1)
    {
        int parent = index / 2;
        if (prique[parent].key > prique[index].key)
        {
            PQnode temp = prique[parent];
            prique[parent] = prique[index];
            prique[index] = temp;
            vertex[prique[parent].ver].indexinPQ = parent;
            vertex[prique[index].ver].indexinPQ = index;
            index = parent;
        }
        else
        {
            break;
        }
    }
}
void insert(int i, int adj)
{
    int w;
    scanf("%d", &w);
    gnode *temp = (gnode *)malloc(sizeof(gnode));
    temp->next = NULL;
    temp->vertex = adj;
    temp->weight = w;
    if (vertex[i].alptr == NULL)
    {
        vertex[i].alptr = temp;
    }
    else
    {
        temp->next = vertex[i].alptr;
        vertex[i].alptr = temp;
    }
}
void readgraph()
{
    for (int i = 1; i <= n; i++)
    {
        vertex[i].alptr = NULL;
    }
    printf("Enter -1 for stop entering edges\n");
    for (int i = 1; i <= n; i++)
    {
        // printf("Enter edges and weight for vertex %d\n", i);
        do
        {
            int adj;
            scanf("%d", &adj);
            if (adj == -1)
            {
                break;
            }
            insert(i, adj);
        } while (1);
    }
}
void display()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", i);
        gnode *temp = vertex[i].alptr;
        while (temp != NULL)
        {
            printf("->%d[%d]", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}
void INSERT_KEY(PQnode PQ[], int vertex, int key)
{
    PQsize++;
    PQ[PQsize].key = key;
    PQ[PQsize].ver = vertex;
    for (int i = PQsize / 2; i > 0; i--)
    {
        minheapify(i, PQ, PQsize);
    }
}
void prim(int src, PQnode prique[])
{
    for (int i = 1; i <= n; i++)
    {
        vertex[i].parent = -1;
        vertex[i].inPQ = 1;
        vertex[i].indexinPQ = i;
        INSERT_KEY(prique, i, INT_MAX);
    }
    decrease_key(prique, vertex[src].indexinPQ, 0);
    int minwt = 0;
    while (PQsize > 0)
    {
        PQnode u = extract_min(prique);
        // printf("%d ", u);
        vertex[u.ver].inPQ = 0;
        // printf("%d", u.ver);
        minwt += u.key;
        printf("[%d--%d]\n", u.ver, u.key);
        gnode *temp = vertex[u.ver].alptr;
        while (temp != NULL)
        {
            int v = temp->vertex;
            if (vertex[v].inPQ == 1 && temp->weight < prique[vertex[v].indexinPQ].key)
            {
                decrease_key(prique, vertex[v].indexinPQ, temp->weight);
                vertex[v].parent = u.ver;
            }
            temp = temp->next;
        }
    }
}
void dij(int src, PQnode prique[])
{
    for (int i = 1; i <= n; i++)
    {
        vertex[i].parent = -1;
        vertex[i].inPQ = 1;
        vertex[i].indexinPQ = i;
        INSERT_KEY(prique, i, INT_MAX);
    }
    decrease_key(prique, vertex[src].indexinPQ, 0);
    int minwt = 0;
    while (PQsize > 0)
    {
        PQnode u = extract_min(prique);
        // printf("%d ", u);
        vertex[u.ver].inPQ = 0;
        // printf("%d", u.ver);
        minwt += u.key;
        printf("[%d--%d]\n", u.ver, u.key);
        gnode *temp = vertex[u.ver].alptr;
        while (temp != NULL)
        {
            int v = temp->vertex;
            if (vertex[v].inPQ == 1 && temp->weight + prique[vertex[u.ver].indexinPQ].key < prique[vertex[v].indexinPQ].key)
            {
                decrease_key(prique, vertex[v].indexinPQ, temp->weight + prique[vertex[u.ver].indexinPQ].key);
                vertex[v].parent = u.ver;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    PQnode prique[51];
    printf("Enter the number of vertices\n");
    int a;
    scanf("%d", &a);
    n = a;
    readgraph();
    // display();
    prim(1, prique);
    dij(1, prique);

    // display();
}
// 2 2
// 7 1
// 8 11
// -1
// 2 1
// 3 3
// 7 5
// -1
// 2 3
// 4 5
// -1
// 3 5
// 5 7
// -1
// 4 7
// 6 2
// 10 4
// -1
// 5 2
// 10 8
// 7 9
// 8 4
// -1
// 2 5
// 1 1
// 6 9
// -1
// 6 4
// 1 11
// 9 6
// -1
// 8 6
// 10 5
// -1
// 6 8
// 5 4
// 9 5
// -1