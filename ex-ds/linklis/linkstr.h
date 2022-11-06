#ifndef _linkstr_H_
#define _linkstr_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*链表结构体定义*/
typedef struct node
{
    char str[20]; /*可以更换数据类型*/
    struct node *next;
} Node, *LinkList; /*同时LinkList是指向该种类型指针的别名，LinkList用于头节点创建，node用于新节点创建*/

/*头插法加入链表*/
void fromhead(LinkList L)
{
    Node *s; /*使用指针访问后续产生的新节点*/
    int flag = 1;
    char str[20]; /*当$出现停止flag=0*/
    while (flag)
    {
        scanf("%s", str);
        if (str[0] != '$')
        {
            s = (LinkList)malloc(sizeof(Node));
            strcpy(s->str, str);
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
}

/*尾插法加入链表*/
void fromtail(LinkList L)
{
    Node *s, *r; /*使用指针访问后续产生的新节点*/
    int flag = 1;
    r = L;
    char str[20]; /*当$出现停止flag=0*/
    while (flag)
    {
        scanf("%s", str);
        if (str[0] != '$')
        {
            s = (LinkList)malloc(sizeof(Node));
            strcpy(s->str, str);
            s->next = r->next;
            r->next = s;
            r = s;
        }
        else
            flag = 0;
    }
}

/*判断链表是否为空*/
int ListEmpty(LinkList L)
{
    return (L->next == NULL);
}

/*获取链表长度*/
int ListLength(LinkList L)
{
    int n = 0;
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return (n);
}

/*输出链表*/
void DispList(LinkList L)
{
    Node *p;
    p = L->next; //两种方式遍历p=L
    while (p != NULL)
    {
        printf("%s\n", p->str);
        p = p->next;
    }
    printf("\n");
}

Node *GetData(LinkList L, int i)
{
    int j = 0;
    Node *p;
    p = L;
    while (j < i && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if (i == j)
        return p;
    else
        return NULL;
}
//按元素查找
int Locate(LinkList L, char *e)
{
    Node *p;
    p = L;
    int flag = -1, i = 0;
    while (flag != 0 && p->next != NULL)
    {
        p = p->next;
        i++;
        flag = strcmp(p->str, e);
    }
    if (flag == 0)
        return i;
    else
        return 0;
}
/*单链表第i位置前插入e*/
void InsList(LinkList L, int i, char *e)
{
    int j = 0;
    Node *s, *p;
    p = L;
    while (j != i - 1 && p->next != NULL) /*可以插入链表最后一个元素后？？*/
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
    {
        printf("插入位置不合理！");
        return;
    }
    else
    {
        s = (LinkList)malloc(sizeof(Node));
        strcpy(s->str, e);
        s->next = p->next;
        p->next = s;
    }
}

//删除位置元素
void DelList(LinkList L, int i)
{
    int j = 0;
    Node *r, *p;
    p = L;
    while (j < i - 1 && p->next != NULL) /*p不能无所指*/
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
    {
        printf("删除位置不合理！");
        return;
    }
    else
    {
        r = p->next;
        p->next = r->next;
        free(r);
    }
}

/*逆序单链表*/
void RevLinkList(LinkList L)
{
    Node *p, *s;
    s = L->next;
    p = L->next->next;
    L->next = NULL;
    while (s != NULL)
    {
        s->next = L->next;
        L->next = s;
        s = p;
        if (p != NULL)
            p = p->next;
    }
}
#endif