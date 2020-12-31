//ħ�����Խ���
//1.ջ��ת�������ڵ�����
//2.���У��洢�������ħ������
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 
//ջ��˳��洢
typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;
//ջ�ĳ�ʼ�� 
void InitStack(SqStack &S){
	S.base=(char*)malloc(MAXSIZE*sizeof(char));
	S.top=S.base;
	S.stacksize=MAXSIZE;
}
//�ж�ջ��
int StackEmpty(SqStack S){
	if(S.top==S.base){
		return 0;
	}else{
		return 1;
	}
} 
int StackEmptyw(SqStack S){
	if(--S.top==S.base){
		return 0;
	}else{
		return 1;
	}
}
//��ջ 
void Push(SqStack &S,char e){
	S.top++;
	*S.top=e;
} 
//��ջ 
char Pop(SqStack &S){
	char c;
	c=*S.top;
	S.top--;
	return c;
}
//��ӡջ������Ԫ��
void Print(SqStack &S){
	while(StackEmpty(S)){
		printf("%c ",*S.top);
		S.top--;
	}
} 
//��ȡջ��Ԫ��
char Getbase(SqStack &S){
	SqStack L=S;
	char c;
	while(StackEmpty(L)){
		c=*L.top;
		L.top--;
	}
	return c;
} 
//���е�˳��洢
typedef struct{
	char *base;
	char front;
	char rear;
}SqQueue; 
//���еĳ�ʼ�� 
void InitQueue(SqQueue &Q){
	Q.base=(char*)malloc(MAXSIZE*sizeof(char));
	Q.front=Q.rear=0;
}
//�ж϶���Ԫ���Ƿ�Ϊ��
int QueueEmpty(SqQueue &Q){
	if(Q.rear==Q.front){
		return 0;
	}else{
		return 1;
	}
} 
//��� 
void EnQueue(SqQueue &Q,char e){
	Q.base[Q.rear]=e;
	Q.rear++;
}
//���� 
char DeQueue(SqQueue &Q){
	char e;
	e=Q.base[Q.front];
	Q.front++;
	return e;
}
//��ӡ����Ԫ��
void PrintQueue(SqQueue &Q){
	while(QueueEmpty(Q)){
		printf("%c",DeQueue(Q));
	}
} 
int main(){
	SqQueue Q;
	InitQueue(Q);
	SqStack L;
	InitStack(L);
	char c;
	int flag=0;
	while((scanf("%c",&c))!=EOF){
		if(!flag){
			if(c=='A'){
				EnQueue(Q,'s');
				EnQueue(Q,'a');
				EnQueue(Q,'e');
			}else if(c=='B'){
				EnQueue(Q,'t');
				EnQueue(Q,'s');
				EnQueue(Q,'a');
				EnQueue(Q,'e');
				EnQueue(Q,'d');
				EnQueue(Q,'s');
				EnQueue(Q,'a');
				EnQueue(Q,'e');
			}else if(c=='('){
				flag=1;
			}else{
				EnQueue(Q,c);
			}
		}else{
			if(c==')'){
				char s=Getbase(L);
				while(StackEmptyw(L)){
					if(s=='A'){
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
					}else if(s=='B'){
						EnQueue(Q,'t');
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
						EnQueue(Q,'d');
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
					}else{
						EnQueue(Q,s);
					}
					char e=Pop(L);
					if(e=='A'){
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
					}else if(e=='B'){
						EnQueue(Q,'t');
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
						EnQueue(Q,'d');
						EnQueue(Q,'s');
						EnQueue(Q,'a');
						EnQueue(Q,'e');
					}else{
						EnQueue(Q,e);
					}
			}
			EnQueue(Q,s); 
			flag=0;
			}else{
				Push(L,c);	
			}
		}
	}
	PrintQueue(Q);
	return 0;
} 
