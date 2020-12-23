#include <stdio.h>
#include <stdlib.h>
 
typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode,*LinkList;
 
 
void InitList(LinkList *head);
void CreateList(LinkList head,int n);
void DestoryList(LinkList head);
void PrintList(LinkList head);
void ReverseList(LinkList head);
 
int main(void)
{
    LinkList head;
    int n;
 
    InitList(&head);
    while(scanf("%d",&n) == 1){
        if(n<=0){
            printf("NULL\n");
            continue;
        }
        CreateList(head,n);
//      PrintList(head);
        ReverseList(head);
        PrintList(head);
        DestoryList(head);
//      PrintList(head);
 
    }
 
 
 
    return 0;
}
 
//带有头结点的链表
void InitList(LinkList *head)
{
    *head = (LinkList)malloc(sizeof(ListNode));
    if(!*head)
        exit(-1);
    (*head)->next = NULL;
}
 
void CreateList(LinkList head,int n)
{
    LinkList p = head->next;
    int e;
 
    for(int i = 0;i < n;++i){
        scanf("%d",&e);
        LinkList q = (LinkList)malloc(sizeof(ListNode));
        if(!q)
            exit(-1);
        q->data = e;
        q->next = NULL;
        if(p == NULL){
            head->next = p = q;
        }else{
            p->next = q;
            p = q;
        }
    }
}
 
void DestoryList(LinkList head)
{
    LinkList p = head->next;
 
    while(p){
        LinkList q = p->next;
        free(p);
        p = q;
    }
    head->next = NULL;  //这句话必须加上
}
 
void PrintList(LinkList head)
{
    LinkList p = head->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
 
void ReverseList(LinkList head)
{
    LinkList pLow,pMid,pHight;
 
    if(head == NULL){   //我们也要考虑当传入的指针为空的情况，尽管我们设置了头结点，但以防万一
        return ;
    }
    if(head->next == NULL || head->next->next == NULL)
        return ;
    pLow = head->next;
    pMid = pLow->next;
    pHight = pMid->next;
    pLow->next = NULL;  //指针的赋值考虑全，不然得不到可靠的程序
 
    while(pMid){    //判断中间指针是否为空，
        pMid->next = pLow;
        if(pHight == NULL)  //必须判断，否则下面没法用pHight = pMid->next;
            break;
        pLow = pMid;
        pMid = pHight;
        pHight = pMid->next;
    }
    head->next = pMid;
}
 