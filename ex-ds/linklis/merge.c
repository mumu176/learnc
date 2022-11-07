#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "number.h"

int main()
{
    LinkList a, b;
    int mink, maxk;
    a = (LinkList)malloc(sizeof(Node)); //初始化
    a->next = NULL;
    b = (LinkList)malloc(sizeof(Node));
    b->next = NULL;
    fromtail(a); //尾插建表建立递增序列
    fromtail(b); //尾插建表建立递增序列
    printf("递增序列a\t\t");
    DispLinkList(a);
    printf("递增序列b\t\t");
    DispLinkList(b);
    MergeLinkList2(a, b); //同序合并至a链表操作
    printf("同序合并至a\t\t");
    DispLinkList(a);
    RevLinkList(a); //逆序操作
    printf("逆序a    \t\t");
    DispLinkList(a);
    printf("输入mink maxk\t\t");
    scanf("%d%d", &mink, &maxk);
    DelmLinklist(a, mink, maxk); //删除4-8之间元素，需要递增序列
    printf("删除mink<x<maxk的a\t");
    DispLinkList(a);
    return 0;
}