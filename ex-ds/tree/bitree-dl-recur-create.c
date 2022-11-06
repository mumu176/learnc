#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//二叉树类型定义
typedef struct Node
{
    char data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;

//先序输入
BiTree PreCreate(BiTree bt)
{
    char ch;
    scanf("%c", &ch);
    setbuf(stdin, NULL);

    if (ch == '#')
    {
        bt=NULL;
        return bt;
    }
    else
    {
        bt=(BiTree)malloc(sizeof(BiTNode));
        bt->data=ch;
        bt->LChild=PreCreate(bt->LChild);
        bt->RChild=PreCreate(bt->RChild);
        return bt;
    }
}

//中序输入


//先序输出二叉树递归法
void PreOrder(BiTree bt)
{
    if (bt != NULL)
    {

        printf("%c  ", bt->data);
        PreOrder(bt->LChild);
        PreOrder(bt->RChild);
    }
}

//中序递归法
void InOrder(BiTree bt)
{
    if (bt != NULL)
    {
        InOrder(bt->LChild);
        printf("%c  ", bt->data);
        InOrder(bt->RChild);
    }
}

//后序递归法
void PostOrder(BiTree bt)
{
    if (bt != NULL)
    {
        PostOrder(bt->LChild);
        PostOrder(bt->RChild);
        printf("%c  ", bt->data);
    }
}

int main()
{
    BiTree bt1;
    bt1=PreCreate(bt1);
    printf("pre: ");
    PreOrder(bt1);
    printf("\n");
    printf("in: ");
    InOrder(bt1);
    printf("\n");
    printf("post: ");
    PostOrder(bt1);
    return 0;
}
