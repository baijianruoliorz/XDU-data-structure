//求无向图连通子图个数
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
#define MaxEdgeNum 100
#define maxSize 30
typedef int VertexType;//顶点的数据类型
typedef int EdgeType;//权的数据类型
typedef struct{
	VertexType Vex[MaxVertexNum];//顶点表 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵,边表
	int vexnum,edgenum;//图的顶点数
}MGraph;
void create_Graph(MGraph *G,int n,int m){
	int v1,v2;//顶点 
	G->vexnum=n;
	G->edgenum=m;
	//初始化邻接矩阵
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			G->Edge[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		G->Edge[v1-1][v2-1]=1;
		G->Edge[v2-1][v1-1]=1;
	}
//	for(int i=0;i<G->vexnum;i++){
//		G->Edge[i][i]=1;
//	}
} 
void Print(MGraph *G){
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			printf("%d ",G->Edge[i][j]);
		}
		printf("\n");
	}
}
typedef struct{
	int *data;
	int front,rear;
}Queue;
void InitQueue(Queue *Q){
	Q->data=(int *)malloc(maxSize*sizeof(int));
	Q->front=Q->rear=0;
}
int IsEmpty(Queue*Q){
	if(Q->front==Q->rear){
		return 1;
	}else{
		return 0;
	}
}
void EnQueue(Queue *Q,int e){
	Q->data[Q->rear]=e;
	Q->rear++;
}
void DeQueue(Queue *Q,int *e){
	if(Q->rear==Q->front){
		return;
	}
	*e=Q->data[Q->front];
	Q->front++;
}
int visitBFS[maxSize];
int cou[maxSize];//储存连通子图中顶点个数 
void BFS(MGraph *G,int k,int s){
	int i,j;
	Queue Q;
	InitQueue(&Q);
	visitBFS[k]=1;
	EnQueue(&Q,k);
	while(!IsEmpty(&Q)){
		DeQueue(&Q,&i);
		for(j=0;j<G->vexnum;j++){
			if(!visitBFS[j]&&G->Edge[i][j]==1){
				visitBFS[j]=1;
				EnQueue(&Q,j);
				cou[s]++;
			}
		}
	}
}
int BFSTraverse(MGraph *G){//考虑非连通图 
	int count=0,s=0;
	for(int i=0;i<G->vexnum;i++){
		visitBFS[i]=0;
	}
	for(int i=0;i<maxSize;i++){
		cou[i]=0;
	}
	for(int i=0;i<G->vexnum;i++){
		if(!visitBFS[i]){
			BFS(G,i,s);
			s++;
			count++;
		}
	}
	return count;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	MGraph *G;
	G=(MGraph*)malloc(sizeof(MGraph));
	create_Graph(G,n,m);
	int result=BFSTraverse(G);
	printf("%d\n",result);
	int i,j,temp;
	for(i=0;i<result-1;i++){
		for(j=0;j<result-1-i;j++){
			if(cou[j]>cou[j+1]){
				temp=cou[j];
				cou[j]=cou[j+1];
				cou[j+1]=temp;
			}
		}
	}
	for(i=0;i<result;i++){
		printf("%d ",cou[i]+1);
	}
	return 0;
} 
