#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM
#define INFINITY 32768

//图的种类：DG表示有向图，UDG表示无向图
typedef enum {DG ,DN, UDG, UDN}GraphKind;
//顶点为字符型数据
typedef char VertexData;
//边定义
typedef struct ArcNode
{
  int adj;//表示权值，有权表示连通，且有距离
  char ch;
}ArcNode;
//邻接矩阵图定义
typedef struct
{
  VertexData vertex[MAX_VERTEX_NUM];
  ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  int vexnum,arcnum;
  GraphKind kind;
}AdjMatrix;

int LocateVertex(AdjMatrix *G,VertexData v)
{
    int j=false,k;
    for(k=0;k<G->vexnum;k++)
    {
        if(G->vertex[k]==v)
        {
            j=k;
            break;
        }
    }
    return j;
}

void CreatDN(AdjMatrix *G)
{
    int i,j,k,weight;
    VertexData v1,v2;
    scanf("%d%d",&G->vexnum,&G->arcnum);
    for(i=0;i<G->vexnum)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=INFINITY;
    for(i=0;i<G->vexnum;i++)
        scanf("%c",&G->vertex[i]);
    for(k=0;k<G->arcnum;k++)
    {
        scanf("%c %c %d",&v1,&v2,&weight);
        i=LocateVertex(G,v1);
        j=LocateVertex(G,v2);
        G->arcs[i][j].adj=weight;
    }
    G->kind=DN;
}

void DispDN(AdjMatrix G)
{
    int i,j;
    printf("DN\t");
    for(i=0;i<G->vexnum;i++)
    {
        printf("%c\t",G->vertex[i]);
    }
    printf("\n");
    for(i=0;i<G->vexnum;i++)
    {
        printf("%c\t",G->vertex[i]);
        for(j=0;j<G->vexnum;j++)
        {
            if(G->arcs[i][j].adj!=INFINITY)
            printf("%d\t",G->arcs[i][j].adj);
            else
            printf("$");
        }
        printf("\n");
    }
}

int main()
{
    AdjMatrix G_point;
    CreatDN(&G_point);
    DispDN(G_point);
    return 0;

}



