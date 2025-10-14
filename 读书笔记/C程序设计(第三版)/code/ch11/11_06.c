#include <stdio.h>
#include <string.h>
#define FORMAT "%d\n%s\n%f\n%f\n%f\n"

struct student
{
    int num;
    char name[20];
    float score[3];
}stu = {12345, "Li Li", 67.5, 89, 78.6};

void main()
{
    void print(struct student*);
    print(&stu);
}

void print(struct student *p)
{
    printf(FORMAT, p->num, p->name, p->score[0], p->score[1], p->score[2]);
    printf("\n");
}