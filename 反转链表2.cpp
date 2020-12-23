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
 
//����ͷ��������
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
    head->next = NULL;  //��仰�������
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
 
    if(head == NULL){   //����ҲҪ���ǵ������ָ��Ϊ�յ��������������������ͷ��㣬���Է���һ
        return ;
    }
    if(head->next == NULL || head->next->next == NULL)
        return ;
    pLow = head->next;
    pMid = pLow->next;
    pHight = pMid->next;
    pLow->next = NULL;  //ָ��ĸ�ֵ����ȫ����Ȼ�ò����ɿ��ĳ���
 
    while(pMid){    //�ж��м�ָ���Ƿ�Ϊ�գ�
        pMid->next = pLow;
        if(pHight == NULL)  //�����жϣ���������û����pHight = pMid->next;
            break;
        pLow = pMid;
        pMid = pHight;
        pHight = pMid->next;
    }
    head->next = pMid;
}
 