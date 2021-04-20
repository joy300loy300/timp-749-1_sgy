/* 02_max.c */
#include <stdio.h>

int main()
{
    int n;
    int x;
    int i;
    int max = -2147483647;
    (void)scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        (void)scanf("%d", &x);
        if (x > max)
            max = x;
    }
    printf("%d", max);
    return 0;
}
