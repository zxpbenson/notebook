#include <stdio.h>

struct student
{
    int num;
    char name[20];
    char sex;
    int age;
};

struct student stu[] = {
    {10101, "Li Lin", 'M', 18},
    {10102, "Zhang Fun", 'M', 19},
    {10104, "Wang Min", 'F', 20}
};

void main()
{
    struct student *p;
    printf("No. Name sex age\n");
    for(p = stu; p < stu+3; p++)
        printf("%5d %-20s %2c %4d\n", p->num, p->name, p->sex, p->age);
}