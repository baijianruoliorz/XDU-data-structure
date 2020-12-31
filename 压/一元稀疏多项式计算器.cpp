#include<stdio.h>
#include<stdlib.h>
typedef struct Polynmial{
	int coef;
	int exp;
	struct Polynmial *next;
}PolyNode,*PolyList;
PolyList PolyCreate(int count,int t){
	PolyList head,rear,s;
	int c,e;
	head=(PolyList)malloc(sizeof(PolyNode));
	rear=head;
	for(int i=0;i<count;i++){
		s=(PolyList)malloc(sizeof(PolyNode));
		scanf("%d%d",&c,&e);
		if(!t){
			s->coef=c;
		}else{
			s->coef=-c;
		}
		s->exp=e;
		rear->next=s;
		rear=s;
	}
	rear->next=NULL;
	return(head);
}
void PolyAdd(PolyList &ha,PolyList &hb){
	PolyList p,q,tail,temp;
	int sum;
	p=ha->next;
	q=hb->next;
	tail=ha;//tail指向和多项式的尾结点
	while(p&&q){
		if(p->exp<q->exp){
			tail->next=p;
			tail=p;
			p=p->next;
		}
		else if(p->exp==q->exp){
			sum=p->coef+q->coef;
			if(sum!=0){
				p->coef=sum;
				tail->next=p;
				tail=p;
				p=p->next;
				temp=q;
				q=q->next;
			}else{
				temp=p;
				p=p->next;
				temp=q;
				q=q->next;
			}
		}else{
			tail->next=q;
			tail=q;
			q=q->next; 
		}
	} 
	if(p){
		tail->next=p;
	}else{
		tail->next=q;
	}
}
void PolyPrint(PolyList L){
	PolyList p;
	p=L->next;
	int flag=0,flag2=0;
	while(p){
		if(p->coef!=0){
			flag=1;
		}
		if(p->coef==0){
		}
		else if(p->coef==1){
			if(p->exp==0){
				flag2=1;
				printf("1");
			}
			else if(p->exp==1){
					flag2=1;
				printf("x");
			}else{
					flag2=1;
				printf("x^%d",p->exp);
			}
		}
		else if(p->coef==-1){
			if(p->exp==0){
					flag2=1;
				printf("-1");
			}else if(p->exp==1){
					flag2=1;
				printf("-x");
			}else{
					flag2=1;
				printf("-x^%d",p->exp);
			}
		}else{
			if(p->exp==0){
					flag2=1;
				printf("%d",p->coef);
			}else if(p->exp==1){
					flag2=1;
				printf("%dx",p->coef);
			}else{
					flag2=1;
				printf("%dx^%d",p->coef,p->exp);
			}
		}
		p=p->next;	
		if(p){
			if(p->coef>0&&flag2){
				printf("+");
			}
		}
	}
	if(flag==0){
		printf("0"); 
	}
}
int main(){
	PolyList HA,HB;
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	HA=PolyCreate(n,0);
	HB=PolyCreate(m,t);
	PolyAdd(HA,HB);
	PolyPrint(HA);
	return 0;
}
