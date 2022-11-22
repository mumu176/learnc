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

typedef struct vertexdata
{
    char name[MAX_VERTEX_NUM];
}VertexData[MAX_VERTEX_NUM];

typedef struct arcnode //定义边结构
{
    int adj;
} ArcNode;
typedef struct adjmatrix //定义邻接矩阵结构
{
    VertexData vertex[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} AdjMatrix;

int LocateVertex(AdjMatrix *G, char v[]) //通过元素寻找位置
{
    int j = false, k;
    for (k = 0; k < G->vexnum; k++)
    {
        if (strcmp(G->vertex[k]->name,v)==0)
        {
            j = k;
            break;
        }
    }
    return j;
}

void CreatUDN(AdjMatrix *G) //创建有向网络
{
    int i, j, k, weight;
    char v1[MAX_VERTEX_NUM], v2[MAX_VERTEX_NUM];
    scanf("%d%d", &G->vexnum, &G->arcnum);
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;
    }
    for (i = 0; i < G->vexnum; i++)
    {
        setbuf(stdin, NULL); //清空输入缓冲区
        gets(G->vertex[i]->name);
    }

    for (k = 0; k < G->arcnum; k++)
    {
        setbuf(stdin, NULL); //清空输入缓冲区
        scanf("%s %s %d", &v1, &v2, &weight);
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adj = weight;
        G->arcs[j][i].adj = weight;
    }
    G->kind = UDN;
}

void DispUDN(AdjMatrix *G) //输出有向图的邻接矩阵
{
    int i, j;
    printf("UDN\t");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%s\t", G->vertex[i]->name);
    }
    printf("\n");
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%s\t", G->vertex[i]->name);
        for (j = 0; j < G->vexnum; j++)
        {
            if (G->arcs[i][j].adj != INFINITY)
                printf("%d\t", G->arcs[i][j].adj);
            else 
                printf("inf\t");
        }
        printf("\n");
    }
}

bool visited[MAX_VERTEX_NUM*MAX_VERTEX_NUM]={false};
//领接矩阵深度优先遍历
void DepthFirstSerach(AdjMatrix g,int v0)
{
    int vj;
    printf("%s\t",g.vertex[v0]->name);
    visited[v0]=true;
    for(vj=0;vj<g.vexnum;vj++)
    {
        if(visited[vj]==false&&g.arcs[v0][vj].adj!=INFINITY)
        DepthFirstSerach(g,vj);
    }  
}
int main()
{
    AdjMatrix G_point;
    CreatUDN(&G_point);
    DispUDN(&G_point);
    printf("DFS:\t");
    DepthFirstSerach(G_point,0);
    return 0;
}
