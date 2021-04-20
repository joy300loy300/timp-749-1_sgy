#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct node* f;
    struct node* l;
} list;


struct node
{ 
    int value;
    struct node *next;
    struct node *prev;
} node;


void init(struct list* myList,int value) 
{
    struct node* m;
    m = (struct node*)malloc(sizeof(struct node));
    m->value=value;
    m->next=NULL;
    m->prev=NULL;
    myList->f = m;
    myList->l = m;
}


int is_empty(struct list* myList) 
{
    return myList->f==NULL && myList->l==NULL;
}


int clean(struct list* myList) 
{
    if(is_empty(myList)==1)
    {
        struct node *m=myList->f;
        struct node *e=NULL;
        while(m!=NULL)
        {
            e=m->next;
            free(m);
            m=e;
        }
        myList->f=NULL;
        myList->l=NULL;
    }
}


struct node* find(struct list* myList,int k)
{
    struct node *m=myList->f;
    while(m->value!=k){
        if(m->next!=NULL){
            m=m->next;
        }else{
            return 0;
        }
    }
    return m;
}


int push_back(struct list* myList, int x) 
{
    if(is_empty(myList)==1)
        init (myList,x);
    else
    {
        struct node *m = (struct node*)malloc(sizeof(struct node));
        m->value=x;
        m->prev=myList->l;
        m->next=NULL;
        myList->l=m;
        m->prev->next=m;
    }
    return 0;
}


int push_front(struct list* myList,int x)
{
    if(is_empty(myList)==1)
        init (myList,x);
    else
    {
        struct node *m = (struct node*)malloc(sizeof(struct node));
        m->value=x;
        m->prev=NULL;
        m->next=myList->f;
        myList->f=m;
        m->next->prev=m;
    }
    return 0;
}


int insert_after (struct list* myList,int num, int data)
{
    struct node* m = myList->f;
    for (int i = 1;i<num;i++)
    {
        m=m->next;
        if(m==NULL)
            return -1;
    }
    struct node *e = malloc(sizeof(node));
    e->value=data;
    e->next=m->next;
    e->prev=m;
    m->next->prev=e;
    m->next=e;
    return 0;
}


int insert_before(struct list* myList,int num, int data)
{
    struct node* m = myList->f;
    for (int i = 1;i<num;i++)
    {
        m=m->next;
        if(m==NULL)
            return -1;
    }
    struct node *e = malloc(sizeof(node));
    e->value=data;
    e->prev=m->prev;
    e->next=m;
    m->prev=e;
    e->prev->next=e;
    return 0;
}


void help_remove(struct list* myList, struct node *m)
{
    if(m!=NULL){
        if (m==myList->f && m==myList->l) {
            clean(myList);
            return;
        }
        if (m==myList->f)
        {
            myList->f=m->next;
            m->next->prev=NULL;
        }
        else if(m==myList->l)
        {
            myList->l=m->prev;
            m->prev->next=NULL;
        }
        else if (m!=myList->f && m!=myList->l)
        {
            m->next->prev=m->prev;
            m->prev->next=m->next;
        }
        free(m);
    }
}


int remove_first(struct list* myList, int x)
{
    struct node* elem = find(myList, x);
    if (elem!=NULL){
        help_remove(myList,elem);
        return 0;
    }
    return -1;
}


struct node* find_invers(struct list* myList, int k)
{
    struct node *m=myList->l;
    while(m->value!=k){
        if(m->prev!=NULL){
            m=m->prev;
        }else{
            return 0;
        }
    }
    return m;
}


int remove_last(struct list* myList,int g)
{
    struct node* elem = find_invers(myList, g);
    if (elem!=NULL){
        help_remove(myList,elem);
        return 0;
    }
    return -1;
}


void print(struct list* myList)
{
    struct node* m=myList->f;
    while(m->next!=NULL)
    {
        printf("%d ", m->value);
        m=m->next;
    }
    printf("%d\n", m->value);
}


void print_invers(struct list* myList)
{
    struct node* m=myList->l;
    while(m->prev!=NULL)
    {
        printf("%d ", m->value);
        m=m->prev;
    }
    printf("%d\n", m->value);
}


int main()
{
    int f,a;
    int k1;
    int k2;
    int k3;
    int m;
    int t;
    int j,x;
    int u,y;
    int z;
    int r;
    struct list* stru40k=(struct list*)malloc(sizeof(struct list));
    scanf("%d",&f);
    for (int i=0;i<f;i++)
    {
        scanf("%d",&a);
        push_back(stru40k,a);
    }
    print(stru40k);
    scanf("%d%d%d",&k1,&k2,&k3);
    if(find(stru40k,k1)!=NULL)
        printf("1 ");
    else
        printf("0 ");
    if(find(stru40k,k2)!=NULL)
        printf("1 ");
    else
        printf("0 ");
    if(find(stru40k,k3)!=NULL)
        printf("1 ");
    else
        printf("0 ");
    printf("\n");
    scanf("%d",&m);
    push_back(stru40k,m);
    print_invers(stru40k);
    scanf("%d",&t);
    push_front(stru40k,t);
    print(stru40k);
    scanf("%d%d",&j,&x);
    insert_after(stru40k,j,x);
    print_invers(stru40k);
    scanf("%d%d",&u,&y);
    insert_before(stru40k,u,y);
    print(stru40k);
    scanf("%d",&z);
    remove_first(stru40k,z);
    print_invers(stru40k);
    scanf("%d",&r);
    remove_last(stru40k,r);
    print(stru40k);
    clean(stru40k);
    return 0;
}
