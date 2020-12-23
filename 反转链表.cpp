#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct list
{
    int a;
    struct list *next;
}l;
l *cre(int n)
{
    int a,i;
    l *head,*r,*s;
    head=(l*)malloc(sizeof(l));
    r=head;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        s=(l *)malloc(sizeof(l));
        s->a=a;
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return head;
}
void f(l *head,int n)
{
    l *h=head->next,*r=head->next,*q=head->next,*p,*end;
    int i;
    if(n==2)
    {
        r=r->next;
        r->next=h;
        h->next=NULL;
        head->next=r;
    }
    else if(n>2)
    {
        while(r->next!=NULL) r=r->next;
        end=r;
        while(q->next!=r) q=q->next;
        r->next=q;
        p=h->next;
        h->next=NULL;
        for(i=0;i<n/2-1;i++)
        {
            r=p;
            while(r->next!=q) r=r->next;
            q->next=r;
            q=p;
            if(r==q) break;
            while(q->next!=r) q=q->next;
            r->next=q;
        }
        q->next=h;
        head->next=end;
    }
}
void output(l *head)
{
    l *r=head->next;
    while(r!=NULL)
    {
        printf("%d",r->a);
        if(r->next!=NULL) printf(" ");
        r=r->next;
    }
}
int main()
{
    int n,i,k;
    scanf("%d",&n);
    l *L[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        L[i]=cre(k);
        f(L[i],k);
    }
    for(i=0;i<n;i++)
    {
        output(L[i]);
        if(i!=n-1) printf("\n");
    }
    return 0;
}
