# include <stdio.h>
# define SIZE 4

struct student_type
{
  char name[10];//姓名
  int num;//学号
  int age;//年龄
  char addr[15];//地址
}stud[SIZE];

void save()
{
  FILE *fp;
  int i;
  
  if((fp=fopen("stu_list", "wb"))==NULL)
  {
    printf("can not open file\n");
    return;
  }
  
  for(i=0; i<SIZE; i++)
    if(fwrite(&stud[i], sizeof(struct student_type), 1, fp)!=1)
      printf("file write error\n");
  
  fclose(fp);
}

void main()
{
  int i;
  for(i=0; i<SIZE; i++)
    scanf("%s%d%d%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
    
  save();
}