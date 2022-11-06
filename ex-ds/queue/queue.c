#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10
//循环队列定义
typedef struct
{
    char str[MAXSIZE];
    int front; //头指第一个值
    int rear;  //尾指第一个空
} SeqQueue;

//进队
bool inqueue(SeqQueue *q, char ch)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
        return false;
    else
    {
        q->str[q->rear] = ch;
        q->rear = (q->rear + 1) % MAXSIZE;
    }
    return true;
}

//出队
bool outqueue(SeqQueue *q)
{
    if (q->front == q->rear)
        return false;
    else
    {
        q->front = (q->front + 1) % MAXSIZE;
        return true;
    }
}

//输出队列
void dispqueue(SeqQueue q)
{
    int i;
    if (q.front < q.rear)
    {
        for (i = q.front; i < q.rear; i++)
            printf("%c ", q.str[i]);
    }
    else if(q.front!=q.rear)
    {
        for (i = q.front; i < MAXSIZE; i++)
            printf("%c", q.str[i]);
        for (i = 0; i < q.rear; i++)
            printf("%c ", q.str[i]);
    }
}

//开始
int main()
{
    SeqQueue q;
    int i;
    char ch;
    bool bo;
    q.front = 0; //初始化
    q.rear = 0;

    while (1)
    {
        scanf("%c", &ch);
        if (ch >= 48 && ch <= 57)
        {
            bo = inqueue(&q, ch);
        }
        else if (ch >= 97 && ch <= 122)
        {
            bo = outqueue(&q);
        }
        else
            break;
    }

    dispqueue(q);

    return 0;
}