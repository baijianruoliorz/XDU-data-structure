#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef struct node{
	int position;
	int m;
	struct node *next;
}node,*LinkList;
void CreateList(LinkList &L,int n){
	LinkList p1,p2;
	int i=1;
	p1=(LinkList)malloc(sizeof(node));
	p2=(LinkList)malloc(sizeof(node));
	L->next=p1;
	while(n--){
		scanf("%d",&p1->m);
		p1->position=i;
		p2->next=p1;
		p2=p1;
		p1=(LinkList)malloc(sizeof(node));
		i++;
	}
	p2->next=L;
}
int main(){
	int n,M;
	int i,k=1;
	LinkList L;
	LinkList p1,p2,p3=NULL;
	L=(LinkList)malloc(sizeof(node));
	if(!L){
		exit(1);
	}
	scanf("%d %d",&n,&M);
	CreateList(L,n);
	p1=L;
	while(n!=0){
		for(i=1;i<=M;i++){
			p1=p1->next;
			if(p1==L){
				p1=p1->next;
			}
			if(i==M-1){
				p2=p1;
			}
		}
		free(p3);
		M=p1->m;
		printf("%d ",p1->position);
		p2->next=p1->next;
		n--;
	}
	return 0;
}
