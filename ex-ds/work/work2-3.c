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
void InOrderout(BiTree bt)
{
    if (bt != NULL)
    {
        InOrderout(bt->LChild);
        printf("%d ", bt->data);
        InOrderout(bt->RChild);
    }
}

bool search_key_tree(BiTree tr, int key)
{
    bool bo = false;
    if (tr->data > key)
    {
        tr = tr->LChild;
        if (tr == NULL)
            return false;
        else if (search_key_tree(tr, key) == true)
            return true;
    }
    else if (tr->data < key)
    {
        tr = tr->RChild;
        if (tr == NULL)
            return false;
        else if (search_key_tree(tr, key) == true)
            return true;
    }
    else if (tr->data == key)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int key;// key为关键字的值，x为从递归带出key的变量
    BiTree tr1 = NULL;
    bool bo = false;

    printf("初始化，输入1为继续分支，输入0为停止分支)：");
    tr1 = PreCreate(tr1); //初步构建二叉树
    printf("中序构建排序二叉树，输入递增值：");
    InOrderin(&tr1); //改变值为排序二叉树
    printf("当前排序二叉树中序输出：");
    InOrderout(tr1); //按值从小到大输出
    printf("\n输入要查找的key值：");
    scanf("%d", &key);              //输入关键字key的值
    bo = search_key_tree(tr1, key); //判断是否找到
    if (bo == true)
    {
        printf("找到关键字key");
    }
    else
    {
        printf("找不到关键字key");
    }

    return 0;
}