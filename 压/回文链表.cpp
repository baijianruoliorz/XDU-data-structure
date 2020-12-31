//回文链表
#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1
struct ListNode{
	char val;
	struct ListNode *next;
};
int isPalindrome(ListNode* head){
    char s[70000],i=0,j=0;
	while(head){
        s[i++]=head->val;
        head=head->next;
    }
	int length=i;
	//使用双指针法检查，在起点放一个指针，结尾放一个指针
	for(i=0,j=length-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return false;
		}
	}
	return true;
    
}
int main(){
	char ch;
	ListNode *L,*r;
	scanf("%c",&ch);
	L=(ListNode *)malloc(sizeof(ListNode));
	L->val=ch;
	L->next=NULL;
	r=L;
	while(scanf("%c",&ch)!=EOF){
		ListNode *p;
		if(ch!='\n'){
			p=(ListNode *)malloc(sizeof(ListNode));
			p->val=ch;
			r->next=p;
			r=p;
		}
	}
	r->next=NULL;
	if(isPalindrome(L)){
		printf("right");
	}else{
		printf("wrong");
	}
	return 0;	
}

