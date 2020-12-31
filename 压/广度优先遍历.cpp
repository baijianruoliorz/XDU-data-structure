//������ȱ���
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxVertexNum 101//������Ŀ�����ֵ 
#define maxSize 101
typedef int VertexType;//�������������
typedef int EdgeType;//Ȩ����������
typedef struct{
	VertexType Vex[MaxVertexNum];//����� 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ���,�߱�
	int vexnum;//ͼ�Ķ�����
}MGraph;
void create_Graph(MGraph *G,int n){
	int w;//�ߵ�Ȩֵ 
	G->vexnum=n;
	for(int i=0;i<G->vexnum;i++){
		G->Vex[i]=i+1;
	}
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			G->Edge[i][j]=-1;
		}
	}
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			scanf("%d",&w);
			G->Edge[i][j]=w;
		}
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
void BFS(MGraph *G,int k){
	int i,j;
	Queue Q;
	InitQueue(&Q);
	printf("v%d ",G->Vex[k]);
	visitBFS[k]=1;
	EnQueue(&Q,k);
	while(!IsEmpty(&Q)){
		DeQueue(&Q,&i);
		for(j=0;j<G->vexnum;j++){
			if(!visitBFS[j]&&G->Edge[i][j]!=-1){
				visitBFS[j]=1;
				printf("v%d ",G->Vex[j]);
				EnQueue(&Q,j);
			}
		}
	}
}
void BFSTraverse(MGraph *G,int k){//���Ƿ���ͨͼ 
	for(int i=0;i<G->vexnum;i++){
		visitBFS[i]=0;
	}
	BFS(G,k);
	for(int i=0;i<G->vexnum;i++){
		if(!visitBFS[i]){
			BFS(G,i);
		}
	}
}
int main(){
	MGraph *G;
	int n,k;
	scanf("%d%d",&n,&k);
	G=(MGraph*)malloc(sizeof(MGraph));
	create_Graph(G,n);
	BFSTraverse(G,k-1);
	return 0;
}
