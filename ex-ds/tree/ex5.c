#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 20
#define M 2*N-1

typedef struct
    {
        int weight;
        int parent;
        int LChild;
        int RChild;
    }HTNode,HuffmanTree[M+1];

void select(HuffmanTree ht,int n,int *x1,int *x2)
{
    int i,t,p1,p2;
    for(i=1,t=INT_MAX,p1=1;i<=n;i++)
    {
        if(ht[i].weight<t)
        {
            t=ht[i].weight;
            p1=i;//p传出最小权值的序号
        }
    }
    for(i=1,t=INT_MAX,p2=1;i<=n;i++)
    {
        if(ht[i].weight<t&&i!=p1)
        {
            t=ht[i].weight;
            p2=i;//p传出第二小权值的序号
        }
    }
    *x1=p1;
    *x2=p2;
}

void CrtHuffmantree(HuffmanTree ht,int w[],int n)
{
    int i,m;
    for(i=1;i<=n;i++)
    {
        ht[i].weight=w[i-1];
        ht[i].parent=0;
        ht[i].LChild=0;
        ht[i].RChild=0;
    }
    m=2*n-1;
    for(i=n+1;i<=m;i++)
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].LChild=0;
        ht[i].RChild=0;
    }
    //chushihuawanbi
    for(i=n+1;i<=m;i++)
    {

        int s1=0,s2=0;//第一小和第二小的序号
        select(ht,i-1,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].LChild=s1;//  左小右大
        ht[i].RChild=s2;

    }
}


int main()
{
    HuffmanTree ht[10];
    int i;
    int w1[5];
    for(i=0;i<5;i++)
    {
        scanf("%d",&w1[i]);
    }
    CrtHuffmantree(ht,w1,5);

    return 0;
}
