//·´×ªÁ´±í 
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
	struct ListNode *next;
};
ListNode* reverseList(ListNode* head) {
    ListNode*cur=NULL,*pre=head;
    while(pre){
        ListNode*t=pre->next;
        pre->next=cur;
        cur=pre;
        pre=t;
    }
    return cur;
}
int main(){
	int n,m,k;
	scanf("%d",&m);
	k=m;
	ListNode *L[1000],*r[1000];
	while(m--){
		L[m]=(ListNode*)malloc(sizeof(ListNode));
		r[m]=L[m];
		scanf("%d",&n);
		for(int i=n;i>0;i--){
			ListNode *p[1000];
			p[m]=(ListNode*)malloc(sizeof(ListNode));
			scanf("%d",&p[m]->val);
			r[m]->next=p[m];
			r[m]=p[m];
		}
		r[m]->next=NULL;
		L[m]=reverseList(L[m]);
	}
	while(k--){
		while(L[k]->next){
			printf("%d ",L[k]->val);
			L[k]=L[k]->next;
		}
		printf("\n");
	}
	return 0;
}
