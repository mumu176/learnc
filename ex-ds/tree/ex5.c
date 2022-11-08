#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define N 20
#define M 2 * N - 1

typedef struct
{
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode, HuffmanTree[M + 1]; // the first is empty

typedef char *HuffmanCode[N + 1];

void select(HuffmanTree ht, int n, int *x1, int *x2)
{
    int i, t, p1, p2;
    for (i = 1, t = INT_MAX, p1 = 1; i <= n; i++)
    {
        if (ht[i].weight < t && ht[i].parent == 0)
        {
            t = ht[i].weight;
            p1 = i; //第一小的权值
        }
    }
    for (i = 1, t = INT_MAX, p2 = 1; i <= n; i++)
    {
        if (ht[i].weight < t && i != p1 && ht[i].parent == 0)
        {
            t = ht[i].weight;
            p2 = i; //第二小的权值
        }
    }
    *x1 = p1;
    *x2 = p2;
}

void CrtHuffmantree(HuffmanTree ht, int w[], int n)
{
    int i, m;
    for (i = 1; i <= n; i++)
    {
        ht[i].weight = w[i - 1];
        ht[i].parent = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
    }
    m = 2 * n - 1;
    for (i = n + 1; i <= m; i++)
    {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
    }
    // chushihuawanbi
    for (i = n + 1; i <= m; i++)
    {

        int s1 = 0, s2 = 0; //第一小第二小
        select(ht, i - 1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].LChild = s1; //  左小右大
        ht[i].RChild = s2;
    }
}

//创建哈夫曼编码
void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{
    char *cd;
    int start, c, i, p;
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        start = n - 1;
        c = i;
        p = ht[i].parent;
        while (p != 0)
        {
            --start;
            if (ht[p].LChild == c)
            {
                cd[start] = '1';
            }
            else
            {
                cd[start] = '0';
            }
            c = p;
            p = ht[p].parent;
        }
        hc[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(hc[i], &cd[start]);
    }
    free(cd); //释放空间
}

int main()
{
    HuffmanTree ht;
    HuffmanCode hc;
    int i, n;
    int w1[N];
    printf("权值个数:");
    scanf("%d", &n);
    printf("权值:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w1[i]);
    }
    CrtHuffmantree(ht, w1, n); //哈夫曼树构建
    CrtHuffmanCode(ht, hc, n); //哈夫曼编码

    printf("weigth\tparent\tLChild\tRChild\n"); // utf8
    for (i = 1; i <= 2 * n - 1; i++)
    {
        printf("%-6d\t%-6d\t%-6d\t%-6d\n", ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
    }

    printf("weigth\tparent\tLChild\tRChild\tCode\n"); // utf8
    for (i = 1; i <= n; i++)
    {
        printf("%-6d\t%-6d\t%-6d\t%-6d\t%-s\n", ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild, hc[i]);
    }

    return 0;
}
