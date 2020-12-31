//�ж϶�ջ��ջ�����Ƿ���Ч
#include<stdio.h>
#include<stdlib.h> 
#define stacksize 10 
//˳��ջ 
typedef struct{
	int *base;
	int *top;
}SqStack; 
//ջ�ĳ�ʼ�� 
void InitStack(SqStack &S,int n){
	S.base=(int*)malloc(stacksize*sizeof(int));
	S.top=S.base;
}
//��ջ
void Push(SqStack &S,int i){
	S.top++;
	*S.top=i;
} 
//��ջ
int  Pop(SqStack &S){
	int i=*S.top;
	S.top--;
	return i;
} 
int main(){
	int n,flag=1;
	scanf("%d",&n);
	int s[10];
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	SqStack S;
	InitStack(S,n);
	int count=1;
	for(int i=0;i<n;i++){
		while(count<=s[i]){
			Push(S,count);
			count++;
		}
		if(Pop(S)!=s[i]){
			flag=0;
			break;
		} 
	}
	if(flag){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}  
