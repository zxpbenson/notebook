#include<stdio.h>

void main()
{
    int large(int x, int y);
    int a[10], b[10], i, r, n = 0, m = 0, k = 0;
    printf("enter array a : \n");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    printf("enter array b : \n");
    for(i = 0; i < 10; i++)
        scanf("%d", &b[i]);
    printf("\n");
    for(i = 0; i < 10; i++)
    {
        r = large(a[i], b[i]);
        if(r == 1)
            n = n + 1;
        else
            if(r == 0)
                m = m + 1;
            else
                k = k + 1;
    }
    printf("a[i] > b[i] %d times\n", n);
    printf("a[i] = b[i] %d times\n", m);
    printf("a[i] < b[i] %d times\n", k);
    if(n > k)
        printf("array a is larger to array b\n");
    else if(n < k)
        printf("array a is smaller to array b\n");
    else
        printf("array a is equal to array b\n");
}

large(int x, int y)
{
    int flag;
    if(x > y)
        flag = 1;
    else if(x < y)
        flag = -1;
    else
        flag = 0;
    return (flag);
}