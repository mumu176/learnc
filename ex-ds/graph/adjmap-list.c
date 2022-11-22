#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_VERTEX_NUM 10
#define INFINITY 32768
typedef enum //定义枚举图类型
{
    DG,  //有向图
    DN,  //有向网
    UDG, //无向图
    UDN  //无向网
} GraphKind;

typedef struct arcnode //定义边结构
{
    int adj;
    int vex;
    struct arcnode *nextarc;
} ArcNode;

typedef struct vertexnode
{
    char name[MAX_VERTEX_NUM];
    struct arcnode *firstarc;
} Vertexnode;

typedef struct adjlist //定义邻接矩阵结构
{
    Vertexnode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} AdjList;

int LocateVertex(AdjList *G, char v[]) //通过元素寻找位置
{
    int j = false, k;
    for (k = 0; k < G->vexnum; k++)
    {
        if (strcmp(G->vertex[k].name, v) == 0)
        {
            j = k;
            break;
        }
    }
    return j;
}

void CreatUDN(AdjList *G) //创建有向网络
{
    int i, j, k, weight;
    char v1[MAX_VERTEX_NUM], v2[MAX_VERTEX_NUM];
    ArcNode *p, *q, *r;

    printf("顶点和边的数量");
    scanf("%d%d", &G->vexnum, &G->arcnum); //输入顶点和边的数量
    for (i = 0; i < G->vexnum; i++)        //初始化顶点指针域
    {
        G->vertex[i].firstarc = NULL;
    }
    //初始化顶点数据
    for (i = 0; i < G->vexnum; i++)
    {
        setbuf(stdin, NULL); //清空输入缓冲区
        gets(G->vertex[i].name);
    }
    //输入k个边的数据,一次输入同一个边的
    for (k = 0; k < G->arcnum; k++)
    {
        setbuf(stdin, NULL); //清空输入缓冲区
        scanf("%s %s %d", &v1, &v2, &weight);
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        p = G->vertex[i].firstarc;
        r = (ArcNode *)malloc(sizeof(ArcNode)); //头插法
        r->adj = weight;
        r->vex=j;
        r->nextarc = p;
        G->vertex[i].firstarc = r;

        q= G->vertex[j].firstarc;
        r = (ArcNode *)malloc(sizeof(ArcNode)); //头插法
        r->adj = weight;
        r->vex=i;
        r->nextarc = q;
        G->vertex[j].firstarc = r;
    }
    G->kind = UDN;
}

void DispUDN(AdjList *G) //输出有向图的邻接矩阵
{
    int i, j;
    ArcNode *p;

    printf("UDN\n");
    for (i = 0; i < G->vexnum; i++)
    {
        p = G->vertex[i].firstarc;
        printf("%d  %10s\t",i, G->vertex[i].name);
        while (p != NULL)
        {
            printf("%10s-%d\t",G->vertex[p->vex].name, p->adj);
            p = p->nextarc;
        }
        printf("\n");
    }
}

bool visited[MAX_VERTEX_NUM * MAX_VERTEX_NUM] = {false};
//领接表深度优先遍历
void DepthFirstSerach(AdjList g, int v0)
{
    ArcNode *vj;
    vj=g.vertex[v0].firstarc;
    
    printf("%10s\t", g.vertex[v0].name);
    visited[v0] = true;
    
    while (vj!=NULL)
    {
        if(!visited[vj->vex])
            DepthFirstSerach(g,vj->vex);
        vj=vj->nextarc;
    }
    
}
int main()
{
    AdjList G_point;
    CreatUDN(&G_point);
    DispUDN(&G_point);
    printf("DFS:\t");
    DepthFirstSerach(G_point, 0);
    return 0;
}
