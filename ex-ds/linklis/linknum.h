#ifndef _NUMBER_H_
#define _NUMBER_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*链表结构体定义*/
typedef struct node
{
    int num; /*可以更换数据类型*/
    struct node *next;
} Node, *LinkList;

//尾插法
void fromtail(LinkList L)
{
    Node *s, *r; /*使用指针访问后续产生的新节点*/
    int flag = 1;
    int num; /*当$出现停止flag=0*/
    r = L;
    while (flag)
    {
        scanf("%d", &num);
        if (num != 0)
        {
            s = (LinkList)malloc(sizeof(Node));
            s->num = num;
            s->next = r->next;
            r->next = s;
            r = s;
        }
        else
            flag = 0;
    }
}
//输出
void DispLinkList(LinkList L)
{
    Node *p;
    p = L->next; //两种方式遍历p=L
    while (p != NULL)
    {
        printf("%d  ", p->num);
        p = p->next;
    }
    printf("\n");
}
/*两个递增数字链表同序合并*//*尾插法合并*/
void MergeLinkList1(LinkList LA, LinkList LB)
{
    Node *pa, *pb, *r; /*尾插法*/
    pa = LA->next;
    pb = LB->next;
    LA->next = NULL;
    ;
    free(LB);
    r = LA;

    while (pa != NULL && pb != NULL)
    {
        if (pa->num <= pb->num)
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else
        {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL)
        r->next = pa;
    else
        r->next = pb;
}

/*两个递增数字链表逆序合并*//*头插法*/
void MergeLinkList2(LinkList LA, LinkList LB)
{
    Node *p, *pa, *pb; 
    pa = LA->next;
    pb = LB->next;
    p = NULL;
    LA->next = NULL;
    free(LB);

    while (pa != NULL && pb != NULL)
    {
        if (pa->num <= pb->num)
        {
            p = pa->next;
            pa->next = LA->next;
            LA->next = pa;
            pa = p;
        }
        else
        {
            p = pb->next;
            pb->next = LA->next;
            LA->next = pb;
            pb = p;
        }
    }
    while (pa != NULL)
    {
        p = pa->next;
        pa->next = LA->next;
        LA->next = pa;
        pa = p;
    }
    while (pb != NULL)
    {
        p = pb->next;
        pb->next = LA->next;
        LA->next = pb;
        pb = p;
    }
}

/*逆序单链表*/
void RevLinkList(LinkList L)
{
    Node *p, *x;
    p = L->next;
    x = NULL;
    L->next = NULL;
    while (p != NULL)
    {
        x = p->next;
        p->next = L->next;
        L->next = p;
        p = x;
    }
}

/*去除递增有序链表中大于mink小于maxk的整数*/
/*利用前驱定位、利用指针标记头尾*/

bool DelmLinklist(LinkList L, int mink, int maxk)
{
    Node *p, *m1, *m2, *d;
    p = L;
    m1 = NULL;
    m2 = NULL;
    d = NULL;
    if (mink > maxk)
        return false;
    while (p->next != NULL)
        if (p->next->num > mink)
        {
            m1 = p;
            break;
        }
        else
            p = p->next;
    while (m1 != NULL && p->next != NULL)
        if (p->next->num >= maxk)
        {
            m2 = p->next;
            p->next = NULL;
            break;
        }
        else
            p = p->next;
    if (m1 != NULL && m1->next != m2)
    {
        d = m1->next;
        m1->next = m2;
        p = d;
        while (p != NULL)
        {
            d = p->next;
            free(p);
            p = d;
        }

        return true;
    }
    else
        return false;
}

#endif