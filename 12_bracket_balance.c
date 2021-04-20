/* 12_bracket_balance.c */
#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    int i;
    char x;
    (void)scanf("%d", &n);
    for (i = 0; i < 2*n; i++)
    {
        (void)scanf("%c", &x);
        if (x=='(')
            count = count +1;
        if (x==')')
            count = count-1;
        if ((i==1) && (x==')'))
            count = 2147483647;
    }
    if (count  == 0)
        printf("1");
    else
        printf("0");
    return 0;
}
