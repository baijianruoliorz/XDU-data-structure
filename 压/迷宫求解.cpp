#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 1000//��ʼ������ 
#define STACKNCREMRNT 100//�������� 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
int m,n;
typedef int SElemType;
typedef int Status;

typedef int MazeType;

typedef struct {
	int row;//��
	int col;//��
} PosType;

typedef struct {
	int ord;//ͨ������·���ϵ����
	PosType seat;//ͨ�������Թ��е�λ��
	int di;//�Ӵ�ͨ����������һͨ�����"����"
} ElemType;

typedef struct {
	ElemType *base;//�ڹ���ջǰ������ջ��,base��ֵΪNULL
	ElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�����Ԫ�ؿռ���Ԫ��Ϊ��λ
} SqStack;
MazeType Maze[100][100];
//�����ջ
Status InitStack(SqStack &S) {
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);//�������ʧ��
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}
//�ж��Ƿ�ջ��
Status StackEmpty(SqStack S) {
	if(S.top==S.base)return TRUE;
	else return FALSE;
}
//���ջ
Status ClearStack(SqStack &S) {
	S.top=S.base;
	printf("\nջ�����\n");
	return OK;
}
//�ݻ�ջ
Status DestroyStack(SqStack &S) {
	S.top=NULL;
	S.base=NULL;
	free(S.base);
	S.stacksize=0;
	printf("\nջ���ٻ�\n");
	return OK;
}
//Ϊջ�����µ�ջ��Ԫ��k
Status Push(SqStack &S,ElemType k) {
	if(S.top-S.base>S.stacksize) {
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKNCREMRNT)*sizeof(ElemType));
		if(!S.base)exit(OVERFLOW);//�������ʧ��
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKNCREMRNT;
	}
	*S.top++=k;
	return OK;
}
//��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ������OK�����򷵻�ERROR
Status Pop(SqStack &S,ElemType &e) {
	if(S.top==S.base)return ERROR;
	e=*--S.top;
	return OK;
}
//FootPrint����ͨ��ջ�����㼣
void FootPrint(PosType pose,int step) {
	Maze[pose.row-1][pose.col-1]=step;
}
//Pass������¼�ж��Ƿ��߹���ǰ��ͨ����, mΪ�� nΪ��
Status Pass(PosType pose) {
	if(Maze[pose.row-1][pose.col-1]==0)return TRUE;
	else return FALSE;
}
//MarkPrint������ʾ����߲�ͨ��λ�÷�����
void MarkPrint(PosType pos) {
	Maze[pos.row-1][pos.col-1]=1;
}
//NextPos������ʾ��ǰλ����ĳ������
PosType NextPos(PosType pos,int di) {
	switch(di) {
		case 1:
			if(pos.col<n)
			pos.col++;
			break;
		case 2:
			if(pos.row<m)
			pos.row++;
			break;
		case 3:
			if(pos.col>1)
			pos.col--;
			break;
		case 4:
			if(pos.row>1)
			pos.row--;
			break;
	}
	return pos;
}
//���Թ���Ҫ���� 
Status MazePath(PosType start,PosType end) {
	SqStack S;
	ElemType e;
	PosType curpos;
	SElemType curstep;
	InitStack(S);
	curstep=1;//�趨��ǰ����,̽����һ��
	curpos=start;//�趨��ǰλ��Ϊ���λ��
	do {
		if(Pass(curpos)) {//��ǰλ�ÿ���ͨ����Ҳ��δ��������λ��
			FootPrint(curpos,curstep);
			e.ord=curstep;
			e.seat=curpos;
			e.di=1;
			Push(S,e);//����·��(������λ�ã�����)
			if(curpos.row==end.row&&curpos.col==end.col){
				SqStack S1;
				InitStack(S1);
				while(!StackEmpty(S)){
					ElemType p;
					Pop(S,p);
					Push(S1,p);
				}
				while(!(StackEmpty(S1))){
					ElemType p;
					Pop(S1,p);
					printf("(%d,%d,%d)",p.seat.row,p.seat.col,p.di);
					if(!(StackEmpty(S1)))
					printf(",");
				}
				return TRUE;
			}
			curpos=NextPos(curpos,1);//��һλ.
			curstep++;//������һ��
		}//if
		else { //��ǰλ�ò���ͨ��
			if(!StackEmpty(S)) {//������ǿ�ջ
				Pop(S,e);
				while(e.di==4&&!StackEmpty(S)) {
					MarkPrint(e.seat);//���²���ͨ���ı��
					Pop(S,e);//�˺�һ��
				}//while
				if(e.di<4) {
					e.di++;
					Push(S,e);//����һ����������
					curpos=NextPos(e.seat,e.di);
				}//if
				curpos=NextPos(e.seat,e.di);
			}//if
		}//else
	} while(!StackEmpty(S));
	printf("no"); 
	return FALSE;
}//MazePath

int main() {
	SqStack S;
	scanf("%d%d",&m,&n);
	PosType Start,End;
	scanf("%d%d",&Start.row,&Start.col);
	scanf("%d%d",&End.row,&End.col);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&Maze[i][j]);
		}
	}
	MazePath(Start,End);
}


