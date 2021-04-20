#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct list
{
    struct list *next;
    int data;
};
struct node
{
    struct node *next;
    int data;
};
void init(struct list **l)
{
    *l = (struct list *)malloc(sizeof(struct list));
    (*l)->next = NULL;
    (*l)->data = 2147483647;
}
void clean(struct list *l)
{
    struct list *Temp = l;
    do
    {
        Temp = Temp->next;
        free(l);
        l = Temp;
        
    }
    while (l != NULL);
}
bool is_empty(struct list *l)
{
    if (l == NULL)
    return 0;
    else
    return 1;
}
struct node *find(struct list *l, int value)
{
    struct list *Temp = l;
    while (1)
    {
        if (Temp == NULL)
        return NULL;
        else
        {
            if ((Temp->data) == value)
            return ((struct node *)l);
            
        }
        Temp = Temp->next;
        
    }
}
int push_back(struct list *l, int value)
{
    if (l->data == 2147483647)
    {
        l->data = value;
        return 0;
        
    }
    struct list *Temp = (struct list *)malloc(sizeof(struct list));
    Temp = l;
    while (Temp->next != NULL)
    Temp = Temp->next;
    Temp->next = (struct list *)malloc(sizeof(struct list));
    Temp = Temp->next;
    Temp->data = value;
    Temp->next = NULL;
    return 0;
}
int push_front(struct list **l, int value)
{
    struct list *Temp = (struct list *)malloc(sizeof(struct list));
    Temp->data = value;
    Temp->next = (*l);
    (*l) = Temp;
    return 0;
}
int insert_after(struct node *l, int value)
{
    struct list *Temp = (struct list *)malloc(sizeof(struct list)), *Temp2;
    Temp2=(struct list *)l->next;
    l->next =(struct node *)Temp;
    Temp->data = value;
    Temp->next = Temp2;
    return 0;
}
int remove_node(struct list *l, int value)
{
    struct list *Temp = l;
    if (l != NULL)
    {
        while (1)
        {
            if ((Temp->next) == NULL)
            return 1;
            if ((Temp->next->data) == value)
            {
                struct list *Temp2 = (struct list *)malloc(sizeof(struct list));
                Temp2 = Temp->next->next;
                free(Temp->next);
                Temp->next = Temp2;
                return 0;
            }
            Temp = Temp->next;
        }
    }
    else
    return 1;
}
void print(struct list *l)
{
    while (l != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}
int main()
{
    struct list *l, *Temp;
    int n, a, k, m, t, j , x, z, i;
    scanf("%d", &n);//1 - считывание количества элементов
    init(&l);//2 - создание пустого списка
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        push_back(l, a);
        
    }
    print(l);//3 - вывод содержимого списка
    for (i = 0; i < 3; i++)//4 - считывание параметров k
    {
        scanf("%d", &k);
        if (find(l, k) == NULL)
        printf("0");
        else
        printf("1");
        if (i!=2)
        printf(" ");
        else
        printf("\n");
    }
    scanf("%d", &m);//5 - считывание параметра m
    push_back(l, m);
    print(l);//6 - вывод содержимого списка
    scanf("%d", &t);//7 - считывание параметра t
    push_front(&l, t);
    print(l);//8 - вывод содержимого списка
    scanf("%d", &j);//9 - считывание параметров j и x
    scanf("%d", &x);
    struct node *el=(struct node *)l;
    while (j != 1)
    {
        el = el->next;
        j--;
    }
    insert_after(el, x);
    print(l);//10  - вывод содержимого списка
    scanf("%d", &z);//11  - считывание параметра z
    if (l->data==z)
    {
        Temp=l->next;
        free(l);
        l=Temp;
    }
    else
    remove_node(l, z);
    print(l);//12  - вывод содержимого списка
    clean(l);//13 - очистка списка
    return 0;
}

