//��С������
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
#define MaxEdgeNum 100
typedef int VertexType;//�������������
typedef int EdgeType;//Ȩ����������
int fat[MaxVertexNum];
typedef struct{
	VertexType Vex[MaxVertexNum];//����� 
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ���,�߱�
	int vexnum,edgenum;//ͼ�Ķ�����,���� 
}MGraph;
typedef struct{
	int vex1,vex2;
	int w;
}kedge;
void create_Graph(MGraph *G,int n,int m){
	int v1,v2,w;
	G->vexnum=n;
	G->edgenum=m;
	//��ʼ���ڽӾ���
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			G->Edge[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v1,&v2,&w);
		G->Edge[v1-1][v2-1]=w;
		G->Edge[v2-1][v1-1]=w;
	}
}
void kruskal(MGraph *G){	/*��³˹�����㷨-�ڽӾ���*/
	int tag[MaxVertexNum];
	kedge Ke[MaxEdgeNum];	/*������Ŷ�ȡ�������б�*/ 
	int i,j;
	int length=0;
	int n=0;	//n��ʾke[]�еı��� 
	for(i=0;i<G->vexnum;i++)	
		tag[i]=i;	/*��ʼ��tag��ǩ����*/
	for(i=0;i<G->vexnum;i++)
		for(j=i+1;j<G->vexnum;j++)
		if(G->Edge[i][j]!=0){		/*����߱�*/
			Ke[n].vex1=i;
			Ke[n].vex2=j;
			Ke[n++].w=G->Edge[i][j];
		}
		kedge temp;
		for(i=0;i<n-1;i++)		/*ð�ݽ��ߵļ��ϰ�Ȩֵ��������*/
			for(j=0;j<n-i-1;j++)
				if(Ke[j].w>Ke[j+1].w){
					temp=Ke[j+1];
					Ke[j+1]=Ke[j];
					Ke[j]=temp;
					}
		for(i=0;i<n;i++){	/*ѡ����̱�*/ 
			int first,second;
			first = tag[Ke[i].vex1];	/*first��ʾ��ǰ�ߵĵ�һ�����ı�Ǽ���*/ 
			second = tag[Ke[i].vex2];	/*second��ʾ��ǰ�ߵĵڶ������ı�Ǽ���*/
			if(first!=second){
				length+=Ke[i].w;		/*������С����������Ȩֵ*/ 
				printf("%d %d %d\n",Ke[i].vex1+1,Ke[i].vex2+1,Ke[i].w); 
				tag[Ke[i].vex2]=first;		/*���ñ����뼯��*/
				for(j=0;j<G->vexnum;j++){			/*��������ͳһ���*/
					if(second==tag[j])
					tag[j]=first;
				}
			}
		}
}
void Print(MGraph *G){
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			printf("%d ",G->Edge[i][j]);
		}
	//	printf("\n");
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	MGraph *G;
	G=(MGraph*)malloc(sizeof(MGraph));
	create_Graph(G,n,m);
//	sort(G);
//	Print(G);
	kruskal(G);
	return 0; 
} 
