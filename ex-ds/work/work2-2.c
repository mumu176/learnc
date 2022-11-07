#include <stdio.h>
#include <stdlib.h>

//结构体定义
typedef struct node
{
    char ch; /*英文字符不支持中文*/
    struct node *next;
} Node, *LinkList; /*同时LinkList是指向该种类型指针的别名，LinkList用于头节点创建，node用于新节点创建*/

/*头插法*/
void fromhead_s(LinkList L, const char *swen)
{
    Node *s; /*使用指针访问后续产生的新节点*/
    int i;
    for (i = 0; swen[i] != '\0'; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->ch = swen[i];
        s->next = L->next;
        L->next = s;
    }
}

int main()
{
    char str[20];
    scanf("%s", str);

    LinkList Lw;
    Node *p;
    int i = 0, flag = 1;

    Lw = (LinkList)malloc(sizeof(Node)); //初始化链表
    Lw->next = NULL;

    fromhead_s(Lw, str);
    p = Lw->next;
    while (flag==1&&p!=NULL) //头插法逆序后逐个判别
    {
        if (str[i] == p->ch) //不能让空指针参与判断
        {
            p = p->next;
            i++;
        }
        else if (str[i] != p->ch)
        {
            flag=0;
        }
    }

    if (str[i] == '\0')
        printf("输入的内容是回文");
    else
        printf("输入的内容不是回文");

    return 0;
}