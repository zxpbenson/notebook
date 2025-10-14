#include <stdlib.h>
#include <stdio.h>

struct student_type
{
  char name[10];
  int num;
  int age;
  char sex;
}stud[10];

void main()
{
  int i;
  FILE *fp;
  if((fp=fopen("stud_dat", "rb"))==NULL)
  {
    printf("can not open file\n");
    exit(0);
  }
  for(i=0; i<10; i+=2)
  {
    fseek(fp, i*sizeof(struct student_type), 0);
    fread(&stud[i], sizeof(struct student_type), 1, fp);
    printf("%s %d %d %c\n", stud[i].name, stud[i].num, stud[i].age, stud[i].sex);
  }
  fclose(fp);
}