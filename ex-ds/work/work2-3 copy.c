#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

//二叉树类型定义
typedef struct Node
{
    int data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;

//先序输入一个基础树元素为1
BiTree PreCreate(BiTree bt)
{
    int ch;
    scanf("%d", &ch);

    if (ch == 0)
    {
        bt = NULL;
        return bt;
    }
    else
    {
        bt = (BiTree)malloc(sizeof(BiTNode));
        bt->data = ch;
        bt->LChild = PreCreate(bt->LChild);
        bt->RChild = PreCreate(bt->RChild);
        return bt;
    }
}

//中序构建排序二叉树
void InOrderin(BiTree *bt) //传入二叉树根指针的指针用于传地址
{
    if ((*bt) != NULL)
    {
        InOrderin(&((*bt)->LChild));
        scanf("%d", &((*bt)->data));
        InOrderin(&((*bt)->RChild));
    }
}
//中序输出排序二叉树
void count(BiTree bt,int *x)
{
    if (bt != NULL)
    {
        count(bt->LChild,x);
        (*x)++;
        count(bt->RChild,x);
    }
}

//父子法输出法的二叉树
void disptree(BiTree bt,int count)
{
    for(;count!=0;count--)
    {
        printf("\t\t");
    }
    printf("\t%d\n%d\t\t%d\n",bt->data,bt->LChild->data,bt->RChild->data);
}


int main()
{
    int key, x; // key为关键字的值，x为从递归带出key的变量
    BiTree tr1 = NULL;
    bool bo = false;

    printf("初始化，输入1为继续分支，输入0为停止分支)：");
    tr1 = PreCreate(tr1); //初步构建二叉树
    printf("中序构建排序二叉树，输入递增值：");
    InOrderin(&tr1);
    count //改变值为排序二叉树
    disptree(tr1);

    return 0;
}