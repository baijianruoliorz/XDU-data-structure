#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 1000//初始分配量 
#define STACKNCREMRNT 100//分配增量 

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
	int row;//行
	int col;//列
} PosType;

typedef struct {
	int ord;//通道块在路径上的序号
	PosType seat;//通道块在迷宫中的位置
	int di;//从此通道块走向下一通道块的"方向"
} ElemType;

typedef struct {
	ElemType *base;//在构造栈前和销毁栈后,base的值为NULL
	ElemType *top;//栈顶指针
	int stacksize;//当前分配的元素空间以元素为单位
} SqStack;
MazeType Maze[100][100];
//构造空栈
Status InitStack(SqStack &S) {
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)exit(OVERFLOW);//储存分配失败
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}
//判断是否栈空
Status StackEmpty(SqStack S) {
	if(S.top==S.base)return TRUE;
	else return FALSE;
}
//清空栈
Status ClearStack(SqStack &S) {
	S.top=S.base;
	printf("\n栈被清空\n");
	return OK;
}
//摧毁栈
Status DestroyStack(SqStack &S) {
	S.top=NULL;
	S.base=NULL;
	free(S.base);
	S.stacksize=0;
	printf("\n栈被毁坏\n");
	return OK;
}
//为栈插入新的栈顶元素k
Status Push(SqStack &S,ElemType k) {
	if(S.top-S.base>S.stacksize) {
		S.base=(ElemType *)realloc(S.base,(S.stacksize+STACKNCREMRNT)*sizeof(ElemType));
		if(!S.base)exit(OVERFLOW);//储存分配失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKNCREMRNT;
	}
	*S.top++=k;
	return OK;
}
//若栈不空，则删除栈顶元素，用e返回其值，返回OK，否则返回ERROR
Status Pop(SqStack &S,ElemType &e) {
	if(S.top==S.base)return ERROR;
	e=*--S.top;
	return OK;
}
//FootPrint函数通过栈留下足迹
void FootPrint(PosType pose,int step) {
	Maze[pose.row-1][pose.col-1]=step;
}
//Pass函数记录判断是否走过当前的通道块, m为行 n为列
Status Pass(PosType pose) {
	if(Maze[pose.row-1][pose.col-1]==0)return TRUE;
	else return FALSE;
}
//MarkPrint函数表示标记走不通的位置方向标记
void MarkPrint(PosType pos) {
	Maze[pos.row-1][pos.col-1]=1;
}
//NextPos函数表示当前位置往某方向走
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
//走迷宫主要方程 
Status MazePath(PosType start,PosType end) {
	SqStack S;
	ElemType e;
	PosType curpos;
	SElemType curstep;
	InitStack(S);
	curstep=1;//设定当前步数,探索第一步
	curpos=start;//设定当前位置为入口位置
	do {
		if(Pass(curpos)) {//当前位置可以通过，也是未曾到过的位置
			FootPrint(curpos,curstep);
			e.ord=curstep;
			e.seat=curpos;
			e.di=1;
			Push(S,e);//加入路径(步数，位置，方向)
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
			curpos=NextPos(curpos,1);//下一位.
			curstep++;//进入下一步
		}//if
		else { //当前位置不能通过
			if(!StackEmpty(S)) {//如果不是空栈
				Pop(S,e);
				while(e.di==4&&!StackEmpty(S)) {
					MarkPrint(e.seat);//留下不能通过的标记
					Pop(S,e);//退后一步
				}//while
				if(e.di<4) {
					e.di++;
					Push(S,e);//换下一个方向搜索
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


