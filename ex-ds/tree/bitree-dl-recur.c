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

void addLc(BiTree bt,char ch)
{
    BiTNode *s;
    s=(BiTree)malloc(sizeof(BiTNode));
    s->LChild=NULL;
    s->RChild=NULL;
    s->data=ch;
    bt->LChild=s;
}
void addRc(BiTree bt,char ch)
{
    BiTNode *s;
    s=(BiTree)malloc(sizeof(BiTNode));
    s->LChild=NULL;
    s->RChild=NULL;
    s->data=ch;
    bt->RChild=s;
}

//先序输出二叉树递归法
void PreOrder(BiTree bt)
{
    if (bt != NULL)
    {
        
        printf("%c\n", bt->data);
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
        printf("%c\n", bt->data);
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
        printf("%c\n", bt->data);
    }
}

int main()
{
    BiTree bt1;
    bt1=(BiTree)malloc(sizeof(BiTNode));
    bt1->LChild=NULL;
    bt1->RChild=NULL;
    bt1->data='a';
    addLc(bt1,'b');
    addRc(bt1,'c');
    addLc(bt1->LChild,'d');
    addRc(bt1->LChild,'e');
    addLc(bt1->LChild->LChild,'f');
    PreOrder(bt1);
    return 0;
}
