// 此文件包含 例 8,9,10,11 以及 11.7.8 对链表的综合操作

#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct student)

struct student
{
    int num;
    float score;
    struct student *next;
};

int n;
struct student *create(void)
{
    struct student *head;
    struct student *p1, *p2;
    n = 0;
    p1 = p2 = (struct student *)malloc(LEN);
    scanf("%ld,%f", &p1->num, &p1->score);
    head = NULL;
    while(p1->num != 0)
    {
        n = n+1;
        if(n == 1)head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct student *)malloc(LEN);
        scanf("%ld,%f", &p1->num, &p1->score);
    }
    p2->next = NULL;
    return (head);
}

void print(struct student *head)
{
    struct student *p;
    printf("\nNow, These %d records are :\n", n);
    p = head;
    if(head != NULL)
    {
        do{
            printf("%ld %5.1f\n", p->num, p->score);
            p = p->next;
        }while(p != NULL);
    }
    
}

struct student * del(struct student * head, long num)
{
    struct student *p1, *p2;
    if(head == NULL){
        printf("\nlist null!\n");
        goto end;
    }
    p1 = head;
    while(num != p1->num && p1->next != NULL) {//p1指向的不是所要找的结点，并且后面还有结点
        p2 = p1;
        p1 = p1->next;//p1后移了一个结点
    }
    if(num == p1->num){//找到了
        if(p1 == head) head = p1->next;//若p1指向的是首结点，把第二个结点地址赋予head
        else p2->next = p1->next;//否则将下一结点地址赋给前一结点地址
        printf("delete : %ld\n", num);
        n = n - 1;
    } else {
        printf("%ld not been found!\n", num);
    }
    end;
    return(head);
}

struct student * insert(struct student * head, struct student * stud)
{
    struct student * p0, *p1, * p2;
    p1 = head; //使p1指向第一个结点
    p0 = stud; //p0指向要插入的结点
    if(head == NULL) {//原来的链表是空表
        head = p0; //使p0指向的结点作为头结点
        p0->next = NULL; //初始化指向，保证后续操作不发生不可预测的后果
    } else {
        while((p0->num > p1->num) && (p1->next != NULL)) {
            p2 = p1; //使p2指向刚才p1指向的结点
            p1 = p1->next; //p1后移一个结点
        }
        if(p0->num <= p1->num) {
            if(head == p1) {
                head = p0; //插到原来第一个结点之前
            } else {
                p2->next = p0; //插到p2指向的结点之后
            }
            p0->next = p1;
        } else {
            p1->next = p0; //插到最后的结点之后
            p0->next = NULL;
        }
    }
    n = n + 1; //结点数加1
    return(head);
}

void main()
{
    struct student * head, * stu;
    long del_num;
    printf("input records :\n");
    head = create(); //建立链表，返回头指针
    print(head);
    printf("\ninput the deleted number :");
    scanf("%ld", &del_num);
    while(del_num != 0)
    {
        head = del(head, deel_num);
        print(head);
        printf("input the deleted number :");
        scanf("%ld", &del_num);
    }
    printf("\ninput the inserted record :");
    stu = (struct student *)malloc(LEN);
    scanf("%ld,%f", &stu.num, &stu.score);
    while(stu->num != 0)
    {
        head = insert(head, stu);
        print(head);
        printf("input the inserted record :");
        stu = (struct student *)malloc(LEN);
        scanf("%ld,%f", &stu.num, &stu.score);
    }
}
