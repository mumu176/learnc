//叫号系统

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 10//通过宏定义修改最大排队人数
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
    else if (q.front != q.rear)
    {
        for (i = q.front; i < MAXSIZE; i++)
            printf("%c", q.str[i]);
        for (i = 0; i < q.rear; i++)
            printf("%c ", q.str[i]);
    }
}

//开始排号端，叫号端需要另一个线程
int main()
{
    SeqQueue q;
    int i, num = 1, front;
    char ch, str[4];
    bool bo;
    q.front = 0; //初始化
    q.rear = 0;
    printf("-----排队排号系统v1-----\ninsert [in] or [out]\n");
    while (scanf("%s", str) != EOF) //排号器输入ctrl-z停止
    {

        if (strcmp("in", str) == 0)
        {
            if (inqueue(&q, 'in') == true)
            {
                if (q.front <= q.rear)
                {
                    front = q.rear - q.front - 1;
                }
                else
                {
                    front = q.rear + MAXSIZE - q.front - 1;
                }
                printf("your num is %d ,front %d\n", num, front);
                num++;
                printf("insert [in] or [out]\n");
            }
            else
            {
                printf("wait someone out,press [in] one more time\n");
                continue;
            }
        }
        else if (strcmp("out", str) == 0)
        {
            outqueue(&q);
            printf("dequeue complete\n");
        }
    }

    return 0;
}