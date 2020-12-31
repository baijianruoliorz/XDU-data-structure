//递增链表的插入
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
	struct ListNode *next;
};
int main(){
	int n,height,flag=0;
	scanf("%d%d",&n,&height);
	ListNode *L,*r;
	L=(ListNode *)malloc(sizeof(ListNode));
	r=L;
	while(n--){
		ListNode *p;
		p=(ListNode *)malloc(sizeof(ListNode));
		scanf("%d",&p->val);
		r->next=p;
		r=p;
	}
	r->next=NULL;
	r=L;
	while(r->next){
		if(r->next->val>height){
			ListNode *p;
			p=(ListNode *)malloc(sizeof(ListNode));
			p->val=height;
			p->next=r->next;
			r->next=p;
			flag=1;
			break;
		}
		r=r->next;
	}
	if(!flag){
		ListNode *p;
		p=(ListNode *)malloc(sizeof(ListNode));
		p->val=height;
		r->next=p;
		p->next=NULL;
	}
	L=L->next; 
	while(L){		
		printf("%d",L->val);
		if(L->next){
			printf(" ");
		}
		L=L->next;
	}
	return 0;
} 
