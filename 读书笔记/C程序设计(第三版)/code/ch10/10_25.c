# include <stdio.h>

void main()
{
    float score[][4] = {{60,70,80,90},{56,89,67,88},{34,78,90,66}};
    float *search(float (*pointer)[4]);
    float *p;
    int i, j;
    for(i = 0; i < 3; i++)
    {
        p = search(score+i);
        if(p == *(score+i))
        {
            printf("No. %d scores:", i);
            for(j=0; j<4; j++)
                printf("%5.2f", *(p+j));
            printf("\n");
        }
    }

    printf("\n");
}

//pointer是指针变量，指向一维数组(有4个元素)
//从实参传给形参pointer的是score+i，它是score第i行的首地址
float *search(float (* pointer)[4])
{
    int i;
    float *pt;//pt是指向实型变量的指针变量
    pt = *(pointer + 1);//先把pt指向行之末尾。用pt作为区分有无不及格课程的标志
    for(i=0; i<4; i++)
        if(*(*pointer+i) < 60)
            pt = *pointer;//如果有不及格的就让pt指向本行0列
    return (pt);
}