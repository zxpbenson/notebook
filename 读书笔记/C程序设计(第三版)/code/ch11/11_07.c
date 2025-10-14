#include <stdio.h>
#define NULL 0

struct student
{
    int num;
    float score;
    struct student *next;
};

void main()
{
    struct student a,b,c, *head, *p;
    a.num = 10101; a.score = 89.5;
    a.num = 10103; a.score = 90;
    a.num = 10107; a.score = 85;
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;//指针值要小心使用，如果不初始化，是个不可预料的值
    p = head;
    do
    {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    }while(p != NULL);
}