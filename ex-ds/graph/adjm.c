#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 10
#define INFINITY 32768
typedef enum//定义枚举图类型
{
    DG,//有向图
    DN,//有向网
    UDG,//无向图
    UDN//无向网
} GraphKind;

typedef char VertexData;//图顶点数据类型是字符

typedef struct arcnode//定义边结构
{
    int adj;
} ArcNode;
typedef struct adjmatrix//定义邻接矩阵结构
{
    VertexData vertex[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} AdjMatrix;

int LocateVertex(AdjMatrix *G, VertexData v)//通过元素寻找位置
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

void CreatDN(AdjMatrix *G)//创建有向网络
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
        setbuf(stdin, NULL);//清空输入缓冲区
        G->vertex[i] = getchar();
    }

    for (k = 0; k < G->arcnum; k++)
    {
        setbuf(stdin,NULL);//清空输入缓冲区
        scanf("%c %c %d", &v1, &v2, &weight);
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adj = weight;
    }
    G->kind = DN;
}

void DispDN(AdjMatrix *G)//输出有向图的邻接矩阵
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
