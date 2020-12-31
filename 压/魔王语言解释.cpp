//魔王语言解释
//1.栈：转换括号内的文字
//2.队列：存储最后编译的魔王语言
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 
//栈的顺序存储
typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;
//栈的初始化 
void InitStack(SqStack &S){
	S.base=(char*)malloc(MAXSIZE*sizeof(char));
	S.top=S.base;
	S.stacksize=MAXSIZE;
}
//判断栈空
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
//入栈 
void Push(SqStack &S,char e){
	S.top++;
	*S.top=e;
} 
//出栈 
char Pop(SqStack &S){
	char c;
	c=*S.top;
	S.top--;
	return c;
}
//打印栈中所有元素
void Print(SqStack &S){
	while(StackEmpty(S)){
		printf("%c ",*S.top);
		S.top--;
	}
} 
//获取栈底元素
char Getbase(SqStack &S){
	SqStack L=S;
	char c;
	while(StackEmpty(L)){
		c=*L.top;
		L.top--;
	}
	return c;
} 
//队列的顺序存储
typedef struct{
	char *base;
	char front;
	char rear;
}SqQueue; 
//队列的初始化 
void InitQueue(SqQueue &Q){
	Q.base=(char*)malloc(MAXSIZE*sizeof(char));
	Q.front=Q.rear=0;
}
//判断队列元素是否为空
int QueueEmpty(SqQueue &Q){
	if(Q.rear==Q.front){
		return 0;
	}else{
		return 1;
	}
} 
//入队 
void EnQueue(SqQueue &Q,char e){
	Q.base[Q.rear]=e;
	Q.rear++;
}
//出队 
char DeQueue(SqQueue &Q){
	char e;
	e=Q.base[Q.front];
	Q.front++;
	return e;
}
//打印队列元素
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
