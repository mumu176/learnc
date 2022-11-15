#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 10
#define INFINITY 32768
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;

typedef char VertexData;

typedef struct arcnode
{
    int adj;
} ArcNode;
typedef struct adjmatrix
{
    VertexData vertex[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} AdjMatrix;

int LocateVertex(AdjMatrix *G, VertexData v)
{
    int j = false, k;
    for (k = 0; k < G->vexnum; k++)
    {
        if (G->vertex[k] == v)
        {
            j = k;
            break;
        }
    }
    return j;
}

void CreatDN(AdjMatrix *G)
{
    int i, j, k, weight;
    VertexData v1, v2;
    scanf("%d%d", &G->vexnum, &G->arcnum);
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;
    }
    for (i = 0; i < G->vexnum; i++)
    {
        setbuf(stdin, NULL);
        G->vertex[i] = getchar();
    }

    for (k = 0; k < G->arcnum; k++)
    {
        setbuf(stdin,NULL);
        scanf("%c %c %d", &v1, &v2, &weight);
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adj = weight;
    }
    G->kind = DN;
}

void DispDN(AdjMatrix *G)
{
    int i, j;
    printf("DN\t");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c\t", G->vertex[i]);
    }
    printf("\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c\t", G->vertex[i]);
        for (j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j].adj != INFINITY)
                printf("%d\t", G->arcs[i][j].adj);
            else
                printf("$\t");
        }
        printf("\n");
    }
}

int main()
{
    AdjMatrix G_point;
    CreatDN(&G_point);
    DispDN(&G_point);
    return 0;
}
